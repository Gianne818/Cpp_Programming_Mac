#include <iostream>
#include "list.hpp"
using namespace std;

/*
class list {
    virtual void add(int) = 0;
    virtual void addHead(int) = 0;
    virtual void addTail(int) = 0;
    virtual int get(int) = 0;
    virtual int remove(int) = 0;
    virtual int removeAt(int) = 0;
    virtual int removeAll(int) = 0;
};
*/

class linkedList : public list {
    int size;
    node* head, *tail;

    void rotate(int num){
        for (int i = 0; i<num; i++){
            head = head->next;
            tail = tail->next;
        }
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
            n->next = head;
            
        } else {
            tail->next = n;
            n->next = head;
            tail = n;
        }
        size++;
    }

    void addHead(int num){
        node* n = new node();
        n->elem = num;
        if(!head){
            head = tail = n;
            n->next = head;
        } else {
            n->next = head;
            head = n;
            tail->next = head;
        }
        size++;
    }

    void addTail(int num){
        add(num);
    }

    int get(int num){
        node* temp = head;
        int pos = 1;
        do {
            if(temp->elem == num){
                return pos;
            }
            pos++;
            temp = temp->next;
        } while(temp!=tail->next);
        return -1;
    }

    int remove(int num){
        node* temp = head;
        node* prev = tail;
        int pos = 1;
        do {
            if(temp->elem == num){
                if(temp==head){
                    if(head==tail){
                        head = tail = nullptr;
                    } else {
                        head = head->next;
                        tail->next = head;
                    }
                } else if(temp==tail){
                    tail = prev;
                    tail->next = head;
                } else {
                    prev->next = temp->next;
                }
                free(temp);
                size--;
                return pos;
            }
            pos++;
            prev = temp;
            temp = temp->next;
        } while(temp!=head);
        return -1;
    }

    int removeAt(int pos){
        if(pos<1 || pos > size || !head) return -1;
        node* temp = head;
        node* prev = tail;
        int i = 1;
        do{
            if(i==pos){
                int val = temp->elem;
                if(temp==head){
                    if(head==tail){
                        head = tail = nullptr;
                    } else {
                        head = head->next;
                        tail->next = head;
                    }
                } else if(temp==tail){
                    tail = prev;
                    tail->next = head;
                } else {
                    prev->next = temp->next;
                }
                delete temp;
                size--;
                return val;
            }
            prev = temp;
            i++;
            temp = temp->next;
        } while(temp!=head);
        return -1;
    }

    int removeAll(int num){
        int count = 0;
        node* temp = head;
        node* prev = tail;
        do{
            node* toRemove = temp;
            if(temp->elem == num){
                if(temp==head){
                    if(head==tail){
                        head = tail = nullptr;
                    } else {
                        head = head->next;
                        tail->next = head;
                    }
                } else if(temp==tail){
                    tail = prev;
                    tail->next = head;
                } else {
                    prev->next = temp->next;
                }
                temp = temp->next;
                delete toRemove;
                size--;
                count++;
            } else {
                prev = temp;
                temp = temp->next;
            }
            
        } while (temp!=head);
        return count;
    }



    void print(){
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