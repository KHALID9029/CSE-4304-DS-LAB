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

    int n;
    cin>>n;

    while(n--){
    string s;
    cin>>s;

    stack<char>st;

    st.push(']');
    st.push(s[s.size()-1]);

    for(int i=s.size()-2;i>=0;i--)
    {
        char x= st.top();
        if(x==s[i]) {st.pop();}
        else {st.push(s[i]);}
    }

    st.push('[');

    while(!st.empty())
    {
        cout<<st.top();
        st.pop();
    }
    cout<<endl;}
}
