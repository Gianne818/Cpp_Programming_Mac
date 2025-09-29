#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

class ArrayList{
protected:
    int size;
    char* array;
    int cap;

public:

    void resizeUp(){
        int newCap = ceil(cap*1.5);
        cap = newCap;
        array = (char*)realloc(array, cap*sizeof(char));
    }

    void resizeDown(){
        int newCap = ceil(cap*0.75);
        cap = max(newCap, 5);
        array = (char*)realloc(array, cap*sizeof(char));
    }

    ArrayList(){
        size = 0;
        cap = 5;
        array = (char*)malloc(cap*sizeof(char));
    }
};
