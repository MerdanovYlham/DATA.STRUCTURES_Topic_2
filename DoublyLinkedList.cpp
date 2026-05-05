#include <iostream>
using namespace std;

struct DLLNode
{
    int key;
    DLLNode *prev;
    DLLNode *next;

    DLLNode(int k)
    {
        key = k;
        prev = next = NULL;
    }
};

class DoublyLinkedList
{
private:
    DLLNode *head;

public:
    DoublyLinkedList()
    {
        head = NULL;
    }

    void push_front(int key)
    {
        DLLNode *x = new DLLNode(key);
        x->next = head;

        if (head)
            head->prev = x;

        head = x;
    }

    void push_back(int key)
    {
        DLLNode *x = new DLLNode(key);

        if (!head)
        {
            head = x;
            return;
        }

        DLLNode *temp = head;
        while (temp->next)
            temp = temp->next;

        temp->next = x;
        x->prev = temp;
    }

    DLLNode *search(int key)
    {
        DLLNode *x = head;
        while (x && x->key != key)
            x = x->next;
        return x;
    }

    void remove(int key)
    {
        DLLNode *x = search(key);
        if (!x)
            return;

        if (x->prev)
            x->prev->next = x->next;
        else
            head = x->next;

        if (x->next)
            x->next->prev = x->prev;

        delete x;
    }

    void print()
    {
        DLLNode *x = head;
        while (x)
        {
            cout << x->key << " ";
            x = x->next;
        }
        cout << endl;
    }
};