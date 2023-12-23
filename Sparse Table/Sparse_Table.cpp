#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

const int N=1e5;
const int INF=1e9+10;

vector<vector<int>> sparse_table_build(vector<int> &v)
{
    int i,j,k,n=v.size();
    vector<vector<int>> sparseTable(n);

    for(i=0;i<n;i++) { sparseTable[i].push_back(v[i]); }

    for(j=0; ;j++)
    {
        k=1<<j;
        if(k>=n) break;

        for(i=0;i+2*k<=n;i++)
        {
            sparseTable[i].push_back(min(sparseTable[i][j],sparseTable[i+k][j]));
        }
    }

    return sparseTable;
}

int sparse_table_query(vector<vector<int>> &sparseTable,int l,int r)
{
    int res=INF,k;

    while(l<=r)
    {
        k=log2(r-l+1);
        res=min(res,sparseTable[l][k]);
        l+=(1<<k);
    }

    return res;
}

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}