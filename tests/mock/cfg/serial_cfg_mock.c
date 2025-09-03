#include <stdbool.h>
#include <stdint.h>


void serial_gdb_send_string(char * str)
{
    (void)str;
}

void serial_gdb_send_bytes(const uint8_t * data, const uint32_t length)
{
    (void)data;
    (void)length;
}

uint32_t serial_gdb_get_num_received_bytes(void)
{
    return 0;
}

uint8_t serial_gdb_get_next_received_byte(void)
{
    return 0;
}

void serial_gdb_putc(void* p, char c)
{
    (void)p;
    (void)c;
}

bool serial_gdb_is_connected(void)
{
    return false;
}

void serial_gdb_flush(void)
{

}

bool serial_gdb_is_buffer_full(void)
{
    return false;
}

// target UART
bool serial_cfg_is_target_UART_enabled(void)
{
    return false;
}

uint32_t serial_cfg_get_target_UART_baudrate(void)
{
    return 0;
}

uint32_t target_uart_pc_get_num_received_bytes(void)
{
    return 0;
}

uint8_t target_uart_pc_get_next_received_byte(void)
{
    return 0;
}

void target_uart_pc_send_bytes(const uint8_t * data, const uint32_t length)
{
    (void)data;
    (void)length;
}

// load configuration
void serial_cfg_reset_to_default(void)
{

}

void serial_cfg_set(char * setting, char * value)
{
    (void)setting;
    (void)value;
}

void serial_cfg_apply(void)
{

}

bool serial_cfg_is_USB_CDC_enabled(void)
{
    return true;
}


