#include <iostream>
#include "stack.hpp"
#include "linkedList.hpp"
using namespace std;

int main (){
    Stack* s = new LinkedList();
    char op;
    int n;
    
    cout << "Options\n";
    cout << "a. Push\n" << "b. Pop\n" << "c. Print\n";
     do {
        cout << "Enter option: ";
        cin >> op;
        switch(op){
            case 'a':
                cout << "Enter value to push: ";
                cin >> n;
                s->push(n);
                break;

            case 'b':
                n = s->pop();
                if(n){
                    cout << "Removed value: " << n << endl;
                } else {
                    cout << "Empty.\n";
                }
                break;
            case 'c':
                s->print();
                break;
            default:
                cout << "Error option.\n";
        } 
    }while(op!='x');
}