#include <cstdlib>

struct TreapNode
{
    int key;
    int priority;
    TreapNode *left;
    TreapNode *right;

    TreapNode(int k)
    {
        key = k;
        priority = rand();
        left = right = NULL;
    }
};

class Treap
{
public:
    TreapNode *rotateRight(TreapNode *y)
    {
        TreapNode *x = y->left;
        TreapNode *T = x->right;

        x->right = y;
        y->left = T;

        return x;
    }

    TreapNode *rotateLeft(TreapNode *x)
    {
        TreapNode *y = x->right;
        TreapNode *T = y->left;

        y->left = x;
        x->right = T;

        return y;
    }

    TreapNode *insert(TreapNode *root, int key)
    {
        if (!root)
            return new TreapNode(key);

        if (key < root->key)
        {
            root->left = insert(root->left, key);

            if (root->left->priority > root->priority)
                root = rotateRight(root);
        }
        else
        {
            root->right = insert(root->right, key);

            if (root->right->priority > root->priority)
                root = rotateLeft(root);
        }

        return root;
    }

    bool search(TreapNode *root, int key)
    {
        if (!root)
            return false;

        if (root->key == key)
            return true;

        if (key < root->key)
            return search(root->left, key);
        else
            return search(root->right, key);
    }

    TreapNode *deleteNode(TreapNode *root, int key)
    {
        if (!root)
            return NULL;

        if (key < root->key)
            root->left = deleteNode(root->left, key);

        else if (key > root->key)
            root->right = deleteNode(root->right, key);

        else
        {
            if (!root->left)
            {
                TreapNode *temp = root->right;
                delete root;
                return temp;
            }
            else if (!root->right)
            {
                TreapNode *temp = root->left;
                delete root;
                return temp;
            }

            if (root->left->priority > root->right->priority)
            {
                root = rotateRight(root);
                root->right = deleteNode(root->right, key);
            }
            else
            {
                root = rotateLeft(root);
                root->left = deleteNode(root->left, key);
            }
        }

        return root;
    }
};