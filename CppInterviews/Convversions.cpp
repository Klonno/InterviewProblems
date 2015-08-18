#include "stdafx.h"
#include "Conversions.h"


//
// LinkedIn
// 
bool Conversions::IsNumeric(char* input)
{
    if (input == NULL || input[0] == '\0')
    {
        return false;
    }
    if (input[0] == '-')
    {
        ++input;
    }
    int len = strlen(input);
    if (len == 0)
    {
        return false;
    }
    int i;
    bool multiple_decimals = false;

    for (i = 0; i < len; ++i)
    {
        // check to see if a numeric character
        if (input[i] - '0' >= 0 && input[i] - '0' <= 9)
            continue;
        else if (input[i] == '.' && len > 1)    // if its not just a '.' but what about "..."
        {
            if (i > 1 && input[i - 1] == '-' && len == 2)        // handle "-." case
                return false;
            if (false == multiple_decimals)
            {
                multiple_decimals = true;
                continue;
            }
        }
        return false;
    }
    return true;
}

//
// Old school. Probably did this in an interview in the early 1990s.
//
char* Conversions::itoa(int n, char* buffer)
{
    bool    isNeg = false;
    int     i = 0;
    int     j = 0;
    char    temp[255];

    // check to see if number is negative
    if(n < 0)
    {
        n *= -1;
        isNeg = true;
    }
    // fill buffer with digit chars in reverse order
    do
    {
        temp[i++] = (n % 10) + '0';
        n /= 10;
    } while (n);

    if (isNeg)
    {
        temp[i++] = '-';
    }

    // now reverse temp, into the actual order
    while (i > 0)
    {
        buffer[j++] = temp[--i];
    }
    // and null terminate
    buffer[j] = '\0';

    return buffer;
}

//
// Old school. Probably did this in an interview in the early 1990s.
//
int Conversions::atoi(char* buffer)
{
    int n = 0;
    int i = 0;
    int len = strlen(buffer);

    bool isNegative = false;

    // sanity check
    if (NULL == buffer && len <= 0)
        return  0;

    // Check to see if negative, if so go to character past negative sign
    if (buffer[0] == '-')
    {
        isNegative = true;
        ++i;
    }
    // Multiply each character * 10
    while (i < len)
    {
        n *= 10;
        
        int number = buffer[i] - '0';
        n += number;

        ++i;
    }
    // Make number negative if it had minus sign
    if (isNegative)
    {
        n *= -1;
    }
    
    return n;
}



Conversions::Conversions()
{
}


Conversions::~Conversions()
{
}
