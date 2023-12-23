#include<iostream>
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

const int N=1e5;
const int INF=1e9+10;

class Prio_Queue
{
public:
    vector<pair<int, int>> heap;


    void heapify(int index)
    {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;


        if (left < heap.size() && heap[left].first > heap[largest].first)
        {
            largest = left;
        }


        if (right < heap.size() && heap[right].first > heap[largest].first)
        {
            largest = right;
        }


        if (largest != index)
        {
            swap(heap[index], heap[largest]);
            heapify(largest);
        }
    }

public:

    Prio_Queue() {}


    void push(int value, int priority)
    {
        heap.push_back(make_pair(value, priority));
        int index = heap.size() - 1;


        while (index > 0)
        {
            int parent = (index - 1) / 2;
            if (heap[index].first > heap[parent].first)
            {
                swap(heap[index], heap[parent]);
                index = parent;
            }
            else
            {
                break;
            }
        }
    }


    pair<int, int> pop()
    {
        if (heap.empty())
        {
            cout<<"Heap is empty"<<endl;
            exit(1);
        }

        pair<int, int> max = heap[0];
        heap[0] = heap.back();
        heap.pop_back();

        heapify(0);

        return max;
    }


    pair<int, int> top()
    {
        if (heap.empty())
        {
            cout<<"Heap is empty"<<endl;
            exit(1);
        }
        return heap[0];
    }


    bool isEmpty()
    {
        return heap.empty();
    }
};

int main() {
    Prio_Queue priorityQueue;

    priorityQueue.push(10, 2);
    priorityQueue.push(30, 1);
    priorityQueue.push(20, 3);
    priorityQueue.push(25, 2);

    cout << "Priority Queue: ";
    while (!priorityQueue.isEmpty())
    {
        pair<int, int> item = priorityQueue.pop();
        cout << "(" << item.first << ", " << item.second << ") ";
    }
    cout << endl;

    return 0;
}
