#pragma once

class StringHelpers
{
public:
    StringHelpers();
    virtual ~StringHelpers();

public:
    void permutation(char* s, int i, int n);

    //
    // This was asked by Limeade
    //
    char* ReverseString(char* stringToReverse);

    //
    // IsAnagrammar (Amazon)
    //
    bool IsAnagrammer(char* s1, char* s2);

private:    
    void swap(char& a, char& b);
    void ReverseStringFromIndexToIndex(char* str, int startIndex, int endIndex);
};

