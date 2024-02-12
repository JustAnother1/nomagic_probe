
#ifndef NOMAGIC_WALK_H_
#define NOMAGIC_WALK_H_

#include <stdbool.h>
#include <stdint.h>
#include "result.h"

typedef enum {
    WALK_CONNECT = 0,
    WALK_SCAN,
    // new walks go here
    NUM_WALKS_DEFINED,  // <- do not use other than array size !
}walk_typ;

typedef struct{
    uint32_t par_i_0;//     targetId  |
    uint32_t par_i_1;//     APSel     |
    uint32_t phase;
    Result result;
    uint32_t intern_0;
    walk_typ type;//     WALK_CONNECT |
    bool is_done;
    bool par_b_0; //       isSWDv2?   |
    uint8_t padding;
} walk_data_typ;

void walk_init(void);
void walk_execute(walk_data_typ* data);

#endif /* NOMAGIC_WALK_H_ */
