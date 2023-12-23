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

void printPaths(TreeNode *root, vector<ll>& path, ll pathLength)
{
    if (root == nullptr) {return;}

    path.push_back(root->val);
    pathLength++;


    if (root->left == nullptr && root->right == nullptr)
    {
        cout << "Path: ";
        for (int i = 0; i < path.size(); i++)
        {
            cout << path[i];
            if (i < path.size() - 1)
            {
               cout << " ";
            }
        }
        cout << " Length: " << pathLength << endl;
    }
    else
    {
        printPaths(root->left, path, pathLength);
        printPaths(root->right, path, pathLength);
    }

    path.pop_back();
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

    vector<ll>path;
    ll pathlength=0;

    printPaths(&node[1],path,pathlength);
}
