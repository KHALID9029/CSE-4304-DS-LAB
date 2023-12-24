#include<iostream>
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

const int N=1e5;
const int INF=1e9+10;

int main()
{
    int n,i,mn=INF;
    cin>>n;

    int a[n],available[100000];
    for(i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]<mn) {mn=a[i];}
            available[a[i]]++;
        }


    //for(i=0;i<n;i++) {cout<<available[i]<<" ";} cout<<endl;

    int ans[n];
    ans[0]=mn;

    available[mn]--;


    for(i=1;i<n;i++)
    {
        if(available[mn]>0) {ans[i]=mn;available[mn]--;}
        else {mn++;i--;}
    }

    for(i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
}
