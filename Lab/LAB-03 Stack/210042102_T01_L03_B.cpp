#include<iostream>
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

const int N=1e5;
const int INF=1e9+10;

class stack_int
{
    public:
    int *arr;
    int top;
    int capacity;

    stack_int(int capacity)
    {
        this->capacity=capacity;
        this->arr= new int[capacity];
        this->top=0;
    }

    bool isEmpty()
    {
        if(top==0) return true;
        return false;
    }

    bool isFull()
    {
        return top==capacity;
    }

    void push(int x)
    {
        if(isFull()) {cout<<"Stack is Full"<<endl;}
        else
        {

            arr[top]=x;
            top++;
        }
    }

    void pop()
    {
        if(isEmpty()) {cout<<"Stack is Empty"<<endl;}
        else
        {
            top--;
        }
    }

    void clear_stack()
    {
        top=0;
    }

    int topp()
    {
        if(isEmpty()) {cout<<"Stack is Empty"<<endl;}
        else
        {
            return arr[top-1];
        }
    }

    int topandpop()
    {
        if(isEmpty()) {cout<<"Stack is Empty"<<endl;}
        else
        {int val=topp();
        pop();
        return val;}
    }

    int Size()
    {
        return top;
    }

    void print()
    {
        if(isEmpty()) {cout<<"Stack is Empty"<<endl;return;}
        for(int i=top-1;i>=0;i--)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cout<<"Size of the array:"<<endl;
    cin>>n;
    stack_int s1(n);

    int check=0;

    while(check!=-1)
    {
        cin>>check;

        if(check==1)
        {
            cout<<"Enter the number to push:"<<endl;;
            int xx;
            cin>>xx;
            s1.push(xx);
            s1.print();
        }

        else if(check==2)
        {
            s1.pop();
            s1.print();
        }

        else if(check==3)
        {
            if(s1.isEmpty()) {cout<<"Stack is Empty"<<endl;}
            else {cout<<"Stack is not Empty"<<endl;}
        }

        else if(check==4)
        {
            if(s1.isFull()) {cout<<"Stack is Full"<<endl;}
            else {cout<<"Stack is not Full"<<endl;}
        }

        else if(check==5)
        {
            int ans=s1.Size();
            cout<<ans<<endl;
        }

        else if(check==6)
        {
            int ans=s1.topp();
            cout<<ans<<endl;
        }
    }

}

