#include "steps.h"
#include <stddef.h>
#include "debug_log.h"
#include "swd.h"

static void handle_connect(step_data_typ* cur_step);
static void handle_ap_read(step_data_typ* cur_step);
static void handle_ap_write(step_data_typ* cur_step);

void steps_execute(step_data_typ* cur_step)
{
    if(NULL == cur_step)
    {
        return;
    }
    switch(cur_step->type)
    {
    case STEP_CONNECT:
        handle_connect(cur_step);
        break;

    case STEP_AP_READ:
        handle_ap_read(cur_step);
        break;

    case STEP_AP_WRITE:
        handle_ap_write(cur_step);
        break;

    default:
        debug_line("Target: invalid step!");
        break;
    }
}


static void handle_connect(step_data_typ* cur_step)
{
    if(0 == cur_step->phase)
    {
        // debug_line("resetting error condition!");
        swd_reset_error_condition();
        Result res = swd_connect(cur_step->par_b_0, cur_step->par_i_0, cur_step->par_i_1);
        if(RESULT_OK < res)
        {
            cur_step->intern_0 = res;
            cur_step->phase = 1;
        }
        else if(ERR_QUEUE_FULL_TRY_AGAIN == res)
        {
            // try again
        }
        else
        {
            // some error
            cur_step->result = res;
            cur_step->is_done = true;
        }
    }

    if(1 == cur_step->phase)
    {
        uint32_t data;
        Result res = swd_get_result(cur_step->intern_0, &data);
        if(RESULT_OK == res)
        {
            if(RESULT_OK == data)
            {
                cur_step->result = RESULT_OK;
                cur_step->is_done = true;
            }
            else
            {
                debug_line("target: SWD connect failed ! (%ld)", data);
                cur_step->result = ERR_WRONG_VALUE;
                cur_step->is_done = true;
            }
        }
        else
        {
            if(ERR_NOT_COMPLETED == res)
            {
                // try again
            }
            else
            {
                // some error
                cur_step->result = res;
                cur_step->is_done = true;
            }
        }
    }
}

static void handle_ap_read(step_data_typ* cur_step)
{
    if(0 == cur_step->phase)
    {
        Result res = swd_read_ap(cur_step->par_i_0);
        if(RESULT_OK < res)
        {
            cur_step->intern_0 = res;
            cur_step->phase = 1;
        }
        else if(ERR_QUEUE_FULL_TRY_AGAIN == res)
        {
            // try again
        }
        else
        {
            // some error
            cur_step->result = res;
            cur_step->is_done = true;
        }
    }

    if(1 == cur_step->phase)
    {
        uint32_t data;
        Result res = swd_get_result(cur_step->intern_0, &data);
        if(RESULT_OK == res)
        {
            if(RESULT_OK == data)
            {
                cur_step->result = RESULT_OK;
                cur_step->is_done = true;
            }
            else
            {
                debug_line("target: SWD read from Access Port failed ! (%ld)", data);
                cur_step->result = ERR_WRONG_VALUE;
                cur_step->is_done = true;
            }
        }
        else
        {
            if(ERR_NOT_COMPLETED == res)
            {
                // try again
            }
            else
            {
                // some error
                cur_step->result = res;
                cur_step->is_done = true;
            }
        }
    }
}

static void handle_ap_write(step_data_typ* cur_step)
{
    if(0 == cur_step->phase)
    {
        Result res = swd_write_ap(cur_step->par_i_0, cur_step->par_i_1);
        if(RESULT_OK < res)
        {
            cur_step->intern_0 = res;
            cur_step->phase = 1;
        }
        else if(ERR_QUEUE_FULL_TRY_AGAIN == res)
        {
            // try again
        }
        else
        {
            // some error
            cur_step->result = res;
            cur_step->is_done = true;
        }
    }

    if(1 == cur_step->phase)
    {
        uint32_t data;
        Result res = swd_get_result(cur_step->intern_0, &data);
        if(RESULT_OK == res)
        {
            if(RESULT_OK == data)
            {
                cur_step->result = RESULT_OK;
                cur_step->is_done = true;
            }
            else
            {
                debug_line("target: SWD write to Access Port failed ! (%ld)", data);
                cur_step->result = ERR_WRONG_VALUE;
                cur_step->is_done = true;
            }
        }
        else
        {
            if(ERR_NOT_COMPLETED == res)
            {
                // try again
            }
            else
            {
                // some error
                cur_step->result = res;
                cur_step->is_done = true;
            }
        }
    }
}

