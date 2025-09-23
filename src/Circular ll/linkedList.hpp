#include <iostream>
#include "list.hpp"
using namespace std;

class linkedList : public list {
    int size;
    node* head, *tail;

    void rotate(int num){
        head = head->next;
        tail = tail->next;
    }

public:
    linkedList(){
        size = 0;
        head = nullptr;
        tail = nullptr;
    }

    void add(int num){
        node* n = new node();
        n->elem = num;
        if(!head){
            head = tail = n;
            size++;
            return;
        }

        tail->next = n;
        head = n;
        size++;
    }

    void print(){
        head = tail->next;
        node* temp = head;
        if(size==0){
            cout << "Empty.\n";
        } else {
            do {
                cout << temp->elem;
                if(temp!=tail){
                    cout << " -> ";
                }
                temp = temp->next;
            } while(temp!=head);
        }
        cout << endl;
    }

};