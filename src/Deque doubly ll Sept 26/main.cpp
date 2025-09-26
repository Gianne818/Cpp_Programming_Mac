#include <iostream>
//#include "Deque.hpp"
#include "linkedList.hpp"
using namespace std;

int main (){
    Deque* s = new LinkedList();
    char op;
    int n;
    
    cout << "Options\n";
    cout << "a. Insert Front\n" << "b. Insert Rear\n" << "c. Remove Front\n" << "d. Remove Rear\n" << "e. Print\n";
     do {
        cout << "Enter option: ";
        cin >> op;
        switch(op){
            case 'a':
                cout << "Enter value to push: ";
                cin >> n;
                s->insertFront(n);
                break;

            case 'b':
                cout << "Enter value to push: ";
                cin >> n;
                s->insertRear(n);
                break;

            case 'c':
                n = s->removeFront();
                if(n){
                    cout << "Removed value: " << n << endl;
                } else {
                    cout << "Empty.\n";
                }
                break;

            case 'd':
                n = s->removeRear();
                if(n){
                    cout << "Removed value: " << n << endl;
                } else {
                    cout << "Empty.\n";
                }
                break;

            case 'e':
                s->print();
                break;
            default:
                cout << "Error option.\n";
        } 
    }while(op!='x');
}