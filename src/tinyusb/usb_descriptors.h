#ifndef SRC_TINYUSB_USB_DESCRIPTORS_H_
#define SRC_TINYUSB_USB_DESCRIPTORS_H_

#include <stdint.h>

uint16_t const* tud_descriptor_string_cb(uint8_t index, uint16_t langid);
uint8_t const * tud_descriptor_configuration_cb(uint8_t index);
uint8_t const * tud_descriptor_device_cb(void);

#endif /* SRC_TINYUSB_USB_DESCRIPTORS_H_ */
