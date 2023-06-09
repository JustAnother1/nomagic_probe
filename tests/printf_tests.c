#include "printf_tests.h"
#include "mocks.h"
#include "../src/lib/printf.h"

#define STRING_BUFFER_LENGTH  100

char str_buffer[100];
unsigned int buf_idx;
MunitResult res;

static void test_putc(void* p, char c)
{
    (void) p; // not used
    str_buffer[buf_idx] = c;
    buf_idx++;
    if(STRING_BUFFER_LENGTH == buf_idx)
    {
        buf_idx = 0;
        res = MUNIT_FAIL;
    }
}

void* printf_setup(const MunitParameter params[], void* user_data) {
    (void)params;
    (void)user_data;
    buf_idx = 0;
    res = MUNIT_OK;
    init_printf(NULL, test_putc);
    return NULL;
}

MunitResult test_printf_init(const MunitParameter params[], void* user_data) {
    /* These are just to silence compiler warnings about the parameters
     * being unused. */
    (void) params;
    (void) user_data;
    return res;
}

MunitResult test_printf_printf_str(const MunitParameter params[], void* user_data) {
    /* These are just to silence compiler warnings about the parameters
     * being unused. */
    (void) params;
    (void) user_data;
    printf("Hello World !\r\n");
    munit_assert_uint32(15, ==, buf_idx);
    str_buffer[buf_idx] = 0;
    munit_assert_string_equal("Hello World !\r\n", str_buffer);
    // munit_assert_memory_equal(78, res_buf, send_buf);
    return res;
}

MunitResult test_printf_printf_int(const MunitParameter params[], void* user_data) {
    /* These are just to silence compiler warnings about the parameters
     * being unused. */
    (void) params;
    (void) user_data;
    uint32_t val = 5;
    printf("Value = %d", val);
    munit_assert_uint32(9, ==, buf_idx);
    str_buffer[buf_idx] = 0;
    munit_assert_string_equal("Value = 5", str_buffer);
    // munit_assert_memory_equal(78, res_buf, send_buf);
    return res;
}

MunitResult test_printf_printf_digits(const MunitParameter params[], void* user_data) {
    /* These are just to silence compiler warnings about the parameters
     * being unused. */
    (void) params;
    (void) user_data;
    const char* expected = "Value = 54321";
    uint32_t val = 54321;
    printf("Value = %d", val);
    munit_assert_uint32(strlen(expected), ==, buf_idx);
    str_buffer[buf_idx] = 0;
    munit_assert_string_equal(expected, str_buffer);
    // munit_assert_memory_equal(78, res_buf, send_buf);
    return res;
}
