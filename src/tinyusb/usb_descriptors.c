#include "usb_descriptors.h"
// tinyusb:
#include "tinyusb/src/tusb.h"
#include "tinyusb/src/device/usbd.h"
#include "tinyusb/src/common/tusb_types.h"

#define DESC_STR_MAX 20
#define USBD_MAX_POWER_MA 250
#define USBD_DESC_LEN (TUD_CONFIG_DESC_LEN + TUD_CDC_DESC_LEN * CFG_TUD_CDC)

#define USBD_VID 0x2E8A /* Raspberry Pi */
#define USBD_PID 0x000A /* Raspberry Pi Pico SDK CDC */

#define USBD_ITF_CDC_0 0
#define USBD_ITF_MAX 4

#define USBD_CDC_0_EP_CMD 0x81
#define USBD_CDC_0_EP_OUT 0x02
#define USBD_CDC_0_EP_IN 0x82
#define USBD_CDC_CMD_MAX_SIZE 8
#define USBD_CDC_IN_OUT_MAX_SIZE 64

#define USBD_STR_0 0x00
#define USBD_STR_MANUF 0x01
#define USBD_STR_PRODUCT 0x02
#define USBD_STR_SERIAL 0x03
#define USBD_STR_CDC 0x04

static const tusb_desc_device_t usbd_desc_device = {
    .bLength = sizeof(tusb_desc_device_t),
    .bDescriptorType = TUSB_DESC_DEVICE,
    .bcdUSB = 0x0200,
    .bDeviceClass = TUSB_CLASS_MISC,
    .bDeviceSubClass = MISC_SUBCLASS_COMMON,
    .bDeviceProtocol = MISC_PROTOCOL_IAD,
    .bMaxPacketSize0 = CFG_TUD_ENDPOINT0_SIZE,
    .idVendor = USBD_VID,
    .idProduct = USBD_PID,
    .bcdDevice = 0x0100,
    .iManufacturer = USBD_STR_MANUF,
    .iProduct = USBD_STR_PRODUCT,
    .iSerialNumber = USBD_STR_SERIAL,
    .bNumConfigurations = 1,
};

static const uint8_t usbd_desc_cfg[USBD_DESC_LEN] = {
    TUD_CONFIG_DESCRIPTOR(1,
                          USBD_ITF_MAX,
                          USBD_STR_0,
                          USBD_DESC_LEN,
                          TUSB_DESC_CONFIG_ATT_REMOTE_WAKEUP,
                          USBD_MAX_POWER_MA),

    TUD_CDC_DESCRIPTOR(USBD_ITF_CDC_0,
                       USBD_STR_CDC,
                       USBD_CDC_0_EP_CMD,
                       USBD_CDC_CMD_MAX_SIZE,
                       USBD_CDC_0_EP_OUT,
                       USBD_CDC_0_EP_IN,
                       USBD_CDC_IN_OUT_MAX_SIZE),
};

static const char *const usbd_desc_str[] = {
    [USBD_STR_MANUF] = "Raspberry Pi",
    [USBD_STR_PRODUCT] = "Pico",
    [USBD_STR_SERIAL] = "000000000001",
    [USBD_STR_CDC] = "nomagic probe",
};

//! Invoked when received GET STRING DESCRIPTOR request
//! Application return pointer to descriptor, whose contents must exist long enough for transfer to complete
uint16_t const* tud_descriptor_string_cb(uint8_t index, uint16_t langid)
{
    (void)langid;
    static uint16_t desc_str[DESC_STR_MAX];
    uint8_t len;

    if (index == 0)
    {
        desc_str[1] = 0x0409;
        len = 1;
    }
    else
    {
        const char *str;

        if (index >= sizeof(usbd_desc_str) / sizeof(usbd_desc_str[0]))
        {
            return NULL;
        }

        str = usbd_desc_str[index];
        for (len = 0; len < DESC_STR_MAX - 1 && str[len]; ++len)
        {
            desc_str[1 + len] = str[len];
        }
    }

    desc_str[0] = (uint16_t)(0xffff & ((TUSB_DESC_STRING << 8) | (2 * len + 2)));

    return desc_str;
}

//! Invoked when received GET CONFIGURATION DESCRIPTOR request
//! Application return pointer to descriptor, whose contents must exist long enough for transfer to complete
uint8_t const * tud_descriptor_configuration_cb(uint8_t index)
{
    (void) index; // TODO multiple configurations ?
    return usbd_desc_cfg;
}

//! Invoked when received GET DEVICE DESCRIPTOR request
//! Application return pointer to descriptor
uint8_t const * tud_descriptor_device_cb(void)
{
    return (const uint8_t *) &usbd_desc_device;
}

