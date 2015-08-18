#pragma once


struct Node
{
    int value;
    Node* next;
    Node() : value(0), next(NULL){};
};

struct BSTNode
{
    int value;
    BSTNode* left;
    BSTNode* right;
    BSTNode() : value(0), left(NULL), right(NULL) {};
};

struct ChildNode
{
    int value;
    ChildNode* child;
    ChildNode* next;
    ChildNode() : value(0), next(NULL), child(NULL){};
};

class LinkedList
{
public:
    LinkedList();
    virtual ~LinkedList();

    void Reverse(struct Node** head_ref);
    
    void Traverse(BSTNode* root);

    template<typename T>
    void DeleteLinkedList(T* head)
    {
        T* last;
        T* current;

        last = current = head;

        while (current != NULL)
        {
            current = last->next;
            delete last;
            last = current;
        }
    }
    template<typename T>
    void CreateLinkedList(T** head, int count)
    {
        if (count > 0)
        {
            // Create the head
            *head = new T();
            T* current = *head;
            T* last = *head;     // to simulate looping back

            for (int i = 0; i < count; ++i)
            {
                current->value = i;
                if (i < count - 1)
                {
                    last = current;
                    current->next = new T();
                    current = current->next;
                }
            }
        }
    }

    bool DetectLoop(Node* head);

    ChildNode* CloneChildList(ChildNode* head);

private:
    void RemoveLoop(struct Node *loop_node, struct Node *head);
};

