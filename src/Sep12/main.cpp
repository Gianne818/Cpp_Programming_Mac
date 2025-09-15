#include <iostream>
#include "LinkedList.hpp"
using namespace std;

int main (){
    LinkedList* list = new LinkedList();
    // for (int i = 0; i<50000000; i++){
    //     list->add(i);
    // }
    // list->print();
    // cout << endl;
    // cout << endl;



    // list = new LinkedList();
    // for (int i = 1; i<50000000; i++){
    //     list->add(i);
    // }
    // list->print();
    // cout << endl;



    char op;
    int val;
    Node* temp = new Node();
    cout << "Options: " << endl << "a. Add\n" << "b. Print\n" << "c. Remove Head.\n" << "d. Remove Tail\n" << "e. Find num\n" << "x. Exit\n";
    do {
        cout << "Enter option: ";
        cin >> op;
        switch(op){
            case 'a': 
                cout << "Enter number: ";
                cin >> val;
                list->add(val);
                break;
            
            case 'b':
                list->print();
                break;

            case 'c':
                val = list->removeHead();
                if(val==0){
                    cout << "List is empty.\n";
                } else {
                    cout << "Removed " << val << endl;
                }
                break;

            case 'd':
                val = list->removeTail();
                if(val==0){
                    cout << "List is empty.\n";
                } else {
                    cout << "Removed " << val << endl;
                }
                break;

            case 'e':
                temp = list->find();
                if(val==0){
                    cout << "List is empty.\n";
                } else {
                    cout << "Removed " << val << endl;
                }
                break;

            case 'x':
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Error.\n";
        }
    } while (op!='x');
}