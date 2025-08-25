#include <iostream>
#include "arraylist.hpp"
using namespace std;

int main (){
    List* l = new ArrayList();
    cout << "Options:" << endl;
    cout << "a. Add\n" << "b. Print\n" << "c. Remove\n" << "d. Add at first index.\n" << "e. Remove first element.\n" << 
     "f. Remove last element.\n" << "i. Flip array\n" << "x. Exit\n";

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

            case 'x':
                cout << "Exiting...";
                break;
            
            default:
            cout << "Invalid option.\n";
        } 
    } while(op!='x');
}