
#ifndef NOMAGIC_STEPS_H_
#define NOMAGIC_STEPS_H_

#include <stdbool.h>
#include <stdint.h>
#include "result.h"

typedef enum {
    STEP_CONNECT = 0,
    STEP_AP_READ,
    STEP_AP_WRITE,
    // new steps go here
    NUM_STEPS_DEFINED,  // <- do not use other than array size !
}step_typ;

typedef struct{ //
    uint32_t par_i_0;//     targetId  | | address
    uint32_t par_i_1;//     APSel     | | value
    uint32_t phase;
    Result result; //     RESULT_OK
    int32_t intern_0;
    step_typ type; //    STEP_CONNECT | STEP_AP_READ | STEP_AP_WRITE
    bool par_b_0; //       isSWDv2?   | |
    bool is_done;
    uint8_t padding;
} step_data_typ;

void steps_execute(step_data_typ* cur_step);

#endif /* NOMAGIC_STEPS_H_ */
