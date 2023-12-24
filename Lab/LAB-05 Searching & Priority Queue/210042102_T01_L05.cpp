#include <iostream>
#include <vector>
using namespace std;

void Heapify(vector<int>& heap, int i){
    int sz = heap.size();
    int mn = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if(l < sz && heap[mn] > heap[l]) mn = l;
    if(r < sz && heap[mn] > heap[r]) mn = r;

    if(mn != i){
        swap(heap[i], heap[mn]);
        Heapify(heap, mn);
    }
}

void Build_minHeap(vector<int>& heap){
    int sz = heap.size();
    for(int i = sz / 2 - 1; i >= 0; i--) {
        Heapify(heap, i);
    }
}

void Min_heap_insert(vector<int>& heap, int value){
    heap.push_back(value);
    int i = heap.size() - 1;

    while(i > 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int Heap_extract_min(vector<int>& heap){
    int sz = heap.size();
    if(sz == 0) return -1;

    int mn = heap[0];
    heap[0] = heap[sz-1];
    heap.pop_back();
    Heapify(heap, 0);
    return mn;
}

void State_of_heap(vector<int>& heap){
    for(auto &e : heap) cout << e << " ";
    cout << "\n";
}

int Heap_Minimim(vector<int>& heap){
    return heap[0];
}

void Heap_decrease_key(int p, int k, vector<int>& heap){
    heap[p-1] -= k;
    int i = p - 1;
    while(i > 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void Heap_increase_key(int p, int k, vector<int>& heap){
    heap[p-1] += k;
    Build_minHeap(heap);
}

int main(){
    vector<int> heap;

    int x, cmd, sz, p, k;

    while(1){
        cin >> x;
        if(x == -1) break;

        heap.push_back(x);
    }

    Build_minHeap(heap);
    State_of_heap(heap);
    cout << "\n";

    while(cin >> cmd){

        if(cmd == 1){
            cout << Heap_Minimim(heap) << "\n";
        }
        if(cmd == 2){
            cout << Heap_extract_min(heap) << "\n";
        }
        if(cmd == 3){
            cin >> x;
            Min_heap_insert(heap, x);
        }
        if(cmd == 4){
            cin >> p >> k;
            Heap_decrease_key(p, k, heap);
        }
        if(cmd == 5){
            cin >> p >> k;
            Heap_increase_key(p, k, heap);
        }

        State_of_heap(heap);
        cout << "\n";
    }

    return 0;
}


// 70 90 60 190 80 170 110 20 50 30 130 -1
// 1
// 2
// 1
// 3 45
// 4 4 65
// 2
// 5 1 170
// 3 47
