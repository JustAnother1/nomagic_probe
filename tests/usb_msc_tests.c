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

MunitResult test_usb_msc_read10_cb(const MunitParameter params[], void* user_data) {
    /* These are just to silence compiler warnings about the parameters
     * being unused. */
    (void) params;
    (void) user_data;

    {
    uint8_t buf[9] = {0};
    uint8_t res_buf[8] = {0};
    // int32_t tud_msc_read10_cb(uint8_t lun, uint32_t lba, uint32_t offset, void* buffer, uint32_t bufsize);
    int32_t res = tud_msc_read10_cb(0, 0, 0, buf, 8);
    munit_assert_int32(8, ==, res);
    munit_assert_memory_equal(8, res_buf, buf);
    }

    {
    uint8_t buf[9] = {0};
    uint8_t res_buf[8] = { 0x00, 0xff, 0xff, 0xff, 0x01, 0xff, 0xff, 0xff };
    // int32_t tud_msc_read10_cb(uint8_t lun, uint32_t lba, uint32_t offset, void* buffer, uint32_t bufsize);
    int32_t res = tud_msc_read10_cb(0, 0, 446, buf, 8);
    munit_assert_int32(8, ==, res);
    munit_assert_memory_equal(8, res_buf, buf);
    }

    {
        // MBR
    uint8_t buf[520] = {0};
    uint8_t res_buf[512] = {
            0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, // 0
            0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, // 1
            0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, // 2
            0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, // 3
            0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, // 4
            0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, // 5
            0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, // 6
            0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, // 7
            0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, // 8
            0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, // 9
            0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, // a
            0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, // b
            0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, // c
            0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, // d
            0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, // e
            0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, // f
            0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, // 10
            0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, // 11
            0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, // 12
            0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, // 13
            0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, // 14
            0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, // 15
            0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, // 16
            0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, // 17
            0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, // 18
            0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, // 19
            0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, // 1a
            0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0x00, 0xff, // 1b
            0xff, 0xff, 0x01, 0xff, 0xff, 0xff, 0x01, 0x00,   0x00, 0x00, 0xff, 0x07, 0x00, 0x00, 0x00, 0x00, // 1c
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 1d
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 1e
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x55, 0xaa  // 1f
    };
    // int32_t tud_msc_read10_cb(uint8_t lun, uint32_t lba, uint32_t offset, void* buffer, uint32_t bufsize);
    int32_t res = tud_msc_read10_cb(0, 0, 0, buf, 512);
    munit_assert_int32(512, ==, res);
    munit_assert_memory_equal(512, res_buf, buf);
    }

    {
        // boot sector
    uint8_t buf[520] = {0};
    uint8_t res_buf[512] = {
            0xeb, 0x3c, 0x90, 0x4d, 0x53, 0x44, 0x4f, 0x53,  0x35, 0x2e, 0x30, 0x00, 0x02,    8,    1,    0,  // 0
               1, 0x80, 0x00, 0xff, 0x00, 0xf8, 0x10, 0x00,  0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,  // 1
            0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x29, 0x15,  0x08, 0x11, 0x47,  'n',  'o',  'm',  'a',  'g',  // 2
             'i',  'c',  ' ',  'p',  'r',  'o', 0x46, 0x41,  0x54, 0x31, 0x32, 0x20, 0x20, 0x20,    0,    0,  // 3
               0,    0,    0,    0,    0,    0,    0,    0,     0,    0,    0,    0,    0,    0,    0,    0,  // 4
               0,    0,    0,    0,    0,    0,    0,    0,     0,    0,    0,    0,    0,    0,    0,    0,  // 5
               0,    0,    0,    0,    0,    0,    0,    0,     0,    0,    0,    0,    0,    0,    0,    0,  // 6
               0,    0,    0,    0,    0,    0,    0,    0,     0,    0,    0,    0,    0,    0,    0,    0,  // 7
               0,    0,    0,    0,    0,    0,    0,    0,     0,    0,    0,    0,    0,    0,    0,    0,  // 8
               0,    0,    0,    0,    0,    0,    0,    0,     0,    0,    0,    0,    0,    0,    0,    0,  // 9
               0,    0,    0,    0,    0,    0,    0,    0,     0,    0,    0,    0,    0,    0,    0,    0,  // a
               0,    0,    0,    0,    0,    0,    0,    0,     0,    0,    0,    0,    0,    0,    0,    0,  // b
               0,    0,    0,    0,    0,    0,    0,    0,     0,    0,    0,    0,    0,    0,    0,    0,  // c
               0,    0,    0,    0,    0,    0,    0,    0,     0,    0,    0,    0,    0,    0,    0,    0,  // d
               0,    0,    0,    0,    0,    0,    0,    0,     0,    0,    0,    0,    0,    0,    0,    0,  // e
               0,    0,    0,    0,    0,    0,    0,    0,     0,    0,    0,    0,    0,    0,    0,    0,  // f
               0,    0,    0,    0,    0,    0,    0,    0,     0,    0,    0,    0,    0,    0,    0,    0,  // 10
               0,    0,    0,    0,    0,    0,    0,    0,     0,    0,    0,    0,    0,    0,    0,    0,  // 11
               0,    0,    0,    0,    0,    0,    0,    0,     0,    0,    0,    0,    0,    0,    0,    0,  // 12
               0,    0,    0,    0,    0,    0,    0,    0,     0,    0,    0,    0,    0,    0,    0,    0,  // 13
               0,    0,    0,    0,    0,    0,    0,    0,     0,    0,    0,    0,    0,    0,    0,    0,  // 14
               0,    0,    0,    0,    0,    0,    0,    0,     0,    0,    0,    0,    0,    0,    0,    0,  // 15
               0,    0,    0,    0,    0,    0,    0,    0,     0,    0,    0,    0,    0,    0,    0,    0,  // 16
               0,    0,    0,    0,    0,    0,    0,    0,     0,    0,    0,    0,    0,    0,    0,    0,  // 17
               0,    0,    0,    0,    0,    0,    0,    0,     0,    0,    0,    0,    0,    0,    0,    0,  // 18
               0,    0,    0,    0,    0,    0,    0,    0,     0,    0,    0,    0,    0,    0,    0,    0,  // 19
               0,    0,    0,    0,    0,    0,    0,    0,     0,    0,    0,    0,    0,    0,    0,    0,  // 1a
               0,    0,    0,    0,    0,    0,    0,    0,     0,    0,    0,    0,    0,    0,    0,    0,  // 1b
               0,    0,    0,    0,    0,    0,    0,    0,     0,    0,    0,    0,    0,    0,    0,    0,  // 1c
               0,    0,    0,    0,    0,    0,    0,    0,     0,    0,    0,    0,    0,    0,    0,    0,  // 1d
               0,    0,    0,    0,    0,    0,    0,    0,     0,    0,    0,    0,    0,    0,    0,    0,  // 1e
               0,    0,    0,    0,    0,    0,    0,    0,     0,    0,    0,    0,    0,    0, 0x55, 0xaa, // 1f
    };
    // int32_t tud_msc_read10_cb(uint8_t lun, uint32_t lba, uint32_t offset, void* buffer, uint32_t bufsize);
    int32_t res = tud_msc_read10_cb(0, 1, 0, buf, 512);
    munit_assert_int32(512, ==, res);
    munit_assert_memory_equal(512, res_buf, buf);
    }
    return MUNIT_OK;
}
