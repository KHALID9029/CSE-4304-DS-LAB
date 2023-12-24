#include<iostream>
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

const int N=1e5;
const int INF=1e9+10;

class Node
{
    public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList
{
    private:
    Node* head;

    public:
    LinkedList() : head(nullptr) {}

    void insert(int val)
    {
        Node* new_node = new Node(val);
        if (!head)
        {
            head = new_node;
        }
        else
        {
            Node* current = head;
            while (current->next)
            {
                current = current->next;
            }
            current->next = new_node;
        }
    }

    void remove_duplicates()
    {
        if (!head)
        {
            return;
        }

        Node* current = head;
        while (current)
        {
            Node* runner = current;
            while (runner->next)
            {
                if (runner->next->data == current->data)
                {
                    Node* temp = runner->next;
                    runner->next = temp->next;
                    delete temp;
                }
                else
                {
                    runner = runner->next;
                }
            }
            current = current->next;
        }
    }

    void print()
    {
        Node* current = head;
        while (current)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    ~LinkedList()
    {
        Node* current = head;
        while (current)
        {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main()
{
    LinkedList list;

    int val;
    while (true)
    {
        cin >> val;
        if (val == -1)
        {
            break;
        }
        list.insert(val);
    }

    list.remove_duplicates();
    list.print();

    return 0;
}

