// CppInterviews.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "newclass.h"
#include "LinkedList.h"
#include <memory>
#include <iostream>
#include "StringHelpers.h"
#include "Hash.h"
#include "JosephusProblem.h"
#include "MTree.h"
#include "SearchAlgos.h"
#include "Recursion.h"
#include "singletons.h"
#include "Conversions.h"
#include "graphics.h"
#include "printleveltree.h"

int MyMul(int a, int b);

struct RandNode
{
    int value;
    RandNode* rand;
    RandNode* next;
};

struct BinaryNode
{
    int value;
    BinaryNode* left;
    BinaryNode* right;

    BinaryNode() : value(0), left(NULL), right(NULL){};
};

struct foo {int x;};

struct test
{
    unsigned int x;
    unsigned int y : 8;
    unsigned int z;
};

#define NUMBER_WORDS 8
#define MAX_WORD_LEN 64

char words[NUMBER_WORDS][MAX_WORD_LEN] = { "foo", "bar", "bat", "monkey", "cigar", "ape", "pig", "donkey"};

int _tmain(int argc, _TCHAR* argv[])
{
	CNewClass newClass(1);
    Node* head;
    ChildNode* childHead;
    ChildNode* clonedHead;
    //
    // STL smart pointers
    //
    std::unique_ptr<LinkedList> ll(new LinkedList);
    std::unique_ptr<StringHelpers> stringHelper(new StringHelpers);
    std::unique_ptr<Hash> hashTable(new Hash(NUMBER_WORDS));
    std::unique_ptr<SearchAlgos> search(new SearchAlgos());
 

    //
    // Create and tear down a singular linked list
    //
    ll->CreateLinkedList<Node>(&head, 5);
    ll->DetectLoop(head);
    ll->Reverse(&head);
    ll->DeleteLinkedList(head);

    //
    // Clone linked list with children
    //
    ll->CreateLinkedList<ChildNode>(&childHead, 5);
    childHead->child = childHead->next->next;
    childHead->next->next->next->next->child = childHead;
    clonedHead = ll->CloneChildList(childHead);
    ll->DeleteLinkedList(childHead);
    ll->DeleteLinkedList(clonedHead);



    // A value of type "const char *" cannot be used to initialize an entity of type "char *"
    // char* pFoo = newClass.ReturnConstString(); Must declare a pointer to constant type string.
    const char* pFoo = newClass.ReturnConstString();
    
    int i = 5;
    int j = i;
    newClass.CannotAlterParameter(i, j);

    int result = MyMul(1000, 1000);

    //
    // Build hash table
    //
    for (i = 0; i < NUMBER_WORDS; ++i)
    {
        hashTable->Add(words[i]);
    }

    int x = 5;
    int& rx = x;

    int& y = newClass.ReferenceMethod(rx);

    // Bit fields
    std::cout << "The size of the bitfields are: " << sizeof(test) << " Press any key to continue." << std::endl;
 
    //
    // find words in the hash table
    //
    for (i = 0; i < NUMBER_WORDS; ++i)
    {
        const char* found = hashTable->Find(words[i]);
        if (NULL != found)
        {
            std::cout << "Found word: " << found << std::endl;
        }
        else
        {
            std::cout << "Did not find word: " << words[i] << std::endl;
        }
    }

    //
    // Binary search of an array
    //
    const int intArraySize = 17;
    int intArray[intArraySize] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17 };
    for (i = 0; i < intArraySize + 2; ++i)
    { 
        int index = search->BinarySearch(intArray, 0, intArraySize, i);
        if (index == ERR_INDEX_NOTFOUND)
        {
            std::cout << "ERR_INDEX_NOTFOUND looking for " << i << std::endl;
        }
        else if (index == ERR_INDEXES_REVERSED)
        {
            std::cout << "ERR_INDEXES_REVERSED" << std::endl;
        }
        else
        {
            std::cout << "Found " << i << " at index " << index << std::endl;
        }
    }

    //
    // Oracle
    // 
    //int  intarray[] = {-1, -2, 3, 6, -2, 10, -9};
    int  intarray[] = { 3, -2, 6, -9 };
    int  len = sizeof(intarray) / sizeof(int);
    int  lowIndex, highIndex, max;
    search->FindHighestSubArray(intarray, len, lowIndex, highIndex, max);



    //
    // Josephus Problem
    //
    std::unique_ptr<JosephusProblem> jp(new JosephusProblem());
    for (i = 1; i < 17; ++i)
    {
        int lastAlive = jp->LastAlive(i, 0);
        std::cout << "Number of people = " << i << " Last alive = " << lastAlive << std::endl;
    }

    //
    // M-ary linked list
    //
    std::unique_ptr<MTree> mTree(new MTree());

    mTree->BuildTree(2,3);

    //
    // Fibonacci, Limeade (and others)
    //
    std::unique_ptr<Recursion> recurse(new Recursion());
    //for (int i = 0; i < 10; ++i)
    //{
        int fib = recurse->FibonacciNumber(7);
        std::cout << "FibonacciNumber at index " << i << " is " << fib << "." << std::endl;
   // }

    //
    // Amazon
    recurse->NaturalNumberCombos(10);



    //
    // Reverse string
    //
    char str[] = { "reverse me now Scott" };
    std::cout << "The string \"" << str << "\" reversed is: ";
    char* reversed = stringHelper->ReverseString(str);
    std::cout << "\"" << str << "\"" << std::endl;

    char s1[] = "iceman";
    char s2[] = "cinema";

    bool bIsAnagram = stringHelper->IsAnagrammer(s1, s2);
 
    
    //
    // Factorial
    //
    int factorial;
    //for (i = 0; i < 10; ++i)
    //{
        i = 5;
        factorial = recurse->Factorial(i);
        std::cout << i << "! = " << factorial << std::endl;
    //}

    //
    // Singleton, riuntime initialized vs. static initialization. Oracle BI.
    //
    RunTimeInitSingleton* runtimeSingleton1 = RunTimeInitSingleton::GetPointer();
    RunTimeInitSingleton* runtimeSingleton2 = RunTimeInitSingleton::GetPointer();

    StaticInitializationSingleton* staticInitializationSingleton = StaticInitializationSingleton::GetPointer();

    //
    // Some conversions. I have been asked this various times in my career.
    //
    int atoi = Conversions::atoi("124");
    
    char buffer[255];
    char* converted = Conversions::itoa(1, buffer);

    //
    // some graphics
    //
    std::unique_ptr<CGraphics> graphics(new CGraphics());
    POINT pt = {1,17};
    RECT rect = {0,0, 15,15};

    BOOL pointInRect = graphics->PointInRect(pt, rect);
    int bitcounter = graphics->CountHighBits(0x0100);
    //
    //

    // All permutations of a string
    char letters[] = { "abc" };
    stringHelper->permutation(letters, 0, strlen(letters));

    struct test t;
    unsigned int *ptr1 = &t.x;
    unsigned int *ptr2 = &t.z;

    return 0;
}



//
// Mutiplication without a *
//
int MyMul(int a, int b)
{
    int result = 0;
    while (b > 0)
    {
        if ((b & 1) == 1)
        {
            result += a;
        }

        b >>= 1;
        a <<= 1;
    }

    return result;
}

#ifdef FIND_IF_LINES_INTERSECT
struct Point
{
public:
    double x;
    double y;

    // Add this instance's value to other, and return a new instance
    // with the result.
    const Point Point::operator-(const Point &other) const {
        Point result = *this;     // Make a copy of myself.  Same as MyClass result(*this);
        result -= other;            // Use += to add other to the copy.
        return result;              // All done!
    };
};

inline double Dot(const Point& a, const Point& b)                        { return (a.x*b.x) + (a.y*b.y); }
inline double PerpDot(const Point& a, const Point& b)                    { return (a.y*b.x) - (a.x*b.y); }

bool LineCollision(const Point& A1, const Point& A2,
    const Point& B1, const Point& B2,
    double* out = 0)
{
    Point a(A2 - A1);
    Point b(B2 - B1);

    double f = PerpDot(a, b);
    if (!f)      // lines are parallel
        return false;

    Point c(B2 - A2);
    double aa = PerpDot(a, c);
    double bb = PerpDot(b, c);

    if (f < 0)
    {
        if (aa > 0)     return false;
        if (bb > 0)     return false;
        if (aa < f)     return false;
        if (bb < f)     return false;
    }
    else
    {
        if (aa < 0)     return false;
        if (bb < 0)     return false;
        if (aa > f)     return false;
        if (bb > f)     return false;
    }

    if (out)
        *out = 1.0 - (aa / f);
    return true;
}
#endif

