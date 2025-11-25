#include <iostream>
#include <cstdlib>
#include <cmath>
#include "minheap.hpp"
#include <algorithm>
using namespace std;

class ArrayMinHeap : public MinHeap {
    int* array;
    int size;
    int capacity = 5;

    int left(int i) {
        return 2*i + 1;
    }

    int right(int i) {
        return 2*i + 2;
    }
    
    void heapifyDown(){
        int i = 0;
        while(true){
            int l = left(i);
            int r = right(i);
            int smallest = i;
            
            if(l < size && array[l] < array[smallest]) smallest = l;
            if(r < size && array[r] < array[smallest]) smallest = r;
            
            if(i == smallest) break;
            swap(array[smallest], array[i]);
            i = smallest;
        }
    }
    
    void resizeUp(){
        int newCap = ceil(capacity*1.5);
        capacity = newCap;
        array = (int*) realloc(array, capacity*sizeof(int));
    }
    
    void resizeDown(){
        int newCap = ceil(capacity*0.8);
        if(newCap < 5) capacity = 5;
        else capacity = newCap;
        array = (int*) realloc(array, capacity*sizeof(int));
    }
    
    

    public:
    ArrayMinHeap() {
        array = (int*)malloc(5*sizeof(int));
        size = 0;
    }
    
    

    // TODO insert the num into the heap
    void insert(int num) {
        if(size==capacity) resizeUp();
        array[size++] = num;
        int i = size-1;
        
        int parent = (i-1)/2;
        while(i > 0 && array[parent] > array[i]){
            swap(array[parent], array[i]);
            i = parent;
            parent = (i-1)/2;
        }
    }

    // TODO remove the minimum value, -1 if empty
    int removeMin() {
        if(size == 0) return -1;
        
        int temp = array[0];
        array[0] = array[size-1];
        size--;
        
        heapifyDown();
        if(size < ceil(capacity*(3.0/4.0))) resizeDown();
        return temp;
    }

    // DO NOT modify the code below
    void print() {
        if (size == 0) {
            cout << "EMPTY" << endl;
            return;
        }
            cout << "Size: " << size << "/" << capacity << endl;
            cout << "TREE: " << endl;
            print_tree("", 0, false);

        cout << "ARRAY: ";
        for (int i = 0; i < size; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }

    void print_tree(string prefix, int n, bool isLeft) {
        cout << prefix;
        cout << (isLeft ? "+--L: " : "+--R: " );
        cout << array[n] << endl;
        if (left(n) < size) {
            print_tree(prefix + "|   ", left(n), true);
        }
        if (right(n) < size) {
            print_tree(prefix + "|   ", right(n), false);
        }
    }
};