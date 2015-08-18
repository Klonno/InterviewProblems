/*

!!!!!!!!!!!!!!!!!!! Demonstrate level order traversal !!!!!!!!!!!!!!!!!!!!!!!!!!!

Tree:
1
/\
3 5
/\ \
2 4 7
/  \
9   8

=======
expected output:
1
35
247
98
*/

#include <queue>
#include <iostream>

struct PNode    // Print Node
{
    int value;
    PNode* left;
    PNode* right;
};

class TreePrint 
{
public:
    void printTree(PNode* root) 
    {
        // implementation here

        // Create a queue
        std::queue<PNode*> q;

        // Save the root
        q.push(root);

        while (false == q.empty())
        {
            // Dequeue (get) the pushed node. Does not remove
            PNode* node = q.front();
            std::cout << node->value << std::endl;

            // Save left node
            if (NULL != node->left)
                q.push(node->left);

            // Save right node
            if (NULL != node->right)
                q.push(node->right);

            // Remove the visited node (node from above)
            q.pop();
        }
    };
};