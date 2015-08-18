#include "stdafx.h"
#include "LinkedList.h"


LinkedList::LinkedList()
{
}


LinkedList::~LinkedList()
{
}

//
// Traverse (visit) every node in a binary tree
// DFS, Depth First
//
void LinkedList::Traverse(BSTNode* root)
{ // Each child of a tree is a root of its subtree.
    if (root->left != NULL){
        Traverse(root->left);
    }
    // std::cout << root->value;
    if (root->right != NULL){
        Traverse(root->right);
    }
}


//
// Reverse the linked list 
//
void LinkedList::Reverse(struct Node** head_ref)
{
    struct Node* prev = NULL;
    struct Node* current = *head_ref;
    struct Node* next;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}



//
// Clone this list IN PLACE!
//
ChildNode* LinkedList::CloneChildList(ChildNode* head)
{
    ChildNode* original = head;
    ChildNode* cloned;
    ChildNode* clonedHead = NULL;

    if (head != NULL)
    { 
        // Allocate the new cloned list, Set the original->next pointer to poinnt to the cloned node.
        while (original != NULL)
        {
            cloned = new ChildNode();
            cloned->value = original->value;

            cloned->next = original->next;
            original->next = cloned;
        
            original = cloned->next;
        }

        // Set the cloned head, saving to return to caller
        clonedHead = head->next;

        // Now copy in place
        original = head;
        while (original != NULL)
        {
            // set the cloned node to be ->next of the original.
            cloned = original->next;
            
            // Set the cloned child value
            if (NULL != original->child)
            {
                cloned->child = original->child->next;
            }
            else
            {
                cloned->child = NULL;
            }

            // restore original list
            original->next = cloned->next;

            if (NULL != original->next)
            {
                original = original->next;
                cloned->next = original->next;
            }
            else
            {
                original = NULL;
                cloned->next = NULL;
            }
        }
    }    
    return clonedHead;
}

//
//
bool LinkedList::DetectLoop(Node* head)
{
    Node* slow = head;
    Node* fast = head;


    while (slow != NULL && 
          fast != NULL && 
          fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        /* If slow and fast meet at some point then there
        is a loop */
        if (slow == fast)
        {
            RemoveLoop(slow, head);

            /* Return 1 to indicate that loop is found */
            return true;
        }

    }
    return false;
}

/* Function to remove loop.
loop_node --> Pointer to one of the loop nodes
head -->  Pointer to the start node of the linked list */
void LinkedList::RemoveLoop(struct Node *loop_node, struct Node *head)
{
    Node *ptr1;
    Node *ptr2;

    /* Set a pointer to the beging of the Linked List and
    move it one by one to find the first node which is
    part of the Linked List */
    ptr1 = head;
    while (1)
    {
        /* Now start a pointer from loop_node and check if it ever
        reaches ptr2 */
        ptr2 = loop_node;
        while (ptr2->next != loop_node && ptr2->next != ptr1)
        {
            ptr2 = ptr2->next;
        }

        /* If ptr2 reahced ptr1 then there is a loop. So break the
        loop */
        if (ptr2->next == ptr1)
            break;

        /* If ptr2 did't reach ptr1 then try the next node after ptr1 */
        else
            ptr1 = ptr1->next;
    }

    /* After the end of loop ptr2 is the last node of the loop. So
    make next of ptr2 as NULL */
    ptr2->next = NULL;
}

