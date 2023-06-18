#include "ctype.h"
#include <stdbool.h>

/*! Returns true for every printing character including space (' '). */
int isprint( int c )
{
    if((c > 0x1f) && (c < 0x7f))
    {
        return true;
    }

    return false;
}


