#include <iostream>
#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

const int N = 1e5;
const int INF = 1e9 + 10;

class Queue
{
    public:
    struct Node
    {
        int data;
        Node* next;
        Node* prev;
        Node(int val) : data(val), next(nullptr), prev(nullptr) {}
    };

    Node* frontPtr;
    Node* backPtr;
    int size;
    int maxSize;

    public:
    Queue(int n) : frontPtr(nullptr), backPtr(nullptr), size(0), maxSize(n) {}

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return size == maxSize;
    }

    int getSize()
    {
        return size;
    }

    void pushRight(int val)
    {
        if (!isFull())
        {
            Node* newNode = new Node(val);
            if (isEmpty())
            {
                frontPtr = newNode;
                backPtr = newNode;
            }
            else
            {
                newNode->prev = backPtr;
                backPtr->next = newNode;
                backPtr = newNode;
            }
            size++;
            cout << "Pushed in Right: " << val << endl;
        }
        else
        {
            cout << "The Queue is Full" << endl;
        }
    }

    void pushLeft(int val)
    {
        if (!isFull())
        {
            Node* newNode = new Node(val);
            if (isEmpty())
            {
                frontPtr = newNode;
                backPtr = newNode;
            }
            else
            {
                newNode->next = frontPtr;
                frontPtr->prev = newNode;
                frontPtr = newNode;
            }
            size++;
            cout << "Pushed in left: " << val << endl;
        }
        else
        {
            cout << "The Queue is Full" << endl;
        }
    }


    void popLeft()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }

        Node* temp = frontPtr;
        int x = frontPtr->data;
        frontPtr = frontPtr->next;

        if (frontPtr)
        {
            frontPtr->prev = nullptr;
        }
        else
        {
            backPtr = nullptr;
        }
        delete temp;
        size--;
        cout << "Popped from left: " << x << endl;
    }

    void popRight()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }

        Node* temp = backPtr;
        int x = backPtr->data;
        backPtr = backPtr->prev;

        if (backPtr)
        {
            backPtr->next = nullptr;
        }
        else
        {
            frontPtr = nullptr;
        }
        delete temp;
        size--;
        cout << "Popped from Right: " << x << endl;
    }
};

int main() {
    int t;
    int i;
    cin >> t;

    for (i = 1; i <= t; i++) {
        cout << "Case:" << i << endl;

        int n, m;
        cin >> n >> m;

        Queue q(n);

        while (m--) {
            string s;
            cin >> s;

            if (s == "pushLeft") {
                int x;
                cin >> x;
                q.pushLeft(x);
            } else if (s == "pushRight") {
                int x;
                cin >> x;
                q.pushRight(x);
            } else if (s == "popRight") {
                q.popRight();
            } else if (s == "popLeft") {
                q.popLeft();
            }
        }
    }

    return 0;
}
