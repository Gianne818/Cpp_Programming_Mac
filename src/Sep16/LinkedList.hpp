#include "List.hpp"
#include <iostream>
using namespace std;

class LinkedList : public List{
private:
    int size = 0;
    Node* head, *tail;

public:
    LinkedList(){
        size = 0;
        head = tail = nullptr;
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
        n->next = nullptr;
        size++;
    }

    void print(){
        Node* temp = head;
        cout << endl;
        int index = 0;
        cout << "Size: " << size << endl;
        while(temp){
            cout << "Node " << index << ": " << temp->elem << " - " << temp << endl;
            temp = temp->next;
            index++;
        }
        cout << endl;
    }

    int removeHead(){
        if(!head){
            tail = nullptr;
            return -1;
        }
        int val = head->elem;

        if(head->next == nullptr){
            head = tail = nullptr;
            delete head;
            size--;
            return val;
        }
        
        Node* temp = head;
        head = temp->next;
        delete temp;
        size--;
        return val;
    }

    int removeTail(){
        if(!head){
            tail = nullptr;
            return -1;
        }

        int val = tail->elem;
        if(head==tail){
            delete head;
            head = tail = nullptr;
            //tail=nullptr;
            size--;
            return val;
        }

        Node* temp = head;
        while(temp->next!=tail){
            temp = temp->next;
        }
        
        delete temp->next;
        tail = temp;
        tail->next = nullptr;
        size--;

        return val;
    }

    Node* find(int num){
        Node* temp = head;
        int index = 0;
        while(temp){
            if(temp->elem == num){
                cout << "Index number: " << index << " - ";
                return temp;
            }
            index++;
            temp = temp->next;
        }

        return nullptr;
    }

    void insertAt(int pos, int num){
        Node* n = new Node();
        n->elem = num;
        if(pos>size+1 || pos < 1){
            cout << "Error. Entered position is greater than size.\n";
            return;
        }

        
        if(!head){
            head = n;
            tail = n;
            n->next = nullptr;
            cout << "List is empty. Added at the beginning instead.\n";
            size++;
            return;
        }

        if(pos==1){
            n->next = head;
            head = n;
            size++;
            return;
        }

        if(pos==size+1){
            tail->next = n;
            tail = n;
            n->next = nullptr;
            size++;
            return;
        }
        Node* temp = head;
        for (int i = 1; i<pos-1; i++){
            temp = temp->next;
        }
        n->next = temp->next;
        temp->next = n;
        size++;

    }

    int removeAt(int pos){
        if(!head){
            cout << "List is empty.\n";
            return -1;
        }
        
        if(pos<1 || pos>size){
            return -1;
        }

        if(pos==1){
            return removeHead();
        }

        if(pos==size){
            return removeTail();
        }

        Node* prev = head;
        for (int i = 1; i<pos-1; i++){
            prev = prev->next;
        }

        Node* temp = prev->next;
        int val = temp->elem; //temp is the node to delete

        prev->next = temp->next;
        delete temp;
        size--;
        return val;

    }

    int removeAll(int num){
        int pos = 1;
        int count = 0;
        Node* temp = head;
        while(temp){
            if(temp->elem == num){
                removeAt(pos);
                count++;
                temp = head;
                for (int i = 1; i<pos; i++){
                    temp = temp->next;
                }
            } else {
                temp = temp->next;
                pos++;
            }
        }
        return count;
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