#include<iostream>
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

const int N=1e5;
const int INF=1e9+10;

int parent[N];

void make(int v)
{
    parent[v]=v;
}

int find(int v)
{
    if(v==parent[v]) return v;
    return parent[v]=find(parent[v]); //PATH COMPRESSION OPERATION
}

void Union(int a,int b)
{
    a=find(a);
    b=find(b);

    if(a!=b)
    {
        if(size[a]<size[b]) {swap(a,b);}
        parent[b]=a;
        size[a]+=size[b];
    }
}

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        //cout<<n<<" "<<q<<endl;

        int i;

        for(i=1;i<=n;i++)
        {
            int q;
            cin>>q;
            make(q);
        }

        for(i=n+1;i<100;i++)
        {
            make(i);
        }
        while(q--)
        {
            ll op;
            cin>>op;
            if(op==1)
            {
                ll x,y;
                cin>>x>>y;

                Union(x,y);

                for(i=1;i<=n;i++)
                {
                    cout<<find(i)<<" ";
                }
                cout<<endl;
            }
            else if(op==2)
            {
                ll x;
                cin>>x;
                cout<<find(x)<<endl;
            }
        }
    }
}
