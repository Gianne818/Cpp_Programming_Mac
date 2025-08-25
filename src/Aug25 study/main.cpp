#include <iostream>
#include <string>
#include "arraylist.hpp"
using namespace std;

int main (){
    ArrayList* list = new ArrayList();
    char op;
    string str;
    int n;
    Entry e;
    string res;
    Entry* temp;

    cout << "Options:\n";
    cout << "a. Add\n" << "b. Display Score Board\n" <<  "c. Remove\n" << "d. Get player at position\n" << "x. Exit\n";

    do {
        cout << "Enter your option: ";
        cin >> op;
        switch(op){
            case 'a':
                cout << "Enter name of participant: ";
                cin >> e.name;
                cout << "Enter score of participant: ";
                cin >> e.score;
                list->add(&e);
                break;
            
            case 'b':
                list->print();
                break;

            case 'c':
                cout << "Enter name of the entry to remove: ";
                cin >> str;
                temp = list->remove(str);
                if(temp == nullptr){
                    cout << "Entry not found.\n";
                } else {
                    cout << "Successfully removed: " << temp->name << endl;
                }
                break;
            
            case 'd':
                cout << "Enter the position: ";
                cin >> n;
                e = list->get(n);
                if(e.score == -1){
                    cout << "Error position. Please enter 1-5.\n";
                } else if(e.score == -2){
                    cout << "There is no player at said position.\n";
                } else {
                    cout << "Player at position " << n << ": " << e.name << ", " << e.score << endl;
                }
                break;

            
            default:
            cout << "Error option.\n";
        } 
    } while (op!='x');
}