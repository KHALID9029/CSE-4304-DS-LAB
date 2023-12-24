#include<iostream>
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

const int N=1e5;
const int INF=1e9+10;

class Node
{
    public:
    int key;
    Node* next;

    Node(int value) : key(value), next(nullptr) {}
};

class LinkedList
{
    public:
    Node* head;
    Node* tail;

    LinkedList() : head(nullptr) {}

    void insert_front(int key)
    {
        Node* new_node = new Node(key);
        new_node->next = head;
        head = new_node;
    }


    void insert_back(int key)
    {
        auto *ptr=head;

        while(ptr!=NULL)
        {
            tail=ptr;
            ptr = ptr->next;
        }
        Node* new_node=new Node(key);
        tail->next=new_node;
        tail=new_node;
    }

    void Insert_after_node(int key,int v)
    {
        auto *ptr=head;
        Node *vptr=NULL;

        while(ptr!=NULL)
        {
            if(ptr->key==v)
            {
                vptr=ptr;
                break;
            }
            ptr = ptr->next;
        }
        if(vptr==NULL) {cout<<"The value does not exists"<<endl;}
        else
        {
        Node* new_node=new Node(key);
        Node* next_vptr=vptr->next;
        vptr->next=new_node;
        new_node->next=next_vptr;
        }
    }


    void Update_node(int key,int v)
    {
        auto *ptr=head;
        Node *vptr=NULL;

        while(ptr!=NULL)
        {
            if(ptr->key==v)
            {
                vptr=ptr;
                break;
            }
            ptr = ptr->next;
        }
        if(vptr==NULL) {cout<<"The value does not exists"<<endl;}
        else
        {
            vptr->key=key;
        }
    }

    void Remove_Head()
    {
        auto *ptr=head;
        Node *second=head->next;

        head=second;
         ptr=NULL;
    }

    void Remove_element(int key)
    {
        auto *ptr=head;
        Node *vptr=NULL;
        Node *preptr;

        if(head->key==key)
        {
            Node *second=head->next;
            head=second;
            ptr=NULL;
        }

        else {
        while(ptr!=NULL)
        {
            if(ptr->key==key)
            {
                vptr=ptr;
                break;
            }
            preptr=ptr;
            ptr = ptr->next;
        }
        if(vptr==NULL) {cout<<"The value does not exists"<<endl;}
        else
        {
            Node* vptr_Next=vptr->next;
            preptr->next=vptr_Next;
            vptr=NULL;
        }
        }
    }

    void Remove_end()
    {
        auto *ptr=head;
        Node* preptr=NULL;

        if(!head) {cout<<"List Empty"<<endl;return;}

        if(!head->next)
        {
            Remove_Head();
            return;
        }

        while(ptr->next!=NULL)
        {
            preptr=ptr;
            ptr = ptr->next;
        }

        preptr->next=NULL;
        ptr=NULL;
    }

    void display()
    {
        Node* current = head;
        while (current)
        {
            cout << current->key << " -> ";
            current = current->next;
        }
       cout << "End" << endl;
    }
};

class stack_int
{
    LinkedList List;
    Node *top;
    stack_int()
    {
        top=NULL;
    }

    bool isEmpty()
    {
        if(top==NULL) {return true;}
        return false;
    }

    bool isFull()
    {
        return false;
    }

    void push(int x)
    {
        List.insert_front(x);
        top=List.head;
    }

    void pop()
    {
        if(isEmpty()) {cout<<"Stack is Empty"<<endl;}
        else
        {
            List.Remove_Head();
            top=List.head;
        }
    }

    void clear_stack()
    {
        top=NULL;
    }

    int topp()
    {
        if(isEmpty()) {cout<<"Stack is Empty"<<endl;}
        else return top->key;
    }

    int topandpop()
    {
        if(isEmpty()) {cout<<"Stack is Empty"<<endl;}
        else
        {
            int val=topp();
            pop();
            return val;
        }
    }

    void print()
    {
        List.display();
    }
};

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    stack_int s1();
    s1.print();

    s1.push(1);
    s1.print();
}
