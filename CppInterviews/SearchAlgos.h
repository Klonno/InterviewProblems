#pragma once
#include <iostream>


#define ERR_INDEXES_REVERSED    -1
#define ERR_INDEX_NOTFOUND      -2


class SearchAlgos
{
public:
    SearchAlgos();
    virtual ~SearchAlgos();

    void FindHighestSubArray(int array[], int arrayLen, int& lowIndex, int& highIndex, int& max);
    int BinarySearch(int* array, int lowerIndex, int upperIndex, int target);
};

