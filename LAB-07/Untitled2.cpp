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

    ll t;
    cin>>t;
    while(t--)
    {
        int t;
        cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        stack<char> st;
        for (char c : s)
        {
            if (!st.empty() && st.top() != c)
            {
                st.pop();
            }
            else
            {
                st.push(c);
            }
        }
        cout << st.size() << endl;
    }

    }
}
