#ifndef TESTS_USB_MSC_TESTS_H_
#define TESTS_USB_MSC_TESTS_H_

#include "munit.h"
#include <stdint.h>
#include <stdbool.h>

void* usb_msc_setup(const MunitParameter params[], void* user_data);
MunitResult test_usb_msc_unit_ready_cb(const MunitParameter params[], void* user_data);
MunitResult test_usb_msc_read10_cb(const MunitParameter params[], void* user_data);

#endif /* TESTS_USB_MSC_TESTS_H_ */
