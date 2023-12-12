#include "usb_msc_tests.h"
#include "mocks.h"
#include "../src/tinyusb/src/class/msc/msc_device.h"

void* usb_msc_setup(const MunitParameter params[], void* user_data) {
    (void)params;
    (void)user_data;
    return NULL;
}

MunitResult test_usb_msc_unit_ready_cb(const MunitParameter params[], void* user_data) {
    /* These are just to silence compiler warnings about the parameters
     * being unused. */
    (void) params;
    (void) user_data;
    bool res = tud_msc_test_unit_ready_cb(0);
    munit_assert_true(res);
    return MUNIT_OK;
}
