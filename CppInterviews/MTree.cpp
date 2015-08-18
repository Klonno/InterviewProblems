#include "stdafx.h"
#include "MTree.h"


MTree::MTree() : m_head(NULL)
{
}


MTree::~MTree()
{
    this->DeleteTree();
}

//
// DeleteTree
//
void MTree::DeleteTree()
{
    if (this->m_head)
    {
        // M_aryNode* node;
        while (m_head->m_nodes.size())
        {
            // Deletes the element at the end of a list.
            m_head->m_nodes.pop_back();
        }
        //
        // And last but not least delete the head
        //
        delete m_head;
    }        
}

//
//
//
void MTree::BuildTree(M_aryNode* level, int currentLevel, int numberLevels, int numNodes)
{
    for (; currentLevel < numberLevels; ++currentLevel)
    {
        level->m_value = currentLevel;
        //
        // Build m-ary nodes
        //
        BuildTree(level, currentLevel + 1, numberLevels, numNodes);
        for (int j = 0; j < numNodes; ++j)
        {
            M_aryNode* node = new M_aryNode();
            node->m_value = currentLevel + j / 10;
            level->m_nodes.push_back(node);
        }
    }
}

//
//
//
void MTree::BuildTree(int numberLevels, int numNodes)
{
    if (numberLevels > 0)
    {
        this->m_head = new M_aryNode();
        this->m_head->m_value = 1.0;
        M_aryNode* level = m_head;
        this->BuildTree(level, 1, numberLevels, numNodes);
    }
}
