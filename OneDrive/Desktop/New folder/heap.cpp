#include <bits/stdc++.h>
using namespace std;

class heap{

    public:
    int arr[100];
    int size;

    heap(){
        arr[0] = -1;
        size = 0;
    }


    // Max Heap insertion
    void insertion(int val){
        // Time = O(log n)
        size = size + 1;
        int index = size;
        arr[index] = val;
        while(index > 1){
            int parent = index/2;
            if(arr[index] > arr[parent]){
                swap(arr[index], arr[parent]);
                index = parent;
            }else{
                return;
            }
        }
    }

    void deleteionFromHeap(){
        // Time = O(log n)
        arr[1] = arr[size];
        size--;
        int index = 1;
        while(index < size){
            int leftIndex = 2*index;
            int rightIndex = 2*index + 1;

            if(leftIndex < size && arr[index] < arr[leftIndex]){
                swap(arr[index], arr[leftIndex]);
            }else if(rightIndex < size && arr[index] < arr[rightIndex]){
                swap(arr[index], arr[rightIndex]);
            }else{
                return;
            }
        }
    }

    void print(){
        for(int i=1; i<=size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

};

// Heapify - It will place the node to its correct position

void heapify(int arr[], int n, int i){
    // O(N)
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if(left <= n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right <= n && arr[largest] < arr[right]){
        largest = right;
    }
    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n){
    int size = n;
    while(size > 1){
        swap(arr[size], arr[1]);
        size--;
        heapify(arr, size, 1);
    }
}


int main(){
    heap h;
    h.insertion(6);
    h.insertion(5);
    h.insertion(7);
    h.insertion(2);
    h.insertion(1);
    h.insertion(9);
    h.insertion(11);

    h.print();

    h.deleteionFromHeap();
    h.print();

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for(int i=n/2; i>0; i--){
        heapify(arr, n, i); //O(logN)
    }

    // Printing Heapify Nodes

    heapSort(arr, n); //O(NlogN)

    for(int i=1; i<=n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Priority Queue " << endl;

    priority_queue<int>pq; // max heap
    pq.push(4);
    pq.push(2);
    pq.push(1);
    pq.push(3);
    cout << "Top element " << pq.top() << endl;
    pq.pop();
    cout << "Size of heap " << pq.size() << endl;
    cout << "Empty Heap " << pq.empty() << endl;


    // MIN Heap
    cout << "MIN  HEAP " << endl;

    priority_queue<int, vector<int>, greater<int>> minHeap;

    minHeap.push(4);
    minHeap.push(2);
    minHeap.push(1);
    minHeap.push(3);
    cout << "Top element " << minHeap.top() << endl;
    minHeap.pop();
    cout << "Size of heap " << minHeap.size() << endl;
    cout << "Empty Heap " << minHeap.empty() << endl;
    return 0;
}