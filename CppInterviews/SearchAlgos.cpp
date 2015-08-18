#include "stdafx.h"
#include "SearchAlgos.h"


SearchAlgos::SearchAlgos()
{
}


SearchAlgos::~SearchAlgos()
{
}
#if 0
const int numBalls = 4;

enum ColoredBall
{
    Red = 0,
    Green = 1,
    Yellow = 2, 
    Blue = 3,
    LastColor = 4
    //Found = 4,
   // NotFound = 5
};
int ReturnScore(ColoredBall computer[numBalls], ColoredBall user[numBalls])
{
    // 1 point if coloer guessed, 2 points if color matches position
    int score = 0;
    int found[ColoredBall::LastColor] = { 0, 0, 0, 0 };

    for (int i = 0; i < LastColor; i++)
    {
#if 0        
        if (computer[i] == user[i])
        {
            score += 2;
        }
        else
        {
            if (found[computer[i]] == ColoredBall::NotFound)
            {
                found[computer[i]] = ColoredBall::Found;
            }
        }
    }
#endif
    return score;
}
#endif

//
// Was asked this at Oracle:
// Find highest subarray value in the array. Example:
// {-1, -2, 3, 6, -2, 10, -9}
// Would return:
// {3, 6, -2, 10}
// This is basically Kadane’s Algorithm:
//int maxSubArraySum(int a[], int size)
//{
//    int max_so_far = 0, max_ending_here = 0;
//    int i;
//    for (i = 0; i < size; i++)
//    {
//        max_ending_here = max_ending_here + a[i];
//        if (max_ending_here < 0)
//            max_ending_here = 0;
//        if (max_so_far < max_ending_here)
//            max_so_far = max_ending_here;
//    }
//    return max_so_far;
//}
void SearchAlgos::FindHighestSubArray(int array[], int arrayLen, int& lowIndex, int& highIndex, int& max)
{
    lowIndex = highIndex = max = 0;
    int i, sum, startIndex;
    
    for (i = 0, sum = 0, startIndex = 0; i < arrayLen; i++)
    {
        sum += array[i];
        if (sum < 0)
        {
            startIndex = i + 1;
            sum = 0;
        }
        if (sum > max)
        {
            lowIndex = startIndex;
            highIndex = i;
            max = sum;
        }
    }
}


// Find the index of the SORTED array that contains target.
int SearchAlgos::BinarySearch(int* array, int lowerIndex, int upperIndex, int target)
{
    int index = ERR_INDEX_NOTFOUND;
    int center;
    int oCounter = 1;   // Instead of a linear search we will do O(logn)

    if (upperIndex < lowerIndex)
    {
        return ERR_INDEXES_REVERSED;
    }
    while (1)
    {
        center = lowerIndex + ((upperIndex - lowerIndex) / 2);
        if (target > array[center])
        {
            lowerIndex = ++center;
            if (center > upperIndex)
            {
                break;
            }
        }
        else if (target < array[center])
        {
            upperIndex = --center;
            if (center < 0)
            {
                break;
            }
        }
        else if (target == array[center])
        {
            index = center;
            break;
        }
        else
        {
            break;
        }
        ++oCounter;
    }
    if (index >= 0)
    {
        std::cout << "Found target=" << target << " at index=" << index << " in " << oCounter << " tries." << std::endl;
    }
    return index;
}
