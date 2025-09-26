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
    Entry* ent;

    cout << "Options:\n";
    cout << "a. Add\n" << "b. Display Score Board\n" << "c. Display whole list\n" <<  "d. Remove at\n" << "x. Exit\n";

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
                list->printScoreBoard();
                break;
            
            case 'c':
                list->printBoard();
                break;

            case 'd':
                cout << "Enter position to remove: ";
                cin >> n;
                ent = list->removeAt(n);
                if(!ent){
                    cout << "Error position.";
                } else {
                    cout << "Successfully removed: " << ent->name << " - " << ent->score << endl;
                }
                break;


            
            // case 'd':
            // cout << "Enter name: ";
            // cin >> str;
            // res = list->remove(str);
            // if(res=="Error"){
            //     cout << "Name not found.\n";
            // } else {
            //     cout << "Successfully removed " << res << endl;
            // }
            // break;

            default:
            cout << "Error option.\n";
        } 
    } while (op!='x');
}