#include <iostream>
#include "Queue.hpp"
#include "node.hpp"
using namespace std;

class LinkedList : public Queue{
    int size;
    node* head, *tail;

public:
    LinkedList(){
        size = 0;
        head = nullptr;
        tail = nullptr;
    }

    void push(int num){
        node* n = new node();
        n->elem = num;

        if(tail){
            tail->next = n;
        } else {
            head = n;
        }
        
        n->next = nullptr;
        tail = n;
        size++;
    }

    int pop(){
        if(!head){
            return -1;
        } else if (head==tail){
            tail = nullptr;
        }
        int val = head->elem;

        node* temp = head;
        head = head->next;

        free(temp);
        size--;
        return val;
    }

    void print(){
        node* temp = head;
        while(temp){
            cout << temp->elem << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};