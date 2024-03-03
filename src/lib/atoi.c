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
            case 'A':
            case 'a': res = (res * base) + 10; digits++; break;
            case 'B':
            case 'b': res = (res * base) + 11; digits++; break;
            case 'C':
            case 'c': res = (res * base) + 12; digits++; break;
            case 'D':
            case 'd': res = (res * base) + 13; digits++; break;
            case 'E':
            case 'e': res = (res * base) + 14; digits++; break;
            case 'F':
            case 'f': res = (res * base) + 15; digits++; break;

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
