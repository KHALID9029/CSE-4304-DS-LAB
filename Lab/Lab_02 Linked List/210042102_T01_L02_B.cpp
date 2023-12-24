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

int main()
{
    LinkedList linked_list;
    int num=0;
    while(num!=8)
    {
        cout<<"- Press 1 to insert at front"<<endl;
        cout<<"- Press 2 to insert at back"<<endl;
        cout<<"- Press 3 to insert after a node"<<endl;
        cout<<"- Press 4 to update a node"<<endl;
        cout<<"- Press 5 to remove the first node"<<endl;
        cout<<"- Press 6 to remove a node"<<endl;
        cout<<"- Press 7 to remove the last node"<<endl;
        cout<<"- Press 8 to exit."<<endl;

        cin>>num;

        if(num==1)
        {
            cout<<"Enter The number to insert at front:";
            int key;
            cin>>key;
            linked_list.insert_front(key);
            linked_list.display();
        }


        else if(num==2)
        {
            cout<<"Enter The number to insert at the back:";
            int key;
            cin>>key;
            linked_list.insert_back(key);
            linked_list.display();
        }

        else if(num==3)
        {
            cout<<"Enter The value and the number:";
            int key,value;
            cin>>value>>key;
            linked_list.Insert_after_node(key,value);
            linked_list.display();
        }

        else if(num==4)
        {
            cout<<"Enter The value and the updated value:";
            int key,value;
            cin>>value>>key;
            linked_list.Update_node(key,value);
            linked_list.display();
        }

        else if(num==5)
        {
            linked_list.Remove_Head();
            linked_list.display();
        }

         else if(num==6)
        {
            cout<<"Enter The number to remove:";
            int key;
            cin>>key;
            linked_list.Remove_element(key);
            linked_list.display();
        }

        else if(num==7)
        {
            linked_list.Remove_end();
            linked_list.display();
        }
    }

    return 0;
}

