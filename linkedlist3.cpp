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
    public:
        Node *next;
        Node() = default;
        Node(int a): BaseNode(""), data(a), next(nullptr) {};
        Node(string s, int a): BaseNode(s), data(a), next(nullptr) {};
        ~Node() = default;
        void printNode() { cout << nodeType << "(" << data << ")"; }
        friend class LinkedList;
        /* modify class Node */
};

class LinkedList {
    protected:
        int size;  // size: the size of the Linked list
        Node *first;  // pointing to the first node of the list
    public:LinkedList(): size(0), first(nullptr) {};
        void PrintList();   // print content of all nodes in the list
        void Push_front(int x);   // add a node at the front of the list
        void Push_front(string s, int x);  // add a node at the front of the list
        virtual void Push_back(int x) ;  // modify this declaration
            // add a note at the rear of the list
        virtual void Push_back(string s, int x) ; // modify this declaration
            // add a note at the rear of the list
};

class twoEndLinkedList: public LinkedList {
    private:
        Node *last;
    public:
        twoEndLinkedList(): LinkedList(), last(nullptr) {};
        void Push_back(int x);
            // override Push_back(int x) in LinkedList
        void Push_back(string s, int x);
            // override Push_back(string s, int x) in LinkedList
        void PrintLast();   // please implement this member function outside the class definition
};

void LinkedList::PrintList() {
    if (size == 0) {
        cout << "List is empty." << endl;
        return;
    }
    Node *current = first;
    while (current != nullptr) {
        current->printNode();
        cout << " ";
        current = current->next;
    }
    cout << endl << "List is of size " << size << endl;
}

void LinkedList::Push_front(int x) {
    Node *newNode = new Node(x);
    newNode->next = first;
    first = newNode;
    ++size;
}

void LinkedList::Push_front(string s, int x) {
    Node *newNode = new Node(s, x);
    newNode->next = first;
    first = newNode;
    ++size;
}

void LinkedList::Push_back(int x) {
    Node *newNode = new Node(x);
    if (size == 0) {
        first = newNode;
    } else {
        Node *current = first;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
    ++size;
}

void LinkedList::Push_back(string s, int x) {
    Node *newNode = new Node(s, x);
    if (first == nullptr) {
        first = newNode;
    } else {
        Node *curr = first;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
    size++;
}

void twoEndLinkedList::PrintLast() {
    if (last == nullptr) {
        cout << "Last node: none" << endl;
    } else {
        cout << "Last node: ";
        last->printNode();
        cout << endl;
    }
}

void twoEndLinkedList::Push_back(int x) {
    Node *newNode = new Node(x);
    if (size == 0) {
        first = newNode;
    } else {
        Node *current = first;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
    ++size;
}

void twoEndLinkedList::Push_back(string s, int x) {
    Node *newNode = new Node(s, x);
    if (first == nullptr) {
        first = newNode;
    } else {
        Node *curr = first;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
    last = newNode;
    size++;
}

int main() { // sample main()
    twoEndLinkedList list;
    list.PrintList();
    list.PrintLast();
    list.Push_back("A", 5);
    list.Push_back("B", 3);
    list.Push_front("C", 9);
    list.Push_back("D", 11);
    list.PrintList();
    list.PrintLast();
    return 0;
}
