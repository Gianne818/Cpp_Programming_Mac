#include "linkedList.hpp"
#include <iostream>
using namespace std;

int main (){
    linkedList* list = new linkedList();

    char op;
    int val;
    int pos;
    node* temp = new node();
    cout << "Options: " << endl << "a. Add\n" << "b. Print\n" << "c. Add Head\n" << "d. Add Tail\n" << "e. get\n" << 
    "f. remove\n" << "g. removeAt\n" << "h. removeAll\n" << "i. Reverse Print\n" << "j. Add Middle\n" << "x. Exit\n";
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

            // case 'c':
            //     cout << "Enter number to add to head: ";
            //     cin >> val;
            //     list->addHead(val);
            //     break;

            // case 'd':
            //     cout << "Enter number to add to tail: ";
            //     cin >> val;
            //     list->addTail(val);
            //     break;

            // case 'e':
            //     cout << "Enter position to get: ";
            //     cin >> pos;
            //     val = list->get(pos);
            //     if(val==-1){
            //         cout << "Value does not exist.\n";
            //     } else {
            //         cout << "Value at node: " << val << endl;
            //     }
            //     break;

            // case 'f':
            //     cout << "Enter value to remove: ";
            //     cin >> val;
            //     pos = list->remove(val);
            //     if(pos==-1){
            //         cout << "Value does not exist.\n";
            //     } else {
            //         cout << "Deleted value at position: " << pos << endl;
            //     }
            //     break;
            
            // case 'g':
            //     cout << "Enter position to remove ";
            //     cin >> pos;
            //     val = list->removeAt(pos);
            //     if(val == -1){
            //         cout << "Removed nothing.\n";
            //     } else {
            //         cout << "Removed " << val << endl;
            //     }
            //     break;
                
            // case 'h':
            //     cout << "Enter number to remove all instances of: ";
            //     cin >> val;
            //     pos = list->removeAll(val);
            //     cout << "Removed " << pos << " elements.\n";
            //     break;

            // case 'i':
            //     list->reversePrint();
            //     break;

            // case 'j':
            //     cout << "Enter number to add to mid: ";
            //     cin >> val;
            //     list->addMid(val);
            //     break;

            case 'x':
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Error.\n";
        }
    } while (op!='x');

   // delete((LinkedList*)list);
}