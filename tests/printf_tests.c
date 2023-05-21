#include "printf_tests.h"
#include "mocks.h"
#include "../src/lib/printf.h"

void* printf_setup(const MunitParameter params[], void* user_data) {
    (void)params;
    (void)user_data;
    init_printf(NULL, debug_putc);
    recv_read_pos = 0;
    recv_write_pos = 0;
    send_read_pos = 0;
    send_write_pos = 0;
    memset(recv_buf, 0, RECEIVE_BUFFER_SIZE);
    memset(send_buf, 0, SEND_BUFFER_SIZE);
    echo_enabled = false;
    return NULL;
}

MunitResult test_printf_init(const MunitParameter params[], void* user_data) {
    /* These are just to silence compiler warnings about the parameters
     * being unused. */
    (void) params;
    (void) user_data;
    return MUNIT_OK;
}
