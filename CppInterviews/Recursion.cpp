#include "stdafx.h"
#include "Recursion.h"

#define PRINT_MESSAGES

Recursion::Recursion()
{
}


Recursion::~Recursion()
{
}

// Return the Fibonacci Number at the given posiition (Limeade).
//
// 1,1,2,3,5,8,13,21,34, 55, 89, 144
// Example: FibonacciNumber(4) would return 3
//
int Recursion::FibonacciNumber(int pos)
{
    if (1 == pos || 2 == pos)
    {
#ifdef PRINT_MESSAGES
        std::cout << "Fibonacci Position: " << pos << " = " << 1 << std::endl;
#endif
        return 1;
    }
    else if (pos == 0)  // Only valid is passed first time
    {
#ifdef PRINT_MESSAGES
        std::cout << "Fibonacci Position: " << pos << " = " << 0 << std::endl;
#endif
        return 0;
    }
    else
    {
#ifdef PRINT_MESSAGES
        int positionMinusOneValue = FibonacciNumber(pos - 1);
        std::cout << "Fibonacci Position: " << pos - 1 << " value = " << positionMinusOneValue << std::endl;

        int positionMinusTwoValue = FibonacciNumber(pos - 2);
        std::cout << "Fibonacci Position: " << pos - 2 << " value = " << positionMinusTwoValue << std::endl;
        return positionMinusOneValue + positionMinusTwoValue;
#else
        // Basically this is: return FibonacciNumber(pos - 1) + FibonacciNumber(pos - 2);
        return FibonacciNumber(pos - 1) + FibonacciNumber(pos - 2);
#endif
    }
}

//
// In mathematics, the factorial of a non-negative integer n, denoted by n!, is the product of 
// all positive integers less than or equal to n. For example,
// 5! = 5x4x3x2x1 = 120
//
int Recursion::Factorial(int x)
{
#ifdef PRINT_MESSAGES
    std::cout << "Factorial: x = " << x << std::endl;
#endif
    if (x == 0 || x == 1)
    {
        return 1;
    }

    return x * Factorial(x - 1);
}

//
// Amazon
//
//if C is 6, output
//6
//1 + 5
//2 + 4
//1 + 2 + 3
//
//and if C is 10, output
//10
//1 + 9
//2 + 8
//3 + 7
//4 + 6
//1 + 2 + 7
//1 + 3 + 6
//1 + 4 + 5
//2 + 3 + 5
//1 + 2 + 3 + 4

int Recursion::NaturalNumberCombos(int c)
{
    if (c == 0)
        return c;
    else
    {
        return NaturalNumberCombos(c, 1); // c - 1);
        //int n;
        //int x = NaturalNumberCombos(c - 1);
       // n = c + x;
       // return n;    /*self call  to function sum() */
    }
}
int Recursion::NaturalNumberCombos(int c, int start) //, int remainder)
{
    if (c - start <= start)
    {
        return 1;
    }
    //else if (int remainder = (c - start) > 0)
    //{
    //    while (remainder = (c - start) > 0)
    //    {
    //        std::cout << start << " + " << c - start << " ";
    //        NaturalNumberCombos(c, start + 1);
    //    }
    //    return NaturalNumberCombos(c, start + 1);
    //}
    else
    {
        std::cout << start << " + " << c - start << " = " << c << std::endl;
        return NaturalNumberCombos(c, start + 1);
    }
}
