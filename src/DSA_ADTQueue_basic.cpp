#include <iostream>
using namespace std;

//Queue is a linear data structure that follows the FIFO priciple.
//FIFO - First In First Out
//Just like in how people line up for some servuce, the first person in line gets to go out first.
//The first element added is the first element to be removed.
//Useful in scenarios like task scheduling, resource allocation, and buffering.
//Queue abstracts the data structure's implementation details, focusing on possible operations.
//The following is an array implementation, but this can also be implemented using linked lists.

#define MAX 5

class Queue{
    int items[MAX];
    int numItems; //current size
    int front; //index of the oldest/first element
    int rear; //index of the newest/last element

public:
    Queue() : numItems(0), front(0), rear(-1){} //rear is initalized to index -1 so that when we add new element, it becomes index 0
    void enqueue(int newData);
    void dequeue();
    bool isEmpty();
    bool isFull();
    void displayQueue();
};

bool Queue::isFull(){
    return numItems == MAX;
}

bool Queue::isEmpty(){
    return numItems == 0;
}

void Queue::enqueue(int newData){
    if(isFull()){
        cout << "Queue is full. Cannot add more items.\n";
        return;
    }
    rear = (rear+1)%MAX; //Circular increment so that rear does not exceed MAX
    items[rear] = newData;
    cout << "Successfully enqueued: " << items[rear] << endl;
    numItems++;
}

void Queue::dequeue(){
    if(isEmpty()){
        cout << "Queue is empty. Cannot remove item.";
        return;
    }
    cout << "Successfully dequeued: " << items[front] << endl;
    front = (front+1)%MAX; //Circular increment so that front does not exceed MAX
    numItems--;
}

void Queue::displayQueue(){
    cout << "Queue:\n";
    for (int i = 0; i<numItems; i++){
        cout << items[(front+i)%MAX] << endl;
    }
}

int main (){
    Queue q1;
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.enqueue(5);
    q1.enqueue(6);
    q1.displayQueue();
    cout << endl << endl;

    

    q1.dequeue();
    q1.displayQueue();
    q1.dequeue();
    q1.displayQueue();
    q1.dequeue();
    q1.displayQueue();
    q1.dequeue();
    q1.displayQueue();
    q1.dequeue();
    q1.displayQueue();
    q1.dequeue();
    
    cout << endl << endl;

    
}