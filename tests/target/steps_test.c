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
#include "unity.h"
#include "probe_api/steps.h"

void setUp(void)
{

}

void tearDown(void)
{

}

// Result step_connect(bool multi, uint32_t target, uint32_t AP_sel);
void test_step_connect(void)
{
    Result res;

    res = step_connect(false, 0, 0);

    TEST_ASSERT_EQUAL_UINT32(RESULT_OK, res);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_step_connect);
    return UNITY_END();
}
