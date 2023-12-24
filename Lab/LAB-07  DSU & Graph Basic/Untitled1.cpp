#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int k=1;k<=n-i;k++) {cout<<" ";}
        int j=(2*i)-1;
        for(int k=1;k<=j;k++)
        {
            if(k%2==1)
            {
                cout<<"X ";
            }
            else
            {
                cout<<" ";
            }
        }
        cout<<endl;
    }
}
