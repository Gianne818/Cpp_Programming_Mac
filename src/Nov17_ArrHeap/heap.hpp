#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

class Heap {
    int* arr;       // dynamic array
    int capacity;   // allocated size
    int size;       // number of elements

    void resizeUp(){
        int newCap = ceil(capacity * 1.5);
        arr = (int*) realloc(arr, newCap * sizeof(int));
        cout << "Triggered resizeUp: " << newCap <<  endl;
        capacity = newCap;
    }


    void resizeDown(){
        int newCap = floor(capacity * 0.75);
        arr = (int*) realloc(arr, newCap * sizeof(int));
        cout << "Triggered resizeDown: " << newCap <<  endl;
        capacity = newCap;
    }

    // void heapifyUp(int idx){
    //     while(idx > 0){
    //         int parent = (idx - 1) / 2;
    //         if(arr[idx] >= arr[parent]) break;     // MIN-heap condition
    //         swap(arr[idx], arr[parent]);
    //         idx = parent;
    //     }
    // }

    void heapifyDown(int idx){
        while(true){
            int left = 2*idx + 1;
            int right = 2*idx + 2;
            int smallest = idx;

            if(left < size && arr[left] < arr[smallest]) smallest = left;
            if(right < size && arr[right] < arr[smallest]) smallest = right;

            if(smallest == idx) break;

            swap(arr[idx], arr[smallest]);
            idx = smallest;
        }
    }




public:

    Heap(){
        capacity = 10;
        size = 0;
        arr = (int*) malloc(capacity * sizeof(int));
    }

    void insert(int num){
        if(size == capacity) resizeUp();
        arr[size++] = num;
        int i = size-1;

        int parent = (i-1)/2;
        while(i > 0 && arr[parent] > arr[i]){
            swap(arr[i], arr[parent]); 
            i = parent;
            parent = (i-1)/2;
        }
    }


    void removeMin(){  // removeMin
        if(size == 0) return;
/*
        if(size == 1){
            size = 0;
            return;
        }
*/

        arr[0] = arr[size - 1];
        size--;
        heapifyDown(0);

        if(size <= floor(capacity/2.0)) resizeDown();
    }

    void print(){
        int i = 0;
        for(i = 0; i < size; i++){
            cout << arr[i] << " ";
        }


        for(i; i<capacity; i++){
            cout << "0 ";
        }
        cout << endl;
    }
};