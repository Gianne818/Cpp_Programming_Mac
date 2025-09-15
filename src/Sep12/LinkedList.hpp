#include <iostream>
#include "List.hpp"
using namespace std;

class LinkedList : public List{
public: 
    int size;
    Node* head;
    Node* tail;

    LinkedList(){
        this->head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void add (int num){
        Node* n = new Node();
        n->elem = num;

        if(tail){
            tail->next = n;
        } else {
            head = n;
        }
        tail = n;
        n->next = NULL;
        size++;
    }

    void print(){
        cout << endl;
        cout << "Size: " << size << endl;
        Node* temp = head;
        while(temp!=NULL){
            cout << temp << " : " << temp->elem << endl;
            temp = temp->next;
        }
        cout << endl;
    }

    int removeHead(){
        if(!head) {
            tail=nullptr;
            return 0;
        }
        Node* temp = head;
        int val = temp->elem;

        head = head->next;
        delete temp;
        size--;
        return val;
    }

    int removeTail(){
        if(!head){
            return 0;
        }

        int val = tail->elem;
        if(head==tail){
            delete tail;
            head = nullptr;
            tail = nullptr;
            size--;
            return val;
        }

        Node* temp = head;
        while(temp->next!=tail){
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = nullptr;
        size--;
        return val;
    }

    Node* find(int num){
        Node* temp = head;
        while(temp){
            if(temp->elem == num){
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }

    ~LinkedList(){
        cout << "DESTRUCT" << endl;
        while(head){
            Node* temp = head;
            head = temp->next;
            delete temp;
        }
    }
};



