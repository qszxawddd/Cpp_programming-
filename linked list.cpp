#include <iostream>
using namespace std;

class BaseNode {
    public:
        string nodeType;
    BaseNode() = default;
    BaseNode(string s): nodeType(s) {}
    ~BaseNode() = default;
};

class Node : public BaseNode {
    private:
        int data;
        Node *next;
    public:
        Node() = default;
        Node(int a) : data(a) {} // TO BE DONE
        Node(string s, int a) : BaseNode(s), data(a) {} // TO BE DONE
        ~Node() = default;
        // destructor TO BE DONE
        void printNode() {
            cout  << nodeType << "(" << data << ") ";
            /* print out the node¡¦s content */
        }
        friend class LinkedList;
};

class LinkedList {
    private:
        int size;            // size: the size of the Linked list
        Node *first;            // pointing to the first node of the list
    public:
        LinkedList(): size(0), first(nullptr) {};
        void PrintList();           // TBD; print content of all nodes in the list
     // add a node at the front of the list
        void Push_front(string s, int x);  // TBD; add a node at the front of the list
     // add a note at the rear of the list
        void Push_back(string s, int x);   // TBD; add a note at the rear of the list
};

void LinkedList::PrintList() {
    // print the content of the list
    if (first == nullptr) {         // no data in the list
            cout << "List is empty." << endl;
    return;}

    Node *current = first;
    while (current != nullptr) {        // Traversing the list and print the content
            /* print the current node¡¦ content */
            current->printNode();
            current = current->next;
    }
    cout << endl;
    cout << "List is of size " << size << endl;

}

void LinkedList::Push_front(string s, int x) {// // allocate new memory for the new node
    Node *newNode = new Node(s, x);    // Note: the parameterized constructor is used
    newNode->next = first;
    first = newNode;
    size++;
    /* we also need to increase the size of the list*/
}

void LinkedList::Push_back(string s, int x) {
    Node *newNode = new Node(s, x);
    if (first == nullptr) {   // the case that the list is empty
            first = newNode;
    } else { // get to the last position of the list
        Node *current = first;
        while (current->next != nullptr) { // Traversing the list...
                current = current->next;
        }current->next = newNode;
    }
    size++;
    /* we also need to increase the size of the list*/
}

int main() { // sample main()
    LinkedList list;
    list.Push_back("B", 5);
    list.Push_back("A", 3);
    list.Push_front("N", 9);
    list.PrintList();
    return 0;
}
