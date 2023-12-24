#include<iostream>
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

const int N=1e5;
const int INF=1e9+10;

class TreeNode
{
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void insert(vector<TreeNode>&node, ll val, ll parent, ll key)
{
    if(key==1)
    {
        node[parent].left = &node[val];
    }
    else
    {
        node[parent].right = &node[val];
    }
}

void pre_order(TreeNode *root,ll parent)
{
    if(root==nullptr) return;
    cout<<root->val<<"("<<parent<<") ";
    pre_order(root->left,root->val);
    pre_order(root->right,root->val);
}

void in_order(TreeNode *root,ll parent)
{
    if(root==nullptr) return;

    in_order(root->left,root->val);
    cout<<root->val<<"("<<parent<<") ";
    in_order(root->right,root->val);
}

void post_order(TreeNode *root,ll parent)
{
    if(root==nullptr) return;

    post_order(root->left,root->val);
    post_order(root->right,root->val);
    cout<<root->val<<"("<<parent<<") ";
}

void level_Order(TreeNode *root)
{
    if (root == nullptr) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode* current = q.front();
        cout << current->val << " ";

        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);

        q.pop();
    }
}


int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,i;
    cin>>n;
    vector<TreeNode> node(n+1);

    vector<ll>parent(n+1);

    for(i=1;i<=n;i++)
    {
        node[i]=TreeNode(i);
    }

    while(n--)
    {
        ll val, par, key;
        cin>>val>>par>>key;
        parent[key]=par;
        insert(node,val,par,key);
    }

    in_order(&node[1],0);
    cout<<endl;
    pre_order(&node[1],0);
    cout<<endl;
    post_order(&node[1],0);
    cout<<endl;
    level_Order(&node[1]);
    cout<<endl;
}
