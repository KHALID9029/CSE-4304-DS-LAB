#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

const int N=1e5;
const int INF=1e9+10;

struct node
{
    int data;
    node *left;
    node *right;
    int height=1;
};

class AVL
{
    private:
    node *root;

    public:
    AVL()
    {
        root=NULL;
    }

    int getheight(node *cur)
    {
        if(cur==NULL)
            return 0;
        return cur->height;
    }

    int getbalancefactor(node *cur)
    {
        if(cur==NULL)
            return 0;
        return getheight(cur->left)-getheight(cur->right);
    }

    node *leftrotate(node *A)
    {
        node *B=A->left;
        node *T2=B->right;

        A->left=T2;
        B->right=A;

        A->height=max(getheight(A->left),getheight(A->right))+1;
        B->height=max(getheight(B->left),getheight(B->right))+1;

        return B;
    }

    node *rightrotate(node *A)
    {
        node *B=A->right;
        node *T2=B->left;

        A->right=T2;
        B->left=A;

        A->height=max(getheight(A->left),getheight(A->right))+1;
        B->height=max(getheight(B->left),getheight(B->right))+1;

        return B;
    }

    void insert(int val)
    {
        root=insert(root,val);
    }

    node *insert(node *cur,int val)
    {
        if(cur==NULL)
        {
            node *temp=new node;
            temp->data=val;
            temp->left=NULL;
            temp->right=NULL;
            return temp;
        }

        if(val<cur->data)
            cur->left=insert(cur->left,val);
        else
            cur->right=insert(cur->right,val);
        

        cur->height=max(getheight(cur->left),getheight(cur->right))+1;

        int balance=getbalancefactor(cur);

        if(balance>1 && val<cur->left->data) //LL condition
        {
            cur=leftrotate(cur);
        }

        else if(balance>1   && cur->left->data<val)  //LR condition
        {
            cur->left=leftrotate(cur->left);
            cur=rightrotate(cur);
        }

        else if(balance<-1 && val>cur->right->data) //RR condition
        {
            cur=rightrotate(cur);
        }

        else if(balance<-1 && val<cur->right->data) //RL condition
        {
            cur->left=rightrotate(cur->right);
            cur=rightrotate(cur);
        }

        return cur;
    
    }

    node *search(int val)
    {
        node *cur=root;
        while(cur!=NULL)
        {
            if(cur->data==val)
                return cur;
            else if(cur->data>val)
                cur=cur->left;
            else
                cur=cur->right;
        }
    }

    void delete_node(int val)
    {
        root=delete_node(root,val);
    }

    node *delete_node(node *cur,int val)
    {
        if(cur==NULL)
            return cur;
        
        else if(cur->data> val)
        {
            cur->left=delete_node(cur->left,val);
        }

        else if(cur->data<val)
        {
            cur->right=delete_node(cur->right,val);
        }

        else if(cur->left!=nullptr && cur->right!=nullptr)
        {
            node *trv=cur->left;
            while(trv->right!=NULL)
                trv=trv->right;

            cur->data=trv->data;
            cur->left=delete_node(cur->left,trv->data);
        }

        else
        {
            if(cur->left==  nullptr && cur->right==nullptr)
            {
                node *temp=cur;
                return NULL;
                delete temp;
            }

            else if(cur->left != nullptr)
            {
                node *temp=cur->left;
                cur->left=NULL;
                delete temp;
            }

            else
            {
                node *temp=cur->right;
                cur->right=NULL;
                delete temp;
            }
        }

        cur->height=max(getheight(cur->left),getheight(cur->right))+1;
        int balancefactor=getbalancefactor(cur);

        if(balancefactor<-1)
        {
            int balance=getbalancefactor(cur->right);

            if(balance<=0) {cur=rightrotate(cur);}
            else
            {
                cur->right=leftrotate(cur->right);
                cur=rightrotate(cur);
            }
        }

        else if(balancefactor>1)
        {
            int balance=getbalancefactor(cur->left);

            if(balance>=0) {cur=leftrotate(cur);}
            else
            {
                cur->left=rightrotate(cur->left);
                cur=leftrotate(cur);
            }
        }

        return cur;
    }

    void printnode(node *cur)
    {
        if(cur==NULL)
            return;
        cout<<cur->data<<" ";
        printnode(cur->left);
        printnode(cur->right);
    }
};

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


}