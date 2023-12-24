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
    Node* prev;

    Node(int k) : key(k), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList
{
    private:
    Node* head;
    Node* tail;

    public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void insert_front(int key)
    {
        Node* new_node = new Node(key);
        if (!head)
        {
            head = tail = new_node;
        }
        else
        {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
    }

    void insert_back(int key)
    {
        Node* new_node = new Node(key);
        if (!tail)
        {
            head = tail = new_node;
        }
        else
        {
            new_node->prev = tail;
            tail->next = new_node;
            tail = new_node;
        }

    }

    void insert_after_node(int key, int v)
    {
        Node* new_node = new Node(key);
        Node* current = head;
        while (current)
        {
            if (current->key == v)
            {
                new_node->prev = current;
                new_node->next = current->next;
                if (current->next)
                {
                    current->next->prev = new_node;
                }
                else
                {
                    tail = new_node;
                }
                current->next = new_node;

                return;
            }
            current = current->next;
        }
        cout << "Node with value " << v << " not found." <<endl;
    }

    void update_node(int key, int v)
    {
        Node* current = head;
        while (current)
        {
            if (current->key == v)
            {
                current->key = key;

                return;
            }
            current = current->next;
        }
        cout << "Node with value " << v << " not found." << endl;
    }

    void remove_head()
    {
        if (!head)
        {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head)
        {
            head->prev = nullptr;
        }
        else
        {
            tail = nullptr;
        }
        delete temp;

    }

    void remove_element(int key)
    {
        if (!head)
        {
            cout << "List is empty." << endl;
            return;
        }
        if (head->key == key)
        {
            remove_head();
            return;
        }
        Node* current = head;
        while (current->next)
        {
            if (current->next->key == key)
            {
                Node* temp = current->next;
                current->next = temp->next;
                if (temp->next)
                {
                    temp->next->prev = current;
                }
                else
                {
                    tail = current;
                }
                delete temp;

                return;
            }
            current = current->next;
        }
        cout << "Node with key " << key << " not found." << endl;
    }

    void remove_end()
    {
        if (!tail)
        {
            cout << "List is empty." << endl;
            return;
        }
        if (!tail->prev)
        {
            remove_head();
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;

    }

    void display()
    {
        cout << "Linked List (Head to Tail): ";
        Node* current = head;
        while (current)
        {
            cout << current->key << " ";
            current = current->next;
        }
        cout << endl;

        cout << "Linked List (Tail to Head): ";
        current = tail;
        while (current)
        {
            cout << current->key << " ";
            current = current->prev;
        }
        cout << endl;
    }
};

int main()
{
    DoublyLinkedList linked_list;
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
            linked_list.insert_after_node(key,value);
            linked_list.display();
        }

        else if(num==4)
        {
            cout<<"Enter The value and the updated value:";
            int key,value;
            cin>>value>>key;
            linked_list.update_node(key,value);
            linked_list.display();
        }

        else if(num==5)
        {
            linked_list.remove_head();
            linked_list.display();
        }

         else if(num==6)
        {
            cout<<"Enter The number to remove:";
            int key;
            cin>>key;
            linked_list.remove_element(key);
            linked_list.display();
        }

        else if(num==7)
        {
            linked_list.remove_end();
            linked_list.display();
        }
    }

    return 0;
}

