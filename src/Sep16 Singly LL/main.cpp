#include "LinkedList.hpp"
#include <iostream>
using namespace std;

int main (){
    List* list = new LinkedList();

    char op;
    int val;
    int pos;
    Node* temp = new Node();
    cout << "Options: " << endl << "a. Add\n" << "b. Print\n" << "c. Remove Head.\n" << "d. Remove Tail\n" << "e. Find num\n" << 
    "f. insertAt\n" << "g. removeAt\n" << "h. removeAll\n" << "i. flip\n" << "x. Exit\n";
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
                if(val==-1){
                    cout << "List is empty.\n";
                } else {
                    cout << "Removed " << val << endl;
                }
                break;

            case 'd':
                val = list->removeTail();   
                if(val==-1){
                    cout << "List is empty.\n";
                } else {
                    cout << "Removed " << val << endl;
                }
                break;

            case 'e':
                cout << "Enter value to find: ";
                cin >> val;
                temp = list->find(val);
                if(!temp){
                    cout << "Value does not exist.\n";
                } else {
                    cout << "Value at node: " << temp->elem << endl;
                }
                break;

            case 'f':
                cout << "Enter value to add: ";
                cin >> val;
                cout << "Enter position to add: ";
                cin >> pos;
                list->insertAt(pos, val);
                break;
            
            case 'g':
                cout << "Enter position to remove ";
                cin >> pos;
                val = list->removeAt(pos);
                if(val == -1){
                    cout << "Removed nothing.\n";
                } else {
                    cout << "Removed " << val << endl;
                }
                break;
            case 'h':
                cout << "Enter number to remove all instances of: ";
                cin >> val;
                pos = list->removeAll(val);
                cout << "Removed " << pos << " elements.\n";
                break;

            case 'i':
                list->flip();
                break;
            case 'x':
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Error.\n";
        }
    } while (op!='x');

    delete((LinkedList*)list);
}