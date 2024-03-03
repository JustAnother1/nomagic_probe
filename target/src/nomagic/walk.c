
#include "walk.h"
#include "steps.h"
#include "arm/cortex-m.h"
#include <stddef.h>
#include "debug_log.h"
#include "time.h"

#define MAX_SAFE_COUNT    0xfffffff0  // comparing against < 0xffffffff is always true -> we want to avoid 0xffffffff as end time of timeout
#define WALK_TIMEOUT_TIME_MS  300


static step_data_typ cur_step;

static uint32_t val_DHCSR;
static uint32_t val_DEMCR;

static uint32_t timeout_time;
static bool wait_for_wrap_around;

static void handle_connect(walk_data_typ* data);
static void handle_scan(walk_data_typ* data);

typedef void (*walk_handler)(walk_data_typ* data);

static const walk_handler walks_look_up[NUM_WALKS_DEFINED] = {
        handle_connect,
        handle_scan,
};

void walk_init(void)
{
    cur_step.is_done = true;
}

void walk_execute(walk_data_typ* data)
{
    if(NULL == data)
    {
        return;
    }
    if(false == cur_step.is_done)
    {
        // we are not done -> do it now
        steps_execute(&cur_step);
    }
    if(false == cur_step.is_done)
    {
        uint32_t cur_time = time_get_ms();
        if(true == wait_for_wrap_around)
        {
            if(10 > cur_time)
            {
                // wrap around happened
                wait_for_wrap_around = false;
            }
            // else continue waiting
        }
        else
        {
            if(cur_time > timeout_time)
            {
                // Timeout !!!
                debug_line("ERROR: Target walk(%d): timeout in running step %ld !", data->type, data->phase );
                // TODO can we do something better than to just skip this command?
                debug_line("walk(pi0:0x%08lX, pi1:0x%08lX, p:%ld, r:%ld, i:%ld, t:%d, d:%d, pb:%d)",
                           data->par_i_0, data->par_i_1, data->phase, data->result, data->intern_0, data->type, data->is_done, data->par_b_0);
                debug_line("step(pi0:0x%08lX, pi1:0x%08lX, p:%ld, r:%ld, i:%ld, t:%d, d:%d, pb:%d)",
                           cur_step.par_i_0, cur_step.par_i_1, cur_step.phase, cur_step.result, cur_step.intern_0, cur_step.type, cur_step.is_done, cur_step.par_b_0);

                // do not try anymore
                data->is_done = true;
                cur_step.is_done = true;
            }
            // else not a timeout, yet.
        }
    }
    else
    {
        if(false == data->is_done)
        {
            // take the next step on this walk
            uint32_t start_time = time_get_ms();

            (*walks_look_up[data->type])(data);
            timeout_time = start_time + WALK_TIMEOUT_TIME_MS;
            if(timeout_time > MAX_SAFE_COUNT)
            {
                // an end time of 0xffffffff would not work as all values are always < 0xffffffff
                uint32_t remainder = 100 - (MAX_SAFE_COUNT - start_time);
                timeout_time = 2 + remainder;
                wait_for_wrap_around = true;
            }
            else if(timeout_time < start_time)
            {
                // wrap around
                wait_for_wrap_around = true;
            }
            else
            {
                wait_for_wrap_around = false;
            }
        }
        else
        {
            // we are done !
        }
    }
}

static void handle_connect(walk_data_typ* data)
{
    if(0 == data->phase)
    {
        // swd_connect()
        cur_step.type = STEP_CONNECT;
        cur_step.par_b_0 = data->par_b_0;
        cur_step.par_i_0 = data->par_i_0;
        cur_step.par_i_1 = data->par_i_1;
        cur_step.phase = 0;
        cur_step.result = RESULT_OK;
        cur_step.is_done = false;
        data->phase++;
    }
    else if(1 == data->phase)
    {
        // write DEBUGEN in DHCSR
        if(RESULT_OK == cur_step.result)
        {
            // cortex-M init
            val_DHCSR = 1;  // C_DEBUGEN = 1; C_HALT = b10;
            cur_step.type = STEP_AP_WRITE;
            cur_step.par_i_0 = DHCSR;
            cur_step.par_i_1 = DBGKEY | (0xffff & val_DHCSR);
            cur_step.phase = 0;
            cur_step.result = RESULT_OK;
            cur_step.is_done = false;
            data->phase++;
        }
        else
        {
            // step 0 failed
            data->result = cur_step.result;
            data->is_done = true;
        }
    }
    else if(2 == data->phase)
    {
        // init DEMCR
        if(RESULT_OK == cur_step.result)
        {
            // TODO DEMCR.DWTENA bit to 1 to enable Watch points
            val_DEMCR = (1 << 24) | (1 << 10) | 1;
            cur_step.type = STEP_AP_WRITE;
            cur_step.par_i_0 = DEMCR;
            cur_step.par_i_1 = val_DEMCR;
            cur_step.phase = 0;
            cur_step.result = RESULT_OK;
            cur_step.is_done = false;
            data->phase++;
        }
        else
        {
            // step 1 failed
            data->result = cur_step.result;
            data->is_done = true;
        }
    }
    else if(3 == data->phase)
    {
        if(RESULT_OK == cur_step.result)
        {
            val_DHCSR = 0xf;
            cur_step.type = STEP_AP_WRITE;
            cur_step.par_i_0 = DHCSR;
            cur_step.par_i_1 = DBGKEY | (0xffff & val_DHCSR);
            cur_step.phase = 0;
            cur_step.result = RESULT_OK;
            cur_step.is_done = false;
            data->phase++;
        }
        else
        {
            // step 2 failed
            data->result = cur_step.result;
            data->is_done = true;
        }
    }
    else
    {
        data->result = cur_step.result;
        data->is_done = true;
    }
}

static void handle_scan(walk_data_typ* data)
{
    {
        data->result = cur_step.result;
        data->is_done = true;
    }
}



/*
static uint32_t reg_data;  // TODO sort these out
static uint32_t first_ap;


Result scan_handler(command_typ* cmd, bool first_call)
{
    static Result phase = 0;
    (void) cmd;
    if(true == first_call)
    {
        cycle_counter = 0;
        first_ap = 0xffffffff;
        phase = 1;
    }

    if(1 == phase)
    {
        debug_line("testing AP %ld", cycle_counter);
        state.mem_ap.ap_sel = cycle_counter;
        phase = 2;
    }

// Phase 2-5 read IDR Register

    if((2 == phase ) || (3 == phase))
    {
        Result res;
        if(2 == phase)
        {
            res = read_ap_register(AP_BANK_IDR, AP_REGISTER_IDR, &read_data, true);
            phase = 3;
        }
        else
        {
            res = read_ap_register(AP_BANK_IDR, AP_REGISTER_IDR, &read_data, false);
        }
        if(RESULT_OK == res)
        {
            phase = 4;
        }
        else
        {
            return res;
        }
    }

    if((4 == phase ) || (5 == phase))
    {
        if(0 != read_data)
        {
            Result tres;
            if(4 == phase)
            {
                debug_line("AP %ld: 0x%08lx", cycle_counter, read_data);
                tres = check_AP(read_data, true);
                phase = 5;
            }
            else
            {
                tres = check_AP(read_data, false);
            }
            if(RESULT_OK == tres)
            {
                // done with this AP
                cycle_counter++;
                if(256 > cycle_counter)
                {
                    phase = 1;
                    state.mem_ap.ap_sel = cycle_counter;
                    return ERR_NOT_COMPLETED;
                }
                else
                {
                    // scan complete
                    debug_line("Done!");
                    return RESULT_OK;
                }
            }
            else
            {
                return tres;
            }
        }
        else
        {
            // reached end of APs
            debug_line("AP %ld: IDR 0x%08lx", cycle_counter, read_data);
            state.mem_ap.ap_sel = cycle_counter - 1;  // use the last good AP
            debug_line("Done!");
           return RESULT_OK;
        }
    }

    return (Result)phase;
}

static Result check_AP(uint32_t idr, bool first_call)
{
    static Result phase = 0;
    uint32_t class = (idr & (0xf << 13))>> 13;
    state.mem_ap.ap_sel = cycle_counter;
    if(8 == class)
    {
        // Memory Access Port (MEM-AP)
        if(true == first_call)
        {
            state.mem_ap.version = AP_VERSION_APv1;
            debug_line("APv1:");
            debug_line("AP: IDR: Revision: %ld", (idr & (0xful<<28))>>28 );
            debug_line("AP: IDR: Jep 106 : %ld x 0x7f + 0x%02lx", (idr & (0xf << 24))>>24, (idr & (0x7f<<17))>>17 );
            debug_line("AP: IDR: class :   %ld", class );
            debug_line("AP: IDR: variant:  %ld", (idr & (0xf<<4))>>4 );
            debug_line("AP: IDR: type:     %ld", (idr & 0xf) );
            phase = 1;
            return ERR_NOT_COMPLETED;
        }

        if((1 == phase) || (2 == phase))
        {
            Result res;
            if(1 == phase)
            {
                res = read_ap_register(AP_BANK_CSW, AP_REGISTER_CSW, &reg_data, true);
                phase = 2;
            }
            else
            {
                res = read_ap_register(AP_BANK_CSW, AP_REGISTER_CSW, &reg_data, false);
            }
            if(RESULT_OK == res)
            {
                debug_line("AP: CSW  : 0x%08lx", reg_data);
                state.mem_ap.reg_CSW = reg_data;

                // change CSW !!!
                reg_data = reg_data & ~0x3ful; // no auto address increment
                reg_data = reg_data | 0x80000002; // DbgSwEnable + data size = 32bit
                phase = 3;
                return ERR_NOT_COMPLETED;
            }
            else
            {
                return res;
            }
        }

        if((3 == phase) || (4 == phase))
        {
            Result res;
            if(3 == phase)
            {
                res = write_ap_register(AP_BANK_CSW, AP_REGISTER_CSW, reg_data, true);
                phase = 4;
            }
            else
            {
                res = write_ap_register(AP_BANK_CSW, AP_REGISTER_CSW, reg_data, false);
            }
            if(RESULT_OK == res)
            {
                phase = 5;
                return ERR_NOT_COMPLETED;
            }
            else
            {
                return res;
            }
        }

        if((5 == phase) || (6 == phase))
        {
            Result res;
            if(5 == phase)
            {
                res = read_ap_register(AP_BANK_BASE, AP_REGISTER_BASE, &reg_data, true);
                phase = 6;
            }
            else
            {
                res = read_ap_register(AP_BANK_BASE, AP_REGISTER_BASE, &reg_data, false);
            }
            if(RESULT_OK == res)
            {
                debug_line("AP: BASE : 0x%08lx", reg_data);
                state.mem_ap.reg_BASE = reg_data;
                phase = 7;
            }
            else
            {
                return res;
            }
        }

        if((7 == phase) || (8 == phase))
        {
            Result res;
            if(7 == phase)
            {
                res = read_ap_register(AP_BANK_CFG, AP_REGISTER_CFG, &reg_data, true);
                phase = 8;
            }
            else
            {
                res = read_ap_register(AP_BANK_CFG, AP_REGISTER_CFG, &reg_data, false);
            }
            if(RESULT_OK == res)
            {
                debug_line("AP: CFG  : 0x%08lx", reg_data);
                if(0 == (reg_data & 0x02))
                {
                    state.mem_ap.long_address_support = false;
                }
                else
                {
                    state.mem_ap.long_address_support = true;
                }
                if(0 == (reg_data & 0x04))
                {
                    state.mem_ap.large_data_support = false;
                }
                else
                {
                    state.mem_ap.large_data_support = true;
                }
                phase = 9;
            }
            else
            {
                return res;
            }
        }

        if((9 == phase) || (10 == phase))
        {
            Result res;
            if(9 == phase)
            {
                res = read_ap_register(AP_BANK_CFG1, AP_REGISTER_CFG1, &reg_data, true);
                phase = 10;
            }
            else
            {
                res = read_ap_register(AP_BANK_CFG1, AP_REGISTER_CFG1, &reg_data, false);
            }
            if(RESULT_OK == res)
            {
                debug_line("AP: CFG1 : 0x%08lx", reg_data);
                phase = 11;
            }
            else
            {
                return res;
            }
        }

        if(11 == phase)
        {
            // TODO read ROM Table
            // ROM Table:
            // ==========
            // each 32bit Entry is defined as:
            // bit 31-12: Address Offset _signed_ base address offset relative to the ROM table base address
            // bit 11-2: reserved
            // bit 1: Format: 0= 8 bit format(not used); 1= 32bit format.
            // bit 0: Entry present: 0= ignore this entry; 1= valid entry
            // entry 0x00000000 marks end of table!

            // actual table: (rp2040 @ 0xe00ff003) = BASE & 0xfffffffc; // lowest two bits are 0.
            // offset, name,   value,                    description
            // ------  ----    -----                     -----------
            // 0,      SCS,    0xfff0f003,               points to the SCS @ 0xe000e000.
            // 4,      ROMDWT, 0xfff02002 or 0xfff02003, points to DWT @ 0xe0001000 bit0 is 1 if DWT is fitted.
            // 8,      ROMBPU, 0xfff03002 or 0xfff03003, points to the BPU @ 0xe0002000 bit 0 is set if BPU is fitted.
            // 0xc,    End,    0x00000000,               End of table marker.


             // i = 0
             // do{
             //  read memory @ Base & 0xfffffffc + 4*i
             //  i = 0 -> SCS
             //  i = 1 -> ROMDWT
             //  i = 2 -> ROMBPU
             // } while(i < 1024 and read != 0)

            // TODO read ROM Table from address pointed to by BASE Register (Architecture P 318)
            // TODO check number of Break Points
            // TODO check number of Watch points


            if(cycle_counter < first_ap)
            {
                first_ap = cycle_counter;
            }
            return RESULT_OK; // done with this AP
        }

        // phase has invalid value
        debug_line("check ap: invalid phase!");
        return (Result)ERR_WRONG_STATE;
    }
    else if(9 == class)
    {
        // Memory Access Port (MEM-AP)
        state.mem_ap.version = AP_VERSION_APv2;
        debug_line("APv2:");
        debug_line("AP: IDR: Revision: %ld", (idr & (0xful<<28))>>28 );
        debug_line("AP: IDR: Jep 106 : %ld x 0x7f + 0x%02lx", (idr & (0xf << 24))>>24, (idr & (0x7f<<17))>>17 );
        debug_line("AP: IDR: class :   %ld", class );
        debug_line("AP: IDR: variant:  %ld", (idr & (0xf<<4))>>4 );
        debug_line("AP: IDR: type:     %ld", (idr & 0xf) );
        // TODO

        if(cycle_counter < first_ap)
        {
            first_ap = cycle_counter;
        }

        return RESULT_OK; // done with this AP
    }
    else
    {
        debug_line("AP unknown class %ld !", class);
        return RESULT_OK; // done with this AP
    }
}
*/
