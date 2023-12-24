#include<iostream>
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

const int N=1e5;
const int INF=1e9+10;

class Queue
{
    public:
    int* queue;
    int capacity;
    int front;
    int rear;

    public:
    Queue(int size)
    {
        capacity = size + 1;
        queue = new int[capacity];
        front = rear = 0;
    }


    bool isEmpty()
    {
        return front == rear;
    }

    bool isFull()
    {
        return (rear + 1) % capacity == front;
    }

    int size()
    {
        return (rear - front + capacity) % capacity;
    }

    void Enqueue(int x)
    {
        if (isFull())
        {
            cout << "Queue is full" << endl;
            return;
        }
        queue[rear] = x;
        rear = (rear + 1) % capacity;
    }

    int Dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            exit(1);
        }
        int item = queue[front];
        front = (front + 1) % capacity;
        return item;
    }

    int frontnum()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            exit(1);
        }
        int item = queue[front];
        return item;
    }

    int rearnum()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            exit(1);
        }
        int item = queue[(rear+capacity-1)%capacity ];
        return item;
    }
};

int main()
{
    Queue q(5);

    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.Enqueue(4);
    q.Enqueue(5);

    q.Enqueue(6);

    cout << "Queue size: " << q.size() << endl;
    cout<<"Front Number: "<<q.frontnum()<<endl;
    cout<<"Back number: "<<q.rearnum()<<endl;

    cout<<q.Dequeue()<<endl;
    cout<<"Front Number: "<<q.frontnum()<<endl;
    cout<<"Back number: "<<q.rearnum()<<endl;

    q.Enqueue(10);

    cout<<"Front Number: "<<q.frontnum()<<endl;
    cout<<"Back number: "<<q.rearnum()<<endl;

//    while (!q.isEmpty())
//    {
//        cout << "Dequeued: " << q.Dequeue() <<endl;
//    }

    cout << "Queue size after dequeue: " << q.size() << endl;

    return 0;
}
