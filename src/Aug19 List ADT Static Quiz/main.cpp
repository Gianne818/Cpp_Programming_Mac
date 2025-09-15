#include <iostream>
#include "arraylist.hpp"
using namespace std;

int main (){
    List* l = new ArrayList();
    cout << "Options:" << endl;
    cout << "a. Add\n" << "b. Print\n" << "c. Remove\n" << "d. Add at first index.\n" << "e. Remove first element.\n" << 
     "f. Remove last element.\n" << "i. Flip array\n" << "j. Clear array.\n"  << "k. Add at position.\n"
      << "l. Remove all instance.\n" << "m. Remove at position.\n" << "n. Sort descending.\n" <<"o. Get Position.\n" << "x. Exit\n";

    char op;
    int num, pos;
    int res;
    do {
        cout << "Enter your option: ";
        cin >> op;
        switch(op){
            case 'a':
                cout << "Enter number to add: ";
                cin >> num;
                l->add(num);
                break;

            case 'b':
                l->print();
                break;
            
            case 'c':
                cout << "Enter first instance of number to remove: ";
                cin >> num;
                res = l->remove(num);
                if(res==-1){
                    cout << "No instance of number found.\n";
                } else {
                    cout << "Removed at index " << res << endl;
                }
                break;

            case 'd':
                cout << "Enter number to add at first index: ";
                cin >> num;
                res = l->addFirst(num);
                if(res==-1){
                    cout << "Cannot add anymore.\n";
                } else {
                    cout << "Successfully added " << num;
                }
                break;

            case 'e':
                res = l->removeFirst();
                if(res==-1){
                    cout << "There is nothing to remove.\n";
                } else {
                    cout << "Successfully removed " << res << endl;
                }
                break;
            
            case 'f':
                res = l->removeLast();
                if(res==-1){
                    cout << "There is nothing to remove.\n";
                } else {
                    cout << "Successfully removed " << res << endl;
                }
                break;

            case 'i':
                l->flip();
                break;
            
            case 'j':
                l->clear();
                break;

            case 'k':
                cout << "Enter number to add: ";
                cin >> num;
                cout << "Enter position: ";
                cin >> pos;
                l->addAtPos(num, pos);
                break;
            
            case 'l':
                cout << "Enter the number to remove: ";
                cin >> num;
                res = l->removeAllInstance(num);
                cout << "Succesfully removed " << res << " elements.\n";
                break;

            case 'm':
                cout << "Enter position of element to remove: ";
                cin >> pos;
                res = l->removeAtPos(pos);
                cout << "Successfully removed: " << res << endl;
                break;
            
            case 'n':
                l->sortDescending();
                break;

            case 'o':
                cout << "Enter number to find: ";
                cin >> num;
                res = l->positionOf(num);
                if(res==-1){
                    cout << "Number not found.\n";
                } else {
                    cout << num << " is at position " << res << endl; 
                }
                break;

            case 'x':
                cout << "Exiting...";
                break;
            
            default:
            cout << "Invalid option.\n";
        } 
    } while(op!='x');
}