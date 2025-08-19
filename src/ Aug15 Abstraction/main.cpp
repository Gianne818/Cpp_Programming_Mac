#include <iostream>
#include "arraylist.hpp"

using namespace std;

int main (){
    //ArrayList* list = new ArrayList();
    //list->size = 6; //size should be private but this line will be an error if we have List* list = new ArraySize();
    List* list = new ArrayList();
    for (int i = 0; i<10; i++){
        list->add(i+1);
    }
    
    list->print();
    return 0;
}