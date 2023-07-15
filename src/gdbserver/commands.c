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
static void handle_vee(char* received, uint32_t length);
static void handle_tee(char* received, uint32_t length);

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

        case '?':  // Report why the target halted
            // TODO
            send_unknown_command_reply();
            break;

        case 'c':  // continue
        case 'C':  // continue
        case 'D':  // Detach from client
        case 'G':  // read  or write general Registers
        case 'g':  // read  or write general Registers
        case 'H':  // report the current tread
            // Hc ?
        case 'k':  // kill the target
        case 'M':  // read  or write main memory
        case 'm':  // read  or write main memory
        case 'P':  // read  or write specific Register
        case 'p':  // read  or write specific Register
            // TODO
            send_unknown_command_reply();
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

        case 'R':  // Restart the program being run
        case 's':  // step
        case 'S':  // step
            // TODO
            send_unknown_command_reply();
            break;

        case 'T':  // report if a particular Thread is alive
            // TODO
            send_unknown_command_reply();
            break;

        case 't':
            handle_tee(received, length);
            break;

        case 'v':
            handle_vee(received, length);
            break;

        case 'X':  // load binary data
        case 'Z':  // clear or set breakpoints or watchpoints
            // TODO
            send_unknown_command_reply();
            break;

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

static void handle_vee(char* received, uint32_t length)
{
    (void)length; // TODO
    if(0 == strncmp(received, "v", 10))
    {
        // Report the features supported by the server.
        // TODO parse parameters
        reply_packet_prepare();
        // TODO add supported features
        reply_packet_add("hwbreak+");
        reply_packet_send();
    }
    else if(0 == strncmp(received, "vCont", 10))
    {
        // specify step or continue actions specific to one or more threads
        // TODO
        send_unknown_command_reply();
    }
    else if(0 == strncmp(received, "vCont?", 10))
    {
        // report the supported vCont actions
        // TODO
        send_unknown_command_reply();
    }
    else if(0 == strncmp(received, "vAttach", 10))
    {
        // Attach to (new) process
        // TODO
        send_unknown_command_reply();
    }
    else if(0 == strncmp(received, "vRun", 10))
    {
        // run program
        // TODO
        send_unknown_command_reply();
    }
    else
    {
        send_unknown_command_reply();
    }
}

static void handle_tee(char* received, uint32_t length)
{
    (void)length; // TODO
    if(0 == strncmp(received, "target async", 10))
    {
        // debug with other core running
        // TODO
        send_unknown_command_reply();
    }
    else if(0 == strncmp(received, "target extended-async", 10))
    {
        // debug with other core running
        // TODO
        send_unknown_command_reply();
    }
    else
    {
        send_unknown_command_reply();
    }
}

static void handle_general_query(char* received, uint32_t length)
{
    (void)length; // TODO
    if(0 == strncmp(received, "qSupported", 10))
    {
        // Report the features supported by the server.
        // TODO parse parameters
        reply_packet_prepare();
        reply_packet_add("hwbreak+");
        reply_packet_add("PacketSize=1f0");
        // TODO add supported features
        reply_packet_send();
    }
    else if(0 == strncmp(received, "qC", 10))
    {
        // report the current tread
        // TODO
        send_unknown_command_reply();
    }
    else if(0 == strncmp(received, "qOffsets", 10))
    {
        // report the offsets to use when relocating downloaded code
        reply_packet_prepare();
        reply_packet_add("Text=0;Data=0;Bss=0;");
        reply_packet_send();
    }
    else if(0 == strncmp(received, "qSymbol", 10))
    {
        // request any symbol data
        // TODO
        send_unknown_command_reply();
    }
    else if(0 == strncmp(received, "qfThreadInfo", 10))
    {
        // report the current tread
        // TODO
        send_unknown_command_reply();
    }
    else if(0 == strncmp(received, "qsThreadInfo", 10))
    {
        // report the current tread
        // TODO
        send_unknown_command_reply();
    }
    else if(0 == strncmp(received, "qGetTLSAddr", 10))
    {
        // report the current tread
        // TODO
        send_unknown_command_reply();
    }
    else if(0 == strncmp(received, "qThreadExtraInfo", 10))
    {
        // report the current tread
        // TODO
        send_unknown_command_reply();
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
    send_unknown_command_reply();
}

