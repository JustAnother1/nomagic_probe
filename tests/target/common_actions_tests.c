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
#include <string.h>

#include "unity.h"
#include "probe_api/result.h"
#include "probe_api/util.h"
#include "target/common_actions.h"

void setUp(void)
{

}

void tearDown(void)
{

}

// Result handle_target_reply_g(action_data_typ* const action);
void test_handle_target_reply_g(void)
{
    Result res;
    action_data_typ action;
    memset(&action, 0, sizeof(action));
    action.first_call = true;

    res = handle_target_reply_g(&action);

    TEST_ASSERT_FALSE(action.first_call);
    TEST_ASSERT_EQUAL_INT32(ERR_TIMEOUT, res);
}

// Result handle_target_reply_questionmark(action_data_typ* const action)
void test_handle_target_reply_questionmark(void)
{
    Result res;
    action_data_typ action;
    memset(&action, 0, sizeof(action));

    res = handle_target_reply_questionmark(&action);

    TEST_ASSERT_EQUAL_UINT32(RESULT_OK, res);
}


int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_handle_target_reply_g);
    RUN_TEST(test_handle_target_reply_questionmark);
    return UNITY_END();
}
