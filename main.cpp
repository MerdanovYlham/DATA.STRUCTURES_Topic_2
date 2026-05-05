#include <iostream>
using namespace std;

#include "BinaryHeap.cpp"
#include "DoublyLinkedList.cpp"
#include "Treap.cpp"

int main()
{

    // HEAP
    BinaryHeap h(10);
    h.insert(10);
    h.insert(50);
    h.insert(20);
    cout << "Max: " << h.extractMax() << endl;

    // DLL
    DoublyLinkedList dll;
    dll.push_back(1);
    dll.push_back(2);
    dll.push_front(0);
    dll.print();

    // TREAP
    Treap t;
    TreapNode *root = NULL;

    root = t.insert(root, 50);
    root = t.insert(root, 30);
    root = t.insert(root, 70);

    cout << "Search 30: " << t.search(root, 30) << endl;

    root = t.deleteNode(root, 30);

    cout << "Search 30 after delete: " << t.search(root, 30) << endl;

    return 0;
}