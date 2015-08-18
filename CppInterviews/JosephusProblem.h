#pragma once
class JosephusProblem
{
    struct Node
    {
        int number;
        Node* next;
    };

public:
    JosephusProblem();
    ~JosephusProblem();

    int LastAlive(int n, int start);

private:
    int JosephusProblem::isPowerOfTwo(unsigned int x);
};

