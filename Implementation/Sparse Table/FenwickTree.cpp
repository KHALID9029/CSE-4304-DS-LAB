#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

const int N=1e5;
const int INF=1e9+10;

class FenwickTree
{
    vector<int> fenwickTree;

    public:
    FenwickTree(vector<int> &v)
    {
        int i,n=v.size();
        fenwickTree.resize(n+1);

        for(i=0;i<n;i++)
        {
            fenwickTree[i+1]=v[i];
        }

        for(i=1;i<=n;i++)
        {
            int j=i+(i&(-i));
            if(j<=n) fenwickTree[j]+=fenwickTree[i];
        }
    }

    void update(int idx,int val)
    {
        int n=fenwickTree.size()-1;

        while(idx<=n)
        {
            fenwickTree[idx]+=val;
            idx+=(idx&(-idx));
        }
    }

    int query(int idx)
    {
        int res=0;

        while(idx>0)
        {
            res+=fenwickTree[idx];
            idx-=(idx&(-idx));
        }

        return res;
    }

    int query(int l,int r)
    {
        return query(r)-query(l-1);
    }
};
int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

