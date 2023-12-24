#include<iostream>
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

const int N=1e5;
const int INF=1e9+10;

bool check_validity(string s)
{
    int si=s.size();
    if(s[0]==')'||s[0]=='}'||s[0]==']') return false;

    stack<char>st;

    for(auto e:s)
    {
        //cout<<e<<endl;
        if(e=='('||e=='{'||e=='[')
            {
                st.push(e);
            }


            if(e==')')
            {
                if(st.empty()) return false;
                char check=st.top();
                if(check!='(') return false;
                else {st.pop();}
            }


            if(e=='}')
            {
                if(st.empty()) return false;
                char check=st.top();
                if(check!='{') return false;
                else {st.pop();}
            }


            if(e==']')
            {
                if(st.empty()) return false;
                char check=st.top();
                if(check!='[') return false;
                else {st.pop();}
            }

    }

    if(st.size()>0) return false;
    return true;
}
int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t;
    cin>>t;
    cin.ignore();
    string s;
    while(t--)
    {
        getline(cin,s);
        cout<<s<<endl;
        //cout<<s.size()<<endl;
        bool flag=check_validity(s);

        if(flag) {cout<<"YES"<<endl;}
        else {cout<<"NO"<<endl;}
    }
}
