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
#include "gdbserver/commands.h"

void setUp(void)
{
    commands_init();
}

void tearDown(void)
{

}

void test_commands_execute_null(void)
{
    commands_execute(NULL, 0, NULL);
}


int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_commands_execute_null);
    return UNITY_END();
}
