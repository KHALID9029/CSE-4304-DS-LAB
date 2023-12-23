#include<iostream>
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

const int N=1e5;
const int INF=1e9+10;

class Queue
{
    public:
    struct Node
    {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };

    Node* frontPtr;
    Node* backPtr;
    int size;

    public:
    Queue() : frontPtr(nullptr), backPtr(nullptr), size(0) {}


    bool isEmpty()
    {
        return size == 0;
    }


    int getSize()
    {
        return size;
    }


    void push(int val)
    {
        Node* newNode = new Node(val);
        if (isEmpty())
        {
            frontPtr = newNode;
            backPtr = newNode;
        }
        else
        {
            backPtr->next = newNode;
            backPtr = newNode;
        }
        size++;
    }


    void pop()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }

        Node* temp = frontPtr;
        frontPtr = frontPtr->next;
        delete temp;
        size--;
    }


    int front()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            exit(1);
        }
        return frontPtr->data;
    }
};

int main()
{
    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front of the queue: " << q.front() << endl;
    cout << "Queue size: " << q.getSize() << endl;

    q.pop();
    cout << "Front of the queue after dequeue: " << q.front() << endl;

    return 0;
}
