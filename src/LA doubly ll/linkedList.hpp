#include <iostream>
#include "list.hpp"
using namespace std;

class linkedList : public list{
private:
    int size;
    node* head, *tail;

public: 
    linkedList(){
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void add(int num){
        node* n = new node();
        n->elem = num;
        n->next = nullptr;

        if(tail){
            tail->next = n;
            n->prev = tail;
        } else {
            head = n;
            //head->prev = nullptr;
        }
        tail = n;
        size++;
    }

    void addHead(int num){
        node* n = new node();
        n->elem = num;
        if(!head){
            head = tail = n;
        } else {
            head->prev = n;
            n->next = head;
        }

        head = n;
        size++;
    }

    void addTail(int num){
        node* n = new node();
        n->elem = num;
        n->next = nullptr;
        if(tail){
            n->prev = tail;
            tail->next = n;
        } else {
            head = n;
            //head->prev = nullptr;
        }

        tail = n;
        size++;
    }

    int get(int num){
        node* temp = head;
        int pos = 1;
        while(temp){
            if(temp->elem==num){
                return pos;
            }
            pos++;
            temp = temp->next;
        }
        return -1;
    }

    int remove(int num){
        node* temp = head;
        int pos = 1;
        while(temp){
            if(temp->elem==num){
                if(temp==head){
                    if(head==tail){
                        head = tail = nullptr;
                    } else {
                        head = head->next;
                        head->prev = nullptr;
                    }
                } else if (temp==tail){
                    tail = tail->prev;
                    tail->next = nullptr;
                } else {
                    temp->next->prev = temp->prev;
                    (temp->prev)->next = temp->next->next;
                }
                delete temp;
                size--;
                return pos;
            }
            pos++;
            temp = temp->next;
        }
        return -1;
    }

    int removeAt(int pos){
        node* temp = head;
        int val;
        if(pos>size){
            return -1;
        }

        if(pos==1){
            if(head==tail){
                val = head->elem;
                head = tail = nullptr;
                
            } else {
                val = head->elem;
                head = head->next;
                head->prev = nullptr;
            }
        } else if(pos==size){
            val = tail->elem;
            tail = tail->prev;
        } else {
            for (int i = 1; i<=pos-1; i++){
                temp = temp->next;
            }
        }

        val = temp->elem;
        temp->next->prev = temp->prev;
        (temp->prev)->next = temp->next->next;
        free(temp);
        return val;

    }

    void addMid(int num){
        node* temp = head;
        node* n = new node();
        n->elem = num;

        if(!head){
            head = tail = n;
            size++;
            return;
        } else if(size==1){
            n->next = head;
            head->prev = n;
            head = n;
            size++;
            return;
        }
        for (int i = 1; i<size/2; i++){
            temp = temp->next;
        }
        temp->next->prev = n;
        n->next = temp->next;
        n->prev = temp;
        temp->next = n;

        size++;
    }

    int removeAll(int num){
        node* temp = head;
        int count = 0;
        while(temp){
            node* toDelete = temp;
            if(temp->elem == num){
                if(temp==head){
                    if(head==tail){
                        head = tail = nullptr;
                    } else {
                        head = head->next;
                    }
                } else if(temp==tail){
                    tail = tail->prev;
                    tail->next = nullptr;
                } else {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                }
                temp = temp->next;
                free(toDelete);
                size--;
                count++;
            } else {
                temp = temp->next;
            }
        }
        return count;
    }

    void print(){
        node* temp = head;
        if(size==0){
            cout << "Empty." << endl;
        } else {
            do {
                cout << temp->elem;
                if(temp!=tail){
                    cout << " -> ";
                }
                temp = temp->next;
            } while(temp);
        }
        cout << endl;
    }

    void reversePrint(){
        node* temp = tail;
        if(size==0){
            cout << "Empty." << endl;
        } else {
            do {
                cout << temp->elem;
                if(temp!=head){
                    cout << " -> ";
                }
                temp = temp->prev;
            } while(temp);
        }
        cout << endl;
    }
    

};