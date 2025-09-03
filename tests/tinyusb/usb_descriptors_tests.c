/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License version 2
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, see <http://www.gnu.org/licenses/>
 *
 */

#include "tinyusb/usb_descriptors.h"
#include "unity.h"

void setUp(void)
{
    update_descriptors();
}

void tearDown(void)
{

}

void test_tud_descriptor_device_cb(void)
{
    uint8_t descr[18] = {
            18, // bLength
            1, // bDescriptorType
            0, 2, // bcdUSB
            239, // bDeviceClass
            2, // bDeviceSubClass
            1, // bDeviceProtocol
            64, // bMaxPacketSize0
            0x8a, 0x2e, // idVendor
            0x01, 0x40, // idProduct
            0, 1, // bcdDevice
            1, // iManufacturer
            2, // iProduct
            3, // iSerialNumber
            1 // bNumConfigurations
    };
    const uint8_t* res = tud_descriptor_device_cb();
    TEST_ASSERT_NOT_NULL(res);

    TEST_ASSERT_EQUAL_MEMORY(descr, res, 18);
}

void test_tud_descriptor_configuration_cb(void)
{
    const uint8_t* res = tud_descriptor_configuration_cb(0);
    TEST_ASSERT_NOT_NULL(res);
    // config_desc
    TEST_ASSERT_EQUAL_INT16(9,    res[0]);
    TEST_ASSERT_EQUAL_INT16(2,    res[1]);  // TUSB_DESC_CONFIGURATION
    // TEST_ASSERT_EQUAL_INT16(9,    res[2]);  // total length (low)
    // TEST_ASSERT_EQUAL_INT16(0,    res[3]);  // total length (high)
    TEST_ASSERT_EQUAL_INT16(1,    res[4]);  // interface count
    TEST_ASSERT_EQUAL_INT16(1,    res[5]);  // configuration number
    TEST_ASSERT_EQUAL_INT16(0,    res[6]);  // string index
    TEST_ASSERT_EQUAL_INT16(0xa0, res[7]);  // attribute remote wakeup
    TEST_ASSERT_EQUAL_INT16(0x7d, res[8]);  // max power 250mA
    // CDC
    // Interface Associate
    TEST_ASSERT_EQUAL_INT16(8,    res[ 9]);
    TEST_ASSERT_EQUAL_INT16(11,   res[10]); // 0x0b == TUSB_DESC_INTERFACE_ASSOCIATION
    // TEST_ASSERT_EQUAL_INT16(1,    res[11]); // interface number
    TEST_ASSERT_EQUAL_INT16(2,    res[12]); // 2
    TEST_ASSERT_EQUAL_INT16(2,    res[13]); // TUSB_CLASS_CDC
    TEST_ASSERT_EQUAL_INT16(2,    res[14]); // CDC_COMM_SUBCLASS_ABSTRACT_CONTROL_MODEL
    TEST_ASSERT_EQUAL_INT16(0,    res[15]); // CDC_COMM_PROTOCOL_NONE
    TEST_ASSERT_EQUAL_INT16(0,    res[16]); // 0
    // CDC Control Interface
    TEST_ASSERT_EQUAL_INT16(9,    res[17]);
    TEST_ASSERT_EQUAL_INT16(4,    res[18]); // TUSB_DESC_INTERFACE
    // TEST_ASSERT_EQUAL_INT16(1,    res[19]); // interface number
    TEST_ASSERT_EQUAL_INT16(0,    res[20]); // 0
    TEST_ASSERT_EQUAL_INT16(1,    res[21]); // 1
    TEST_ASSERT_EQUAL_INT16(2,    res[22]); // TUSB_CLASS_CDC
    TEST_ASSERT_EQUAL_INT16(2,    res[23]); // CDC_COMM_SUBCLASS_ABSTRACT_CONTROL_MODEL
    TEST_ASSERT_EQUAL_INT16(0,    res[24]); // CDC_COMM_PROTOCOL_NONE
    TEST_ASSERT_EQUAL_INT16(4,    res[25]); // string index
    // CDC Header
    TEST_ASSERT_EQUAL_INT16(5,    res[26]);
    TEST_ASSERT_EQUAL_INT16(0x24, res[27]); // TUSB_DESC_CS_INTERFACE
    TEST_ASSERT_EQUAL_INT16(0,    res[28]); // CDC_FUNC_DESC_HEADER
    TEST_ASSERT_EQUAL_INT16(0x20, res[29]); // 0x0120
    TEST_ASSERT_EQUAL_INT16(1,    res[30]);
    // CDC Call
    TEST_ASSERT_EQUAL_INT16(5,    res[31]);
    TEST_ASSERT_EQUAL_INT16(0x24, res[32]); // TUSB_DESC_CS_INTERFACE
    TEST_ASSERT_EQUAL_INT16(1,    res[33]); // CDC_FUNC_DESC_CALL_MANAGEMENT
    TEST_ASSERT_EQUAL_INT16(0,    res[34]); // 0
    // TEST_ASSERT_EQUAL_INT16(2,    res[35]); // interface number + 1
    // CDC ACM: support line request + send break
    TEST_ASSERT_EQUAL_INT16(4,    res[36]);
    TEST_ASSERT_EQUAL_INT16(0x24, res[37]); // TUSB_DESC_CS_INTERFACE
    TEST_ASSERT_EQUAL_INT16(2,    res[38]); // CDC_FUNC_DESC_ABSTRACT_CONTROL_MANAGEMENT
    TEST_ASSERT_EQUAL_INT16(6,    res[39]); // 6
    // CDC Union
    TEST_ASSERT_EQUAL_INT16(5,    res[40]);
    TEST_ASSERT_EQUAL_INT16(0x24, res[41]); // TUSB_DESC_CS_INTERFACE
    TEST_ASSERT_EQUAL_INT16(6,    res[42]); // CDC_FUNC_DESC_UNION
    // TEST_ASSERT_EQUAL_INT16(1,    res[43]); // interface number
    // TEST_ASSERT_EQUAL_INT16(2,    res[44]); // interface number + 1
    // Endpoint Notification
    TEST_ASSERT_EQUAL_INT16(7,    res[45]);
    TEST_ASSERT_EQUAL_INT16(5,    res[46]); // TUSB_DESC_ENDPOINT
    TEST_ASSERT_EQUAL_INT16(0x81, res[47]); // notification endpoint number
    TEST_ASSERT_EQUAL_INT16(3,    res[48]); // TUSB_XFER_INTERRUPT
    TEST_ASSERT_EQUAL_INT16(8,    res[49]); // endpoint size low
    TEST_ASSERT_EQUAL_INT16(0,    res[50]); // endpoint size high
    TEST_ASSERT_EQUAL_INT16(16,    res[51]); // 16
    // CDC Data Interface
    TEST_ASSERT_EQUAL_INT16(9,    res[52]);
    TEST_ASSERT_EQUAL_INT16(4,    res[53]); // TUSB_DESC_INTERFACE
    // TEST_ASSERT_EQUAL_INT16(2,    res[54]); // interface number + 1
    TEST_ASSERT_EQUAL_INT16(0,    res[55]); // 0
    TEST_ASSERT_EQUAL_INT16(2,    res[56]); // 2
    TEST_ASSERT_EQUAL_INT16(10,   res[57]); // TUSB_CLASS_CDC_DATA
    TEST_ASSERT_EQUAL_INT16(0,    res[58]); // 0
    TEST_ASSERT_EQUAL_INT16(0,    res[59]); // 0
    TEST_ASSERT_EQUAL_INT16(0,    res[60]); // 0
    // Endpoint Out
    TEST_ASSERT_EQUAL_INT16(7,    res[61]);
    TEST_ASSERT_EQUAL_INT16(5,    res[62]); // TUSB_DESC_ENDPOINT
    // TEST_ASSERT_EQUAL_INT16(2,    res[63]); // out end point number
    TEST_ASSERT_EQUAL_INT16(2,    res[64]); // TUSB_XFER_BULK
    TEST_ASSERT_EQUAL_INT16(64,   res[65]); // end point size low
    TEST_ASSERT_EQUAL_INT16(0,    res[66]); // end point size high
    TEST_ASSERT_EQUAL_INT16(0,    res[67]); // 0
    // Endpoint In
    TEST_ASSERT_EQUAL_INT16(7,    res[68]);
    TEST_ASSERT_EQUAL_INT16(5,    res[69]); // TUSB_DESC_ENDPOINT
    TEST_ASSERT_EQUAL_INT16(0x82, res[70]); // IN endpoint number
    TEST_ASSERT_EQUAL_INT16(2,    res[71]); // TUSB_XFER_BULK
    TEST_ASSERT_EQUAL_INT16(64,   res[72]); // end point size low
    TEST_ASSERT_EQUAL_INT16(0,    res[73]); // end point size high
    TEST_ASSERT_EQUAL_INT16(0,    res[74]); // 0
    // end of CDC
    TEST_ASSERT_EQUAL_INT16(0,    res[75]);
    TEST_ASSERT_EQUAL_INT16(0,    res[76]);
    TEST_ASSERT_EQUAL_INT16(0,    res[77]);
    TEST_ASSERT_EQUAL_INT16(0,    res[78]);
}

void test_tud_descriptor_string_cb(void)
{
    const uint16_t* res = tud_descriptor_string_cb(0, 0);
    TEST_ASSERT_NOT_NULL(res);
    TEST_ASSERT_EQUAL_INT16(0x0304, res[0]);
    res = tud_descriptor_string_cb(1, 0); // "Raspberry Pi"
    TEST_ASSERT_NOT_NULL(res);
    TEST_ASSERT_EQUAL_INT16(0x031a, res[0]);
    TEST_ASSERT_EQUAL_INT16('R', res[1]);
    TEST_ASSERT_EQUAL_INT16('a', res[2]);
    TEST_ASSERT_EQUAL_INT16('s', res[3]);
    TEST_ASSERT_EQUAL_INT16('p', res[4]);
    TEST_ASSERT_EQUAL_INT16('b', res[5]);
    TEST_ASSERT_EQUAL_INT16('e', res[6]);
    TEST_ASSERT_EQUAL_INT16('r', res[7]);
    TEST_ASSERT_EQUAL_INT16('r', res[8]);
    TEST_ASSERT_EQUAL_INT16('y', res[9]);
    TEST_ASSERT_EQUAL_INT16(' ', res[10]);
    TEST_ASSERT_EQUAL_INT16('P', res[11]);
    TEST_ASSERT_EQUAL_INT16('i', res[12]);

}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_tud_descriptor_device_cb);
    RUN_TEST(test_tud_descriptor_configuration_cb);
    RUN_TEST(test_tud_descriptor_string_cb);
    return UNITY_END();
}
