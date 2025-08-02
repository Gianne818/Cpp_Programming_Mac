#include <iostream>
using namespace std;

//In a linear linked list, you only have 3 places to add a node. Beginning, at the end, and after a node.
//In doubly linked list, you can add nodes in four places. In the beginning, at the end, afte a node, and before a node.
//In singly linked list, you can only go forward, whereas in doubly linked list, you can go back.
//We have *next and *prev, so doubly linked list take up more space.
//Prefer singly linked list if you have memory limitations, and you will not perform a lot of searching, deleting, and inserting nodes.
//Prefer doubly linked list if you don't have memory limitations, and you will perform a lot of searching, deleting, and inserting nodes.

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node (int data){
        this->data = data;
        next = nullptr;
        prev = nullptr;
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
    cout << "Data not found in the list.\n";
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
        newNode->prev = tail;
        tail->next = newNode; //connect tail with newNode;
        tail = newNode;
        // *tail now points to newNode. This does not alter the data held initally by tail.
        //tail is now the newNode that we created, while modifying only the ->next to point to the newNode.
    }
}

void LinkedList::insertAtBeginning(int data){
    Node* newNode = new Node(data);
    if(head==nullptr){
        head = tail = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;

}

void LinkedList::insertAfter(int index, int newData){
    if(index < 0){
        cout << "Invalid.";
        return;
    }

    Node* newNode = new Node(newData);
    if(head==nullptr){
        cout << "List is empty. Inserting as first element.\n";
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
    newNode->prev = previous; //set previous->next to hold the address of newNode
    previous->next = newNode;
    if(newNode->next==nullptr){
        tail = newNode;
    } else {
        (newNode->next)->prev = newNode;
    }
}

void LinkedList::removeNode(int index){
    if(head==nullptr){
        cout << "List is empty.\n";
        return;
    }

    if(index<0){
        cout << "Invalid index.\n";
        return;
    }

    Node* temp = head;
    
    if(index==0){
        head = head->next;
        if(head!=nullptr){
            head->prev = nullptr;
        }
        delete temp;
        return;
    }

    int ctr = 0;
    while(temp!=nullptr && ctr<index){
        temp = temp->next;
        ctr++;
    }

    if(temp==nullptr){
        cout << "Index out of range.\n";
        return;
    }

    if (temp->prev != nullptr) {
        temp->prev->next = temp->next;
    }
    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }

    if (temp->next == nullptr) {
        head = temp->prev;
    
    }

    delete temp; //since *node holds an address, deleting temp will also delete the value stored at the address.
    temp = nullptr;
}

int main (){
    LinkedList l1;
    l1.insertAtEnd(1);
    l1.insertAtEnd(2);
    l1.insertAtEnd(3);
    l1.displayNode();
    l1.searchForValue(3);

    cout << "After insertions:\n";
    l1.insertAtBeginning(999);
    l1.insertAfter(4, 55); //index is 0-based;
    l1.displayNode();

    cout << "\n\nAfter removing node:\n";
    l1.removeNode(1);
    l1.displayNode();

    // l1.insertAtBeginning(999);
    // l1.insertAtEnd(1);
    // l1.insertAtEnd(2);
    // l1.insertAtEnd(3);
    // l1.insertAfter(3, 4);
    // l1.displayNode();

}