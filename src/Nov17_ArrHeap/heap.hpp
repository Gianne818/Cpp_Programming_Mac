#include <iostream>
#include <cmath>
using namespace std;

class MinHeap {
    int* arr;       // dynamic array
    int capacity;   // allocated size
    int size;       // number of elements

    void swapElem(int& a, int& b){
        int t = a;
        a = b;
        b = t;
    }

    void resizeUp(){
        int newCap = ceil(capacity * 1.5);
        arr = (int*) realloc(arr, newCap * sizeof(int));
        capacity = newCap;
    }

    void resizeDown(){
        int newCap = capacity / 2;
        if(newCap < 10) return;
        arr = (int*) realloc(arr, newCap * sizeof(int));
        capacity = newCap;
    }

    void heapifyUp(int idx){
        while(idx > 0){
            int parent = (idx - 1) / 2;
            if(arr[idx] >= arr[parent]) break;     // MIN-heap condition
            swapElem(arr[idx], arr[parent]);
            idx = parent;
        }
    }

    void heapifyDown(int idx){
        while(true){
            int left = 2*idx + 1;
            int right = 2*idx + 2;
            int smallest = idx;

            if(left < size && arr[left] < arr[smallest]) smallest = left;
            if(right < size && arr[right] < arr[smallest]) smallest = right;

            if(smallest == idx) break;

            swapElem(arr[idx], arr[smallest]);
            idx = smallest;
        }
    }

public:

    MinHeap(){
        capacity = 10;
        size = 0;
        arr = (int*) malloc(capacity * sizeof(int));
    }

    void insert(int num){
        if(size == capacity) resizeUp();

        arr[size] = num;
        heapifyUp(size);
        size++;
    }

    void removeRoot(){  // removeMin
        if(size == 0) return;
        if(size == 1){
            size = 0;
            return;
        }

        arr[0] = arr[size - 1];
        size--;

        heapifyDown(0);

        if(size <= capacity / 4) resizeDown();
    }

    void print(){
        for(int i = 0; i < size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};