#include <iostream>
#include <string>
using namespace std;

//Linked Lists is a list they are connected/linked to each other.
//Each node of the list contains a data value and a pointer to the next element
//The biggest difference of a linked list from an array is that linked lists are stored randomly on the memory
//Whereas arrays are of fixed size, a linked list is not. 
//However, linked lists have higher memory usage.
//Linked lists can grow and shrink dynamically without resizing or knowing the size in advanced, which is why yhey can be more efficient.
//Vectors on the other hand, require manual reallocation when they reach capacity, and can be expensibe (Allocate new mem, copy elem, free old mem.)
//Datas that have a lot of shifting in size will be good for linked lists.
//Linked lists are preferred for their efficient insertion and deletion operations, especially when compared to array-based structures.

//Adding/removing nodes at head/tail can be done in constant time O(1)
//Nodes are accessed sequentially, making search oeprations linear time O(n)

//Create a struct or class
struct Node {
public:
    int data;
    Node* next;
};

void displayNodeElem(Node* n){
    while(n!=nullptr){
        cout << n->data << endl;
        n = n->next;

    }
}

Node* createNode(int data, Node* last){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    last->next = newNode;
    return newNode;
}

void insertAtFront(Node** head, int newData ){
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = *head;
    *head = newNode;
}

void insertAtLast(Node** head, int newData){
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = nullptr;

    if(*head == nullptr) {
        *head = newNode;
        return;                    
    }

    Node* tail = *head;
    while(tail->next!=nullptr){
        tail = tail->next;
    }

    tail->next = newNode;
           
}  

void insertAfter(Node* previous, int newData){
    Node* newNode = new Node();
    newNode->data = newData; 

    if(previous->next==nullptr){
        cout << "\nYou are inserting at the last..." << endl;
        newNode->next = nullptr;
        previous->next = newNode;
    } else {
        newNode->next = previous->next;
        previous->next = newNode;
    }
   
}

int main (){
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();
    Node* fourth = new Node();
    Node* fifth = new Node();


    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = fifth;

    fifth->data = 5;
    fifth->next = nullptr;

    insertAtFront(&head, 0);
    insertAtLast(&head, 6); //You can skip the while loop if you input &tail element as parameter instead of &head
    insertAfter(head, 11);
    displayNodeElem(head);
}