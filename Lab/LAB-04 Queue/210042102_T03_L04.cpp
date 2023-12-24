#include<iostream>
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

const int N=1e5;
const int INF=1e9+10;

queue<int>q;
int ping(int t)
{
    // YOUR CODE HERE
    while(!q.empty() && q.front()<t-3000)
    {
        q.pop();
    }

    q.push(t);

    return q.size();
}

int main()
{
    cout << ping(1) << "\n";
    cout << ping(2) << "\n";
    cout << ping(3) << "\n";
    cout << ping(4) << "\n";
    cout << ping(3001) << "\n";
    cout << ping(3002) << "\n";
    cout << ping(3003) << "\n";
    cout << ping(6003) << "\n";
    cout << ping(10003) << "\n";

    return 0;
}

