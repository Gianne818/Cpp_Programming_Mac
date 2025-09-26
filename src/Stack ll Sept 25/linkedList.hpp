#include <iostream>
#include "stack.hpp"
#include "node.hpp"
using namespace std;

class LinkedList : public Stack{
    int size;
    node head, tail; //head is top

    node* addBetween(int num, node* pred, node* succ){
        node* n = new node();
        n->elem = num;
        n->next = succ;
        n->prev = pred;

        pred->next = n;
        succ->prev = n;
        size++;
        return n;
    }

    int removeNode(node* n){
        n->next->prev = n->prev;
        n->prev->next = n->next;

        int val = n->elem;
        free(n);
        size--;
        return val;
    }

public:
    LinkedList(){
        size = 0;
        head.next = &tail;
        tail.prev = &head;

        head.prev = nullptr;
        tail.next = nullptr;
    }

    void push(int num){
        addBetween(num, tail.prev, &tail);
    }

    int pop(){
        return removeNode(tail.prev);
    }

    void print(){
        node* temp = tail.prev;
        while(temp!=&head){
            cout << temp->elem << endl;
            temp = temp->prev;
        }
        cout << endl;
    }

};