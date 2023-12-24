#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

const int N=1e5;
const int INF=1e9+10;

class node
{
    public:
    bool isEnd;
    node* edge[26];
    public:
    node()
    {
        isEnd=false;
        for(int i=0;i<26;i++)
            edge[i]=NULL;
    }
};

void insert(node* root,string s, int idx)
{
    if(s[idx]=='\0')
    {
        root->isEnd=true;
        return;
    }

    int edgeIdx=s[idx]-'a';
    if(root->edge[edgeIdx]==NULL)
        root->edge[edgeIdx]=new node();

    insert(root->edge[edgeIdx],s,idx+1);
}

bool search(node* root,string s,int idx)
{
    if(s[idx]=='\0')
        return root->isEnd;

    int edgeIdx=s[idx]-'a';
    if(root->edge[edgeIdx]==NULL)
        return false;

    return search(root->edge[edgeIdx],s,idx+1);
}

void remove(node* root,string s,int idx)
{
    if(s[idx]=='\0')
    {
        root->isEnd=false;
        return;
    }

    int edgeIdx=s[idx]-'a';
    if(root->edge[edgeIdx]==NULL)
        return;

    remove(root->edge[edgeIdx],s,idx+1);
}


int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    puts("ENTER NUMBER OF WORDS");
    node *root = new node();
    int num_word;
    cin >> num_word;
    for (int i = 1; i <= num_word; i++) 
    {
        string str;
        cin>>str;
        insert(root,str,0);
    }

    puts("ENTER NUMBER OF QUERY");
    int query;
    cin >> query;

    for (int i = 1; i <= query; i++) 
    {
        string str;
        cin>>str;
        if (search(root, str, 0))
            puts("FOUND");
        else
            puts("NOT FOUND");
    }
}