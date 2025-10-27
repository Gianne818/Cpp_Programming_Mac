#include <iostream>
#include "list.hpp"
using namespace std;

class linkedList : public list{
    int size;
    node head, tail;
    
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
        n->prev->next = n->next;
        n->next->prev = n->prev;

        int val = n->elem; 
        free(n);
        size--;
        return val;
    }

    // int removeNode(node* n){
      
        
    //     size--;
    //     return (n->prev->next = n->next, n->next->prev = n->prev, n->elem, delete n, n->elem);
    // }

    

    public:

    linkedList(){
        size = 0;
        head.next = &tail;
        tail.prev = &head;

        head.prev = nullptr;
        tail.next = nullptr;
    }

    void add(int num){
        addBetween(num, tail.prev, &tail);
    }

    void addHead(int num){
        addBetween(num, &head, head.next);
    }

    void addTail(int num){
        addBetween(num, tail.prev, &tail);
    }

    int get(int pos){
        if(pos < 1 || pos > size || size==0) return -1;
        node* temp = head.next;
        int ctr = 1;
        while(ctr<pos){
            temp = temp->next;
            ctr++;
        }
        return temp->elem;
    }

    int remove(int num){
        node*temp = head.next;
        int pos = 1;
        while(temp!=&tail){
            if(temp->elem == num){
                removeNode(temp);
                return pos;
            }
            pos++;
            temp = temp->next;
        }
        return -1;
    }

    int removeAt(int pos){
        node* temp = new node();
        if(pos < 1 || pos > size || size == 0) return -1;
        if(pos<size/2){
            temp = head.next;
            for (int i = 1; i < pos; i++){
                temp = temp->next;
                cout << "from head\n";
            }
            
            
        }
        else {
            temp = tail.prev;
            for (int i = size; i > pos; i--){
                temp = temp->prev;
                cout << "from tail\n";
            }
        }
        
        return removeNode(temp);
    }

    int removeAll(int num){
        node* temp = head.next;
        int count = 0;
        while(temp!=&tail){
            node* toDelete = temp;
            if(temp->elem == num){
                temp = temp->next;
                removeNode(toDelete);
                count++;
            } else {
                temp = temp->next;
            }
        }
        return count;
    }

    void addMid(int num){
        node* temp = head.next;
        for (int i = 1; i<size/2; i++){
            temp = temp->next;
        }
        addBetween(num, temp, temp->next);
    }

    void addAt(int num, int pos){
        if (pos<1 || pos>size){
            cout << "Invalid position.";
            return;
        }
        node* n = new node();
        n->elem = num;
        node* temp = head.next;
        int ctr = 1;
        while(ctr<pos){
            temp = temp->next;
            ctr++;
        }
        addBetween(num, temp->prev, temp);
    }
    
    void print(){
        node* temp = head.next;
        if(size==0){
            cout << "Empty." << endl;
        } else {
            do {
                cout << temp->elem;
                if(temp!=tail.prev){
                    cout << " -> ";
                }
                temp = temp->next;
            } while(temp!=&tail);
        }
        cout << endl;
    }

    void reversePrint(){
        node* temp = tail.prev;
        if(size==0){
            cout << "Empty." << endl;
        } else {
            do {
                cout << temp->elem;
                if(temp!=head.next){
                    cout << " -> ";
                }
                temp = temp->prev;
            } while(temp!=&head);
        }
        cout << endl;
    }
};