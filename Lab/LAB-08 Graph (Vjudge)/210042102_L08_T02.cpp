#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

vector<int>adj[100001];
int vis[100001];
bool catp[100001];
int mxcat,ans;

void dfs(int u,int cat)
{
    if(catp[u]) cat++;
    else cat=0;

    if(cat>mxcat) return;

    vis[u]=1;

    if(adj[u].size()==1 && u!=1) ans++;

    for(int v:adj[u])
    {
        if(!vis[v]) dfs(v,cat);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    int i;

    for(i=1;i<=n;i++) {cin>>catp[i];}

    for(i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    mxcat=m;
    dfs(1,0);

    cout<<ans<<endl;
}