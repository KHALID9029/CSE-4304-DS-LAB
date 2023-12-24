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

void remove(ll x, TreeNode *node)
{
	if(node->left == nullptr) return;

	if(node->left->val == x)
    {
		node->left = nullptr;
		return;
	}

	if(node->right == nullptr) return;

	if(node->right->val == x)
    {
		node->right = nullptr;
		return;
	}

	remove(x, node->left);
	remove(x, node->right);
}



bool search(TreeNode *root,int val)
{
    if(root==nullptr) return false;
    if(root->val==val)
    {
        cout<<"Present, ";
        if(root->left!=nullptr) cout<<"Left"<<"("<<root->left->val<<") ";
        if(root->right!=nullptr) cout<<"Right"<<"("<<root->right->val<<") ";
        cout<<endl;
        return true;
    }
    return search(root->left,val) || search(root->right,val);
}


void print_pre_order(TreeNode *root,ll parent)
{
    if(root==nullptr) return;
    cout<<root->val<<"("<<parent<<") ";
    print_pre_order(root->left,root->val);
    print_pre_order(root->right,root->val);
}



ll h=0;

void height(TreeNode *root,ll depth)
{
    if(root==nullptr) return;
    h=max(h,depth);
    height(root->left,depth+1);
    height(root->right,depth+1);
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

    print_pre_order(&node[1],0);
    cout<<endl;

    ll x;

    while(cin>>x)
    {

        if(x==2)
        {
            cout<<"Enter the value to remove:"<<endl;
            ll val;
            cin>>val;

           remove(val,&node[1]);


                print_pre_order(&node[1],0);
                cout<<endl;
        }

        if(x==3)
        {
            cout<<"Enter the value to search:"<<endl;
            ll val;
            cin>>val;

            bool flag=search(&node[1],val);

            if(!flag) {cout<<"Not present"<<endl;}
        }

        if(x==4)
        {
            h=0;
            ll depth=0;
            height(&node[1],depth);
            cout<<h<<endl;
        }
    }
}
