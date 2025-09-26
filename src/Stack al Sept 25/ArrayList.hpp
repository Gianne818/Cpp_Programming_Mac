#include "Stack.hpp"
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

//Stack is best implemented using ArrayList, since operations on a stack mostly LIFO, involves adding and removing
//at the end. In a singly ll, removing at the end is costly O(n), and also occupies more space. On a doubly ll,
// it will occupy unnecessary space.

class ArrayList : public Stack{
    int size;
    int* array;
    int cap;

    void resizeUp(){
        int newCap = ceil(cap*1.5);
        cout << "Reallocation up triggered.\n";
        cap = newCap;
        array = (int*)realloc(array, cap*sizeof(int));
    }

    void resizeDown(){
        int newCap = ceil(cap*0.75);
        cap = max(newCap, 5);
        cout << "Reallocation down triggered.\n";
        array = (int*)realloc(array, cap*sizeof(int));
    }

public:
    ArrayList(){
        size = 0;
        cap = 5;
        array = (int*)malloc(cap*sizeof(int));
    }

    void push(int num){
        if(size==cap){
            resizeUp();
        }
        array[size] = num;
        size++;
    }

    int pop(){
        int val = array[size-1];
        if(size==0){
            return -1;
        }
        //free((array+(size-1)));
        size--;
        if(size<=floor(cap * 2.0/3.0)){
            resizeDown();
        }
        return val;
    }

    void print(){
        for (int i = size-1; i>=0; i--){
            cout << array[i] << endl;
        }
        cout << endl;
    }


};