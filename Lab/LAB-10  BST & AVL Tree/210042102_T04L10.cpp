#include <iostream>
#include<bits/stdc++.h>
#include <algorithm>
using namespace std;

class AVLTree 
{
private:
    struct Node 
    {
        int data;
        Node* left;
        Node* right;
        int height;

        Node(int value) : data(value), left(nullptr), right(nullptr), height(0) {}
    };

    Node* root;

    int height(Node* node) 
    {
        if (node == nullptr) return 0;
        return node->height;
    }

    int getBalanceFactor(Node* node) 
    {
        if (node == nullptr) return 0;
        return height(node->left) - height(node->right);
    }

    Node* rightRotate(Node* y) 
    {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = 1 + max(height(y->left), height(y->right));
        x->height = 1 + max(height(x->left), height(x->right));

        return x;
    }

    Node* leftRotate(Node* x) 
    {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = 1 + std::max(height(x->left), height(x->right));
        y->height = 1 + std::max(height(y->left), height(y->right));

        return y;
    }

    Node* insertNode(Node* node, int value) 
    {
        if (node == nullptr) return new Node(value);

        if (value < node->data)
            node->left = insertNode(node->left, value);
        else if (value > node->data)
            node->right = insertNode(node->right, value);
        else
            return node; 

        node->height = 1 + std::max(height(node->left), height(node->right));

        int balance = getBalanceFactor(node);

        if (balance > 1 && value < node->left->data) // Left Left Case
            return rightRotate(node);

        if (balance < -1 && value > node->right->data) // Right Right Case
            return leftRotate(node);

        if (balance > 1 && value > node->left->data) { // Left Right Case
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && value < node->right->data) { // Right Left Case
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void inorderTraversal(Node* node) 
    {
        if (node != nullptr) {
            inorderTraversal(node->left);
            std::cout << node->data << "(" << node->height << ") ";
            inorderTraversal(node->right);
        }
    }

    
public:
    AVLTree() : root(nullptr) {}

    void insert(int value) {
        root = insertNode(root, value);
    }

    void inorderTraversal() {
        inorderTraversal(root);
        std::cout << std::endl;
    }

    int second_largest()
    {
        Node *cur=root;
        while(cur->right->right!=NULL)
            cur=cur->right;
        return cur->data;
    }

    void find_path(int x,int y)
    {
        Node *cur=root;
        vector<int> path;
        while(cur->data!=x)
        {
            path.push_back(cur->data);
            if(cur->data>x)
                cur=cur->left;
            else
                cur=cur->right;
        }
        path.push_back(cur->data);
        cur=root;
        vector<int> path2;
        while(cur->data!=y)
        {
            path2.push_back(cur->data);
            if(cur->data>y)
                cur=cur->left;
            else
                cur=cur->right;
        }
        path2.push_back(cur->data);
        vector<int>ans;
        int i=0;
        while(i<path.size() && i<path2.size() && path[i]==path2[i])
            i++;
        for(int j=path.size()-1;j>=i;j--)
            ans.push_back(path[j]);
        
        ans.push_back(path[i-1]);
        for(int j=i;j<path2.size();j++)
            ans.push_back(path2[j]);
        
        for(auto x:ans)
            cout<<x<<" ";
        cout<<endl;
        cout<<ans.size()<<endl;
    }
};

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    AVLTree tree;
    int n;
    while(1)
    {
        cin>>n;
        if(n==-1)
            break;
        tree.insert(n);
    }

    cout<<"Status: ";
    tree.inorderTraversal();

    int q;
    cin>>q;
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        tree.find_path(x,y);
    }
}