#include <iostream>
#include "list.hpp"
using namespace std;

class ArrayList : public List {
private:
    int size = 0;
    int array[5];

public: 
    void add(int num){
        if(size==5){
            cout << "Cannot add anymore.\n";
            return;
        }
        array[size++] = num;
    }

    void print(){
        for (int i = 0; i<5; i++){
            cout << "arr[" << i << "]: " << array[i] << endl;
        }
    }

    int remove(int num){
        int i;
        for (i = 0; i<size; i++){
            if(array[i]==num){
                for(int j = i; j<size-1; j++){
                    array[j] = array[j+1];
                }
                array[size-1] = 0;
                size--;
                return i;
            }
        }
        return -1;
    }

    int addFirst(int num){
        if(size==5){
            return -1;
        }
        for (int i = size; i>0;i--){
            array[i] = array[i-1];
        }
        array[0] = num;
        size++;
        return array[0];
    }

    int removeFirst(){
        if(size==0){
            return -1;
        }
        int temp = array[0];
        for (int i = 0; i<size-1; i++){
            array[i] = array[i+1];
        }
        array[size-1] = 0;
        size--;
        return temp;
    }

    int removeLast(){
        if(size==0){
            return -1;
        }

        int temp = array[size-1];
        array[size-1] = 0;
        size--;
        return temp;
    }

    void flip(){
        int start = 0, end = size-1;
        while((start)<(end)){
            int temp = array[start];
            array[start] = array[end];
            array[end] = temp;

            start++;
            end--;
        }
    }
};