#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node (int data){
        this->data = data;
        next = nullptr;
    }
};

class LinkedList {
private: 
    Node* head;
    Node* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr){}

    void displayNode();
    void insertAtEnd(int data);
    void insertAtBeginning(int data);
    bool searchForValue(int data); //return true if found
    void insertAfter(int index, int newData);
    void removeNode(int index);
    
    
}; 

bool LinkedList::searchForValue(int data){
    Node* cur = head;
    int ctr = 0;
    while(cur!=nullptr){
        if(cur->data==data){
            cout << "Data found on: " << &cur << endl;
            cout << "It is on index: " << ctr << endl << endl;
            return true;
        }
        cur = cur->next;
        ctr++;
    }
    return false;
}

void LinkedList::displayNode(){
    Node* temp = head;
    while(temp!=nullptr){
        cout << temp->data << endl;
        temp = temp->next;
    }
}

void LinkedList::insertAtEnd(int data){
    Node* newNode = new Node(data);
    if(head==nullptr){
        head = newNode;
        tail = head;

    } else {
        tail->next = newNode; //connect tail with newNode;
        tail = newNode;
        // *tail now points to newNode. This does not alter the data held initally by tail.
        //now, only the previous node from the original tail knows how to access the tail.
        //tail is now the newNode that we created, while modifying only the ->next to point to the newNode.
    }
}

void LinkedList::insertAtBeginning(int data){
    Node* newNode = new Node(data);
    if(head==nullptr){
        head = tail = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;

}

void LinkedList::insertAfter(int index, int newData){
    if(index < 0){
        cout << "Invalid.";
        return;
    }

    Node* newNode = new Node(newData);
    if(head==nullptr && index == 0){
        head = tail = newNode;
        return;
    }

    Node* previous = head; 
    int i = 0;
    for (; i<index; i++){
        previous = previous->next;  //iterate through the list while i<index. Sets previous to the index inputted when loop terminates
        //terminate loop after reaching last elem which happens when index > numberOfList
        if(previous==nullptr){
            cout << "Invalid index. Insertion aborted.\n";
            delete newNode;
            return;
        }
    }
    
    newNode->next = previous->next; //set newNode->next to the node that comes after newNode, which was the Node previously linked to previous->next     
    previous->next = newNode; //set previous->next to hold the address of newNode
    if(newNode->next==nullptr){
        tail->next = newNode;
        tail = newNode;
    }
}

void LinkedList::removeNode(int index){
    int ctr = 0;
    Node* temp = head;
    Node* prev = nullptr;

    if(index==0){
        head = temp->next;
        delete temp;
        return;
    }
    if(index<0){
        cout << "Invalid\n";
        return;
    }

    while(temp!=nullptr && ctr<index){
        ctr++;
        prev = temp;
        temp = temp->next;
    }

    if(index>ctr || temp==nullptr){
        cout << "Index out of range.\n";
        return;
    }
    prev->next = temp->next;
    delete temp;
}

int main (){
    LinkedList l1;
    // l1.insertAtEnd(1);
    // l1.insertAtEnd(2);
    // l1.insertAtEnd(3);
    // l1.displayNode();
    // l1.searchForValue(3);

    // cout << "After insertions:\n";
    // l1.insertAtBeginning(999);
    // l1.insertAfter(4, 55); //index is 0-based;
    // l1.displayNode();

    // cout << "\n\nAfter removing node:\n";
    // l1.removeNode(5);
    // l1.displayNode();

    l1.insertAtBeginning(999);
    l1.insertAtEnd(1);
    l1.insertAtEnd(2);
    l1.insertAtEnd(3);
    l1.insertAfter(3, 4);
    l1.displayNode();

}