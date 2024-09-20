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

#include "tinyusb/src/class/msc/msc_device.h"
#include "unity.h"

void setUp(void)
{

}

void tearDown(void)
{

}

void test_usb_msc_unit_ready_cb(void)
{
    bool res = tud_msc_test_unit_ready_cb(0);
    TEST_ASSERT_TRUE(res);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_usb_msc_unit_ready_cb);
    return UNITY_END();
}
