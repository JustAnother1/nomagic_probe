#include <stdbool.h>
#include <stddef.h>

int atoi (const char * string)
{
    bool isNegative = false;
    int base = 10;
    int res = 0;
    int digits = 0;
    if(NULL == string)
    {
        return 0;
    }

    while((0 != *string) && (((base == 16) && (digits < 9)) || ((base == 10) && (digits < 11))))
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

            case '0': res = (res * base) + 0; digits++; break;
            case '1': res = (res * base) + 1; digits++; break;
            case '2': res = (res * base) + 2; digits++; break;
            case '3': res = (res * base) + 3; digits++; break;
            case '4': res = (res * base) + 4; digits++; break;
            case '5': res = (res * base) + 5; digits++; break;
            case '6': res = (res * base) + 6; digits++; break;
            case '7': res = (res * base) + 7; digits++; break;
            case '8': res = (res * base) + 8; digits++; break;
            case '9': res = (res * base) + 9; digits++; break;
            case 'A':                                                  // invalid string -> 0x prefix missing
            case 'a': if(16 == base) {res = (res * base) + 10; digits++;} else {return 0;} break;
            case 'B':
            case 'b': if(16 == base) {res = (res * base) + 11; digits++;} else {return 0;} break;
            case 'C':
            case 'c': if(16 == base) {res = (res * base) + 12; digits++;} else {return 0;} break;
            case 'D':
            case 'd': if(16 == base) {res = (res * base) + 13; digits++;} else {return 0;} break;
            case 'E':
            case 'e': if(16 == base) {res = (res * base) + 14; digits++;} else {return 0;} break;
            case 'F':
            case 'f': if(16 == base) {res = (res * base) + 15; digits++;} else {return 0;} break;

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
