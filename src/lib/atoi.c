#include <stdbool.h>

int atoi (const char * string)
{
    bool isNegative = false;
    int base = 10;
    int res = 0;

    while(0 != *string)
    {
        switch(*string)
        {
            case ',':
            case '.':
            case ' ':
                // skip character
                break;

            case 'X':
            case 'x':
                base = 16; // 0x12 is 18 and not 12
                break;

            case '-':
                isNegative = true;
                break;

            case '0': res = (res * base) + 0; break;
            case '1': res = (res * base) + 1; break;
            case '2': res = (res * base) + 2; break;
            case '3': res = (res * base) + 3; break;
            case '4': res = (res * base) + 4; break;
            case '5': res = (res * base) + 5; break;
            case '6': res = (res * base) + 6; break;
            case '7': res = (res * base) + 7; break;
            case '8': res = (res * base) + 8; break;
            case '9': res = (res * base) + 9; break;
            case 'A':
            case 'a': res = (res * base) + 10; break;
            case 'B':
            case 'b': res = (res * base) + 11; break;
            case 'C':
            case 'c': res = (res * base) + 12; break;
            case 'D':
            case 'd': res = (res * base) + 13; break;
            case 'E':
            case 'e': res = (res * base) + 14; break;
            case 'F':
            case 'f': res = (res * base) + 15; break;

            default:
                // invalid string
                return 0;
        }
        string++;
    }
    if(true == isNegative)
    {
        return -res;
    }
    else
    {
        return res;
    }
}
