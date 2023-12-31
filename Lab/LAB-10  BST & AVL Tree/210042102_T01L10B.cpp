#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int key;
    Node *left, *right;
};


Node *newNode(int item) 
{
    Node *temp =  new Node();
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}


void inorder(Node *root) 
{
    if (root != NULL) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}


Node* insert(Node* node, int key) 
{
    if (node == NULL) return newNode(key);

    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);   

    return node;
}


bool search(Node* root, int key) 
{
    if (root == NULL)
       return false;

    if (root->key == key)
       return true;

    if (root->key < key)
       return search(root->right, key);

    return search(root->left, key);
}

int main() 
{
    Node *root = NULL;
    int key;
    while(true) 
    {
        cin >> key;
        if(key == -1) break;
        if(search(root, key-1) || search(root, key-2) || search(root, key-3) || search(root, key+1) || search(root, key+2) || search(root, key+3)) 
        {
            inorder(root);
            cout << "(Reservation failed)" << endl;
        } 
        else 
        {
            root = insert(root, key);
            inorder(root);
            cout << endl;
        }
    }
    return 0;
}