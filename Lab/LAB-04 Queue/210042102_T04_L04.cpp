#include<iostream>
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

const int N=1e5;
const int INF=1e9+10;

queue<int> q;
// Push into the Stack
void push_s(int x)
{
    q.push(x);
    int n = q.size();

    for (int i = 0; i < n - 1; i++)
    {
        int front = q.front();
        q.pop();
        q.push(front);
    }
}

// Removes the element on top of the stack.
void pop_s()
{
    if (!q.empty())
    {
        q.pop();
    }
}

// Get the top element.
int top_s()
{
   int x= q.front();
   return x;
}

// Return whether the stack is empty.
bool empty_s()
{
   return q.empty();
}

int main() {
    push_s(10);
    cout << top_s() << endl;
    push_s(20);
    cout << top_s() << endl;
    pop_s();
    cout << top_s() << endl;
    push_s(100);
    cout << top_s() << endl;
    cout << empty_s() << endl;
    pop_s();
    pop_s();
    cout << empty_s() << endl;
}

