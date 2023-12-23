#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

const int N=1e5;
const int INF=1e9+10;

int dx[]={1,0,-1,0,-1,1,1,-1};
int dy[]={0,1,0,-1,1,1,-1,-1};
char a[105][105];
int vis[105][105];

ll m,n;

bool canReach(ll x, ll y)
{
    if(x >= 0 && x < m && y >= 0 && y < n && a[x][y] != '*' && vis[x][y]==0)
    {
        return true;
    }
    return false;
}

void dfs(ll x, ll y)
{ 
    vis[x][y]=1;
    
    //cout<<x<<" "<<y<<" "<<"\n";

    for(ll i = 0; i < 8; i++)
    {
        ll mx = x + dx[i];
        ll ny = y + dy[i];
        if(canReach(mx, ny))
        {
            dfs(mx,ny);
        }
    }
}

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>m>>n;
    while(m!=0 && n!=0)
    {
        memset(vis,0,sizeof(vis));
        ll i,j;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                cin>>a[i][j];
            }
        }

        ll ans=0;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(a[i][j]=='@' && vis[i][j]==0)
                {
                    dfs(i,j);
                    ans++;
                }
            }
        }
        cout<<ans<<"\n";
        cin>>m>>n;
    }
}