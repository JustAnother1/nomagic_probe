#include "cli_sys.h"
#include "time.h"

bool cmd_time(void)
{
    uint8_t buf[30];
    uint32_t len = snprintf(buf, 30, "\r\ntime since boot up : %d ms", time_get_ms());
    SERIAL_SEND_STRING(buf);
    return true;  // we are done
}

