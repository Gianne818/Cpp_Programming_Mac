#include <iostream>
#include "list.hpp"

using namespace std;

class ArrayList : public List {
public: //should ideally be private, but if public, do the uncommented version
    //this will not work indefinitely
    int arr[5];
    int size = 0;
    

    //this works only until 5, because size gets overwritten with the next array
    //int arr[5];
    //int size = 0;


public:
    void add(int num){
        if(size==5){
            cout << "Cannot add anymore." << endl;
            return;
        }
        cout << "Adding " << num << endl;
        arr[size++] = num;
        return;
    }

    void print(){
        for (int i = 0; i<size; i++){
            cout << "arr[" << i << "]: " << arr[i] << endl;
        }
    }

    int getElem(int pos){
        if(pos<=size){
            cout << "Error size.";
            return 0;
        }
        return arr[pos];
    }

    void remove(int num){
        for(int i = 0; i<size; i++){
            if(arr[i]==num){
                arr[i]=0;
                break;
            }
        }
    }

    int getSize(){
        return size;
    }
};