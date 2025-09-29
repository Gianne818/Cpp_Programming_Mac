//Stack is best implemented using ArrayList, since operations on a stack mostly LIFO, involves adding and removing
//at the end. In a singly ll, removing at the end is costly O(n), and also occupies more space. On a doubly ll,
// it will occupy unnecessary space.


#include "ArrayList.hpp"
using namespace std;


class Stack : public ArrayList{
public:

    void push(char c){
        if(size==cap){
            resizeUp();
        }
        array[size++] = c;
    }

    void pop(){
        if(size==0){
            return;
        }
        size--;
        if(size<=floor(cap * 2.0/3.0)){
            resizeDown();
        }
    }

    char top(){
        return array[size-1];
    }

    bool isEmpty(){
        return size==0 ? true : false;
    }

    void print(){
        for (int i = size-1; i>=0; i--){
            cout << array[i] << endl;
        }
        cout << endl;
    }


};