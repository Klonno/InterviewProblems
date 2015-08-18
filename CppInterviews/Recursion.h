#pragma once
class Recursion
{
public:
    Recursion();
    virtual ~Recursion();

    int FibonacciNumber(int pos);

    int Factorial(int x);

    int NaturalNumberCombos(int c);

private:
    int NaturalNumberCombos(int c, int start);
 
};

