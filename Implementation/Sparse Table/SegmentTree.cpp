#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

const int N=1e5;
const int INF=1e9+10;

int arr[N+10];
int tree[4*N+10];

void Build(int node,int l,int r)
{
    if(l==r)
    {
        tree[node]=arr[l];
        return;
    }

    int left=2*node;
    int right=2*node+1;
    int mid=(l+r)/2;

    Build(left,l,mid);
    Build(right,mid+1,r);

    tree[node]=tree[left]+tree[right]; // sum
    // Change this line for other problems
}

int query(int node,int l,int r,int i,int j)
{
    if(i>r || j<l) return 0; // sum // Change this line for other problems
    if(i<=l && j>=r) return tree[node];

    int left=2*node;
    int right=2*node+1;
    int mid=(l+r)/2;

    int p1=query(left,l,mid,i,j);
    int p2=query(right,mid+1,r,i,j);

    return p1+p2; // sum // Change this line for other problems 
}

void update(int node,int l,int r,int idx,int val)
{
    if(idx>r || idx<l) return;
    if(l==r)
    {
        tree[node]=val;
        return;
    }

    int left=2*node;
    int right=2*node+1;
    int mid=(l+r)/2;

    update(left,l,mid,idx,val);
    update(right,mid+1,r,idx,val);

    tree[node]=tree[left]+tree[right]; // sum
    // Change this line for other problems
}

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];

    Build(1,1,n);
}