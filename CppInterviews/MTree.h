#pragma once
#include <iostream>
#include <list>

//
// M-ary tree
//
struct M_aryNode
{
    double m_value;
    std::list<M_aryNode*> m_nodes;
    ~M_aryNode()
    {
        std::cout << "M_aryNode Destructor value = " << m_value << std::endl;
    }
};

class MTree
{
private:
    M_aryNode*   m_head;
    void BuildTree(M_aryNode* level, int currentLevel, int numberLevels, int numNodes);
    void DeleteTree();

public:
    MTree();
    virtual ~MTree();

    void BuildTree(int numberLevels, int numNodes);

};

