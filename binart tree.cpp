// C++ program to insert element in Binary Tree
#include <iostream>
#include <queue>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* CreateNode(int data)
{
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Memory error\n";
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert element in binary tree
Node* InsertNode(Node* root, int data)
{
    // If the tree is empty, assign new node address to root
    if (root == NULL) {
        root = CreateNode(data);
        return root;
    }

    // Else, do level order traversal until we find an empty
    // place, i.e. either left child or right child of some
    // node is pointing to NULL.
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp->left != NULL)
            q.push(temp->left);
        else {
            temp->left = CreateNode(data);
            return root;
        }

        if (temp->right != NULL)
            q.push(temp->right);
        else {
            temp->right = CreateNode(data);
            return root;
        }
    }
}

struct Node* deletion(struct Node* root, int key)
{
    if (root == NULL)
        return NULL;
    if (root->left == NULL && root->right == NULL) {
        if (root->data == key)
            return NULL;
        else
            return root;
    }
    Node* key_node = NULL;
    Node* temp;
    Node* last;
    queue<Node*> q;
    q.push(root);
    // Do level order traversal to find deepest
    // node(temp), node to be deleted (key_node)
    // and parent of deepest node(last)
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        if (temp->data == key)
            key_node = temp;
        if (temp->left) {
            last = temp; // storing the parent node
            q.push(temp->left);
        }
        if (temp->right) {
            last = temp; // storing the parent node
            q.push(temp->right);
        }
    }
    if (key_node != NULL) {
        key_node->data
            = temp->data; // replacing key_node's data to
                          // deepest node's data
        if (last->right == temp)
            last->right = NULL;
        else
            last->left = NULL;
        delete (temp);
    }
    return root;
}

/* Inorder traversal of a binary tree */

void inorder(Node* temp)
{
    if (temp == NULL)
        return;

    inorder(temp->left);
    cout << temp->data << ' ';
    inorder(temp->right);
}

// Driver code
int main()
{
    Node* root = CreateNode(10);
    root->left = CreateNode(11);
    root->left->left = CreateNode(7);
    root->right = CreateNode(9);
    root->right->left = CreateNode(15);
    root->right->right = CreateNode(8);

    cout << "Inorder traversal before insertion: ";
    inorder(root);
    cout << endl;

    int key = 12;
    root = InsertNode(root, key);

    cout << "Inorder traversal after insertion: ";
    inorder(root);


    key = 11;
    root = deletion(root, key);

    cout << endl;
    cout << "Inorder traversal after deletion : ";
    inorder(root);

    return 0;
}
