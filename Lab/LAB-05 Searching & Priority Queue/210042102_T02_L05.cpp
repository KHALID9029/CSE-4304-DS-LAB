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

    int n,k;
    cin>>n>>k;
    priority_queue<int,vector<int>,greater<int>>pq;

    int sum=0;
    while(n--)
    {
        int x;
        cin>>x;
        pq.push(x);
        sum+=x;
        //cout<<pq.top()<<endl;
    }

    int ans=0;

    if(sum<k) {cout<<-1<<endl;}
    else
    {
        while(pq.top()<k)
         {
        int x=pq.top();
        //cout<<x<<endl;
        pq.pop();
        int y= pq.top();
        pq.pop();
        //cout<<y<<endl;

        int in=x+2*y;
        //cout<<in<<endl;

        pq.push(in);
        ans++;
        //cout<<pq.top()<<endl;
          }

       cout<<ans<<endl;
    }

}


