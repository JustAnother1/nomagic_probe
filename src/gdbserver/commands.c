#include "commands.h"
#include <stdint.h>
#include <stdbool.h>
#include "gdbserver.h"
#include "util.h"
#include "cfg/gdbserver_cfg.h"

typedef struct {
    bool extended_mode;
} config_typ;


static config_typ cfg;

static bool checksumOK(char* received, uint32_t length, char* checksum);
static void handle_general_query(char* received, uint32_t length);
static void handle_general_set(char* received, uint32_t length);

void commands_init(void)
{
    cfg.extended_mode = false;
}


// split received packet into command + parameters
// split by ',', ';' and ':'
// The binary data representation uses 7d (ASCII ‘}’) as an escape character. Any escaped byte is transmitted as the escape character followed by the original character XORed with 0x20. For example, the byte 0x7d would be transmitted as the two bytes 0x7d 0x5d. The bytes 0x23 (ASCII ‘#’), 0x24 (ASCII ‘$’), and 0x7d (ASCII ‘}’) must always be escaped. Responses sent by the stub must also escape 0x2a (ASCII ‘*’), so that it is not interpreted as the start of a run-length encoded sequence (described next).
// Response data can be run-length encoded to save space. Run-length encoding replaces runs of identical characters with one instance of the repeated character, followed by a ‘*’ and a repeat count. The repeat count is itself sent encoded, to avoid binary characters in data: a value of n is sent as n+29. For a repeat count greater or equal to 3, this produces a printable ASCII character, e.g. a space (ASCII code 32) for a repeat count of 3. (This is because run-length encoding starts to win for counts 3 or more.) Thus, for example, ‘0* ’ is a run-length encoding of “0000”: the space character after ‘*’ means repeat the leading 0 32 - 29 = 3 more times.
// The printable characters ‘#’ and ‘$’ or with a numeric value greater than 126 must not be used. Runs of six repeats (‘#’) or seven repeats (‘$’) can be expanded using a repeat count of only five (‘"’). For example, ‘00000000’ can be encoded as ‘0*"00’.

void commands_execute(char* received, uint32_t length, char* checksum)
{
    if(false == checksumOK(received, length, checksum))
    {
        DEBUG_LOG("\nchecksum is wrong($%s#%s)!\n", received, checksum);
        send_error_packet();
        return;
    }
    // else OK
    send_ack_packet();  // ack the received packet

    DEBUG_LOG("\nparsing command %s!\n", received);

    switch(*received)
    {
        case '!': // enable extended mode
            if(1 == length)
            {
                cfg.extended_mode = true;
                reply_packet_prepare();
                reply_packet_add("OK");
                reply_packet_send();
            }
            else
            {
                send_unknown_command_reply();
            }
            break;

        case 'q': // general query
            if(1 < length)
            {
                handle_general_query(received, length);
            }
            else
            {
                send_unknown_command_reply();
            }
            break;

        case 'Q': // general set
            if(1 < length)
            {
                handle_general_set(received, length);
            }
            else
            {
                send_unknown_command_reply();
            }
            break;

        case '?':
        case 'G':
        case 'g':
        case 'M':
        case 'm':
        case 'c':  // continue
        case 'v':
            // vCont

        default : // unknown or unsupported command
            send_unknown_command_reply();
            break;
    }
}

bool checksumOK(char* received, uint32_t length, char* checksum)
{
    uint32_t calculated_sum = 0;
    uint32_t recieved_sum;

    calculated_sum = calculateChecksum(received, length);
    recieved_sum = hex_to_int(checksum, 2);

    if(calculated_sum == recieved_sum)
    {
        return true;
    }
    else
    {
        DEBUG_LOG("expected: 0x%02lx received : 0x%02lx\n", calculated_sum, recieved_sum);
        return false;
    }
}

static void handle_general_query(char* received, uint32_t length)
{
    (void)length; // TODO
    if(0 == strncmp(received, "qSupported", 10))
    {
        // TODO parse parameters
        reply_packet_prepare();
        // TODO add supported features
        reply_packet_add("hwbreak+");
        reply_packet_send();
    }
    else
    {
        send_unknown_command_reply();
    }
}

static void handle_general_set(char* received, uint32_t length)
{
    // TODO
    (void) received;
    (void) length;
}

