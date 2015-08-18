#pragma once
class Conversions
{
public:
    Conversions();
    virtual ~Conversions();

    static char* itoa(int n, char* buffer);
    static int atoi(char* buffer);
    static bool IsNumeric(char* input);

};

