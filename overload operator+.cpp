#include <iostream>
using namespace std;

class LinkedList;    // Declare for using

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
    Node(int a): BaseNode(""), data(a), next(nullptr) {};
    Node(string s, int a): BaseNode(s), data(a), next(nullptr) {};
    ~Node() = default;
    friend class LinkedList;
};

class LinkedList {
private:
    int size;            // size: the size of the Linked list
    Node *first;            // pointing to the first node of the list
public:
    LinkedList operator+(const LinkedList& other) {
        LinkedList result = *this;  // Create a new LinkedList object and copy the current list
        Node* current = other.first;

        while (current != nullptr) {
            result.Push_back(current->nodeType, current->data);  // Push each node from the other list to the result list
            current = current->next;
        }

        return result;
    }
    LinkedList(): size(0), first(nullptr) {};
    void PrintList();           // print content of all nodes in the list
    void Push_front(int x);     // add a node at the front of the list
    void Push_front(string s, int x);  // add a node at the front of the list
    void Push_back(int x);      // add a note at the rear of the list
    void Push_back(string s, int x);   // add a note at the rear of the list
    void Delete(int x);         // delete a specific nnode with content "int x"
    void Delete(string s, int x);         // delete a specific nnode with content "s and x"
    void Clear();               // delete the whole list
    void Reverse();             // reverse the list: that is, 1->2->3 => 3->2->1
};

void LinkedList::PrintList() {
    // print the constent of the list
    if (first == nullptr) {         // no data in the list
        cout << "List is empty." << endl;
        return;
    }

    Node *current = first;
    while (current != nullptr) {        // Traversing the list and print the content
        cout << current->nodeType << "(" << current->data << ") ";
        current = current->next;
    }
    cout << endl;
    cout << "List is of size " << size << endl;
}

void LinkedList::Push_front(int x) {
    // // allocate new memory for the new node
    Node *newNode = new Node(x);    // Note: the parameterized constructor is used
    newNode->next = first;
    first = newNode;
    size += 1;
}

void LinkedList::Push_front(string s, int x) {
    // // allocate new memory for the new node
    Node *newNode = new Node(s, x);    // Note: the parameterized constructor is used
    newNode->next = first;
    first = newNode;
    size += 1;
}

void LinkedList::Push_back(int x) {
    // append new data node at the rear of the list!
    Node *newNode = new Node(x);

    if (first == nullptr) {   // the case that the list is empty
        first = newNode;
    } else { // get to the last position of the list
        Node *current = first;
        while (current->next != nullptr) { // Traversing the list...
            current = current->next;
        }
        current->next = newNode;
    }
    size += 1;
}


void LinkedList::Push_back(string s, int x) {
    // append new data node at the rear of the list!
    Node *newNode = new Node(s, x);

    if (first == nullptr) {   // the case that the list is empty
        first = newNode;
    } else { // get to the last position of the list
        Node *current = first;
        while (current->next != nullptr) { // Traversing the list...
            current = current->next;
        }
        current->next = newNode;
    }
    size += 1;
}


void LinkedList::Delete(int x) {
    // delete a specific node with integer content x
    Node *current = first, *previous = nullptr;
    while (current != nullptr && current->data != x) {  // traversing
        previous = current;
        current = current->next;
    }

    if (current == nullptr) {   // either can't find the node or the list is empty
        cout << x << " is not found in list." << endl;
    } else if (current == first) {  // the node to delete is the first node of the list
        first = current->next;
        delete current;
        current = nullptr;
        size -= 1;
    } else {    // the other case:
        previous->next = current->next;
        delete current;
        current = nullptr;
        size -= 1;
    }
}

void LinkedList::Delete(string s, int x) {
    // delete a specific node with integer content x
    Node *current = first, *previous = nullptr;
    while (current != nullptr && (current->data != x || current->nodeType != s)) {  // traversing
        previous = current;
        current = current->next;
    }

    if (current == nullptr) {   // either can't find the node or the list is empty
        cout << s << " and " << x << " are not found in list." << endl;
    } else if (current == first) {  // the node to delete is the first node of the list
        first = current->next;
        delete current;
        current = nullptr;
        size -= 1;
    } else {    // the other case:
        previous->next = current->next;
        delete current;
        current = nullptr;
        size -= 1;
    }
}

void LinkedList::Clear() {
    // delete all the list by deleting nodes one by one
    while (first != nullptr) {    // Traversal
        Node *current = first;
        first = first->next;
        delete current;
        current = nullptr;
    }
    size = 0;
}

void LinkedList::Reverse() {

    if (first != nullptr && first->next != nullptr) {
        Node *previous = nullptr,
        *current = first,
        *preceding = first->next;

        while (preceding != nullptr) {
            current->next = previous;
            previous = current;
            current = preceding;
            preceding = preceding->next;
        }   // until preceding gets to nullptr

        current->next = previous;  // now current is at the last node
        first = current;  // update first to be current
    }
}

int main() {
    LinkedList list, list1, list2;
    list1.Push_back("A", 1);
    list1.Push_back("B", 2);
    list1.Push_back("C", 3);
    list2.Push_front("Z", 6);
    list2.Push_front("Y", 5);
    list2.Push_front("X", 4);
    list = list1 + list2;
    list.Delete("Z", 6);
    list.PrintList();
    return 0;
}




