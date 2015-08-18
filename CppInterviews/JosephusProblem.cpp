#include "stdafx.h"
#include "JosephusProblem.h"



// The Josephus Problem - asked by Oracle Cloud team
// A ring of n soldiers numbered from (0 .. n-1)
// Initial shooter is at start.
// Who is left alive?

// Example 1: n = 1, start 0 = 0
// one cannot shoot anyone
// Example 2: n = 2, start 0 = 0
// 0, 1
// 0 shoots 1
// 0 is still alive
// Example 3: n = 2, start 1 = 1
// 0, 1
// 1 shoots 0
// 1 is stil alive
//

//
// This suggests that f(n) is an increasing odd sequence that restarts with f(n) = 1 whenever the index n 
// is a power of 2. Therefore, if we choose m and l so that n = 2 ^ m + l and 0\leq l<2 ^ m, then f(n) = 2 \cdot l + 1.
//  It is clear that values in the table satisfy this equation.Or we can think that after l people are dead there are only 2 ^ m people and we go to the 2l + 1th person.He must be the survivor.So f(n) = 2l + 1. Below, we give a proof by induction.
// Theorem: If n = 2 ^ m + l and 0\leq l<2 ^ m, then f(n) = 2l + 1.
//
// The best way to solve this problem is to use a circular buffer of pointers that points back to itself
// O(2logn)
// returns variable alive, the number of the person last standing!
// returns negative number or zero if the starting index if higher than the number of people, or zero!
int JosephusProblem::LastAlive(int n, int startIndex) 
{
    int survivor = n - startIndex;

    if (survivor > 0)
    {
        // Allocate head
        Node* head = new Node();
        head->number = 1;
        head->next = head;
        Node* last = head;
        Node* node;
        Node* next;

        // Allocate a node for each person (starting at person #2 since we allocated a head @ #1
        for (int i = 2; i <= n; ++i)
        {
            node = new Node();
            node->number = i;
            node->next = NULL;
            if (i - 1 == startIndex)
            {
                head = node;
            }
            last->next = node;
            last = node;
        }
        // make the buffer circular
        last->next = head;

        // Loop and kill the node next to it
        node = head;
        while (node != node->next)
        {
            // Skip over the one we arre going to kill
            next = node->next->next;

            // Kill the person to the right
            delete node->next;
            
            // decrement next pointers
            node->next = next;

            // Hand the gun to the next person alive
            node = next;
        }
        survivor = node->number;
        delete node;
    }
    return survivor;
}


int JosephusProblem::isPowerOfTwo(unsigned int x)
{
    return ((x != 0) && !(x & (x - 1)));
}


JosephusProblem::JosephusProblem()
{
}


JosephusProblem::~JosephusProblem()
{
}

