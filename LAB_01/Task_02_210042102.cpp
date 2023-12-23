#include<iostream>
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

    int n,target;
    cin>>n>>target;
    int i,a[n],available[100000],pos[100000];

    for(i=0;i<n;i++)
    {
        cin>>a[i];
        available[a[i]]++;
        pos[a[i]]=i;
    }

    int ans=0,pos1,pos2;
    for(i=0;i<n;i++)
    {
        int x=target-a[i];
        int check=pos[x];

        if(available[x] && check!=i)
        {
            ans++;
            pos2=pos[x];
            pos1=i;
        }
    }

    if(ans)
    {
        cout<<pos1<<" "<<pos2<<endl;
        cout<<ans/2<<endl;
    }
    else
    {
        cout<<"NO SUCH PAIRS"<<endl;
    }
}
