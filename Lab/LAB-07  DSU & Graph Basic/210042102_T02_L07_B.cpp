#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

const int N=1e5;
const int INF=1e9+10;

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,m;
    cin>>n>>m;

    vector<vector<ll>> adj(n+1);
    vector<vector<ll>> a(n,vector<ll>(n,0));
    ll i,j;

    while(m--)
    {
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        a[u-1][v-1]=1;
        a[v-1][u-1]=1;
    }

    cout<<"List View:"<<endl;
    for(i=1;i<=n;i++)
    {
        cout<<i<<"-> ";
        for(j=0;j<adj[i].size();j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;

    cout<<"Matrix View: "<<endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

