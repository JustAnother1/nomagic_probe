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

#include <stdbool.h>
#include <stdint.h>

void watchdog_disable(void)
{

}

void watchdog_enable(void)
{

}

void watchdog_feed(void)
{

}

bool watchdog_report(const uint32_t loop)
{
    (void) loop;
    return true;
}

void watchdog_report_issue(const uint32_t issue)
{
    (void) issue;
}

void watchdog_report_value(const uint32_t value)
{
    (void) value;
}

void watchdog_enter_section(const uint32_t section)
{
    (void) section;
}

void watchdog_leave_section(const uint32_t section)
{
    (void) section;
}
