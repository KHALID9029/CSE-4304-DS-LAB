#include <bits/stdc++.h>
using namespace std;

class Node 
{
public:
    int key;
    int size;
    Node *left, *right;
};


Node *newNode(int item) 
{
    Node *temp =  new Node();
    temp->key = item;
    temp->size = 1;
    temp->left = temp->right = NULL;
    return temp;
}

int size(Node* node) 
{
    if (node == NULL)
        return 0;
    else
        return node->size;
}



Node* insert(Node* node, int key) 
{
    if (node == NULL) return newNode(key);

    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);   

    node->size = 1 + size(node->left) + size(node->right);

    return node;
}


int smaller(Node* x, int key) 
{
    if (x == NULL) return 0;
    if (key < x->key)
        return smaller(x->left, key);
    else if (key > x->key)
        return 1 + size(x->left) + smaller(x->right, key);
    else
        return size(x->left);
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

void inorder(Node *root) 
{
    if (root != NULL) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

int main() 
{
    Node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 75);
    root = insert(root, 25);
    root = insert(root, 29);
    root = insert(root, 45);
    root = insert(root, 60);
    root = insert(root, 10);

    //inorder(root);
    int n;
    cin >> n;
    for(int i=0; i<n; i++) 
    {
        int key;
        cin >> key;
        cout << smaller(root, key) << endl;
    }


    
    return 0;
}