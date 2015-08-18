#include "stdafx.h"
#include "StringHelpers.h"
#include <iostream>

StringHelpers::StringHelpers()
{
}


StringHelpers::~StringHelpers()
{
}

//
// implement an isAnagram function, that takes two strings as input and returns true/false if they are
// anagrams of each other.they are anagrams if re - arranging the characters in one results in the other.
// ex.iceman and cinema
//
bool StringHelpers::IsAnagrammer(char* s1, char* s2)
{
    const int ALPHABET_SIZE = 26;

    if (s1 == NULL || s2 == NULL)
        return false;
    if (strlen(s1) != strlen(s2))
        return false;

    int letterArray[ALPHABET_SIZE];
    memset(letterArray, 0, ALPHABET_SIZE * sizeof(int));
 
    //
    // Build array
    //
    // A = 65 or 0x41
    // a = 97 or 0x61
    //
    char* temp = s1;
    int index;

    while (*s1 != NULL)
    {
        if (false == isalpha(*s1))
        {
            return false;
        }
        //
        // Find index in to array
        //
        if (isupper(*s1))
        {
            index = (int)*s1 - 'A';
        }
        else
        {
            index = (int)*s1 - 'a';
        }
        letterArray[index] += 1;
        ++s1;
    }

    //
    // Now find each char
    //
    while (*s2 != NULL)
    {
        //
        // Find index
        //
        if (isupper(*s2))
        {
            index = (int)*s2 - 'A';
        }
        else
        {
            index = (int)*s2 - 'a';
        }
        letterArray[index] -= 1;
        if (letterArray[index] < 0)
            return false;
        ++s2;
    }
    return true;
}

//
// Helper for ReverseString
//
void StringHelpers::ReverseStringFromIndexToIndex(char* str, int startIndex, int endIndex)
{
    int i, j;

    for (i = startIndex, j = endIndex; i < j; ++i, --j)
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

//
// This was asked by Limeade
//
char* StringHelpers::ReverseString(char* stringToReverse)
{
    // first reverse the entire string
    int i;
    int lastIndex = ::strlen(stringToReverse) - 1;

    // revere the entire string
    ReverseStringFromIndexToIndex(stringToReverse, 0, lastIndex);

    // now reverse each word
    i = 0;
    int wordEndIndex = 0;
    int wordStartIndex = 0;

    while (wordEndIndex <= lastIndex)
    {
        if (stringToReverse[i] != ' ' && stringToReverse[i] != '\0')
        {
            ++i;
            wordEndIndex = i - 1;
        }
        else
        {
            ReverseStringFromIndexToIndex(stringToReverse, wordStartIndex, wordEndIndex);
            wordStartIndex = ++i;
        }
    }

    return stringToReverse;
}


/* Function to swap two characters */
void StringHelpers::swap(char& a, char& b)
{
    char temp;
    temp = a;
    a = b;
    b = temp;
}

/* Recursive algorith to obtain permutations of string characters
For ABC:
1) Start with A
    Swap A with A
        ABC
    Swap B with B
        ABC
    Swap C with B
        ACB
2) Go to B
    Swap A with B
        BAC
    Swap A with A
        BAC
    Swap A with C
        BCA
3) Go to C
    Swap A with C
        CBA
    Swap B with A
        CAB
*/

void StringHelpers::permutation(char* s, int startIndex, int numChars)
{
    int i;
    if (startIndex == numChars)
        std::cout << s << std::endl;
    else
    {
        for (i = startIndex; i < numChars; i++)
        {
            swap(s[startIndex], s[i]);
            permutation(s, startIndex + 1, numChars);
            swap(s[startIndex], s[i]);
        }
    }
}
