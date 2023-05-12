#include "cli_sys.h"
#include "time.h"
#include "hal/debug_uart.h"

bool cmd_time(void)
{
    debug_line("\r\ntime since boot up : %d ms", time_get_ms());
    return true;  // we are done
}

