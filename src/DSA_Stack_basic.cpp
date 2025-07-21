#include <iostream>
#include <stdlib.h>
using namespace std;

//Stack data structure is a linear data structure that follows the principle LIFO to store elements.
//Last in, First out. Like a stack of plate. 
//If you want to add a plate, you add it on top, and if you want to take out a plate out, you take the one on top.
//The last element added is the first to be removed.
//It restricts adding or removing elements to only one end called the top.
//Example is undo and redo.

#define MAX 5

class Stack {
private:
    int top;
    int items[MAX];
public:
    Stack () : top(-1){}
    bool isEmpty();
    bool isFull();
    void push(int newItem);
    void pop();
    int peek();
    int sizeOfStack() const;
    void displayStack();
};

bool Stack::isEmpty(){
    return top == -1;
}

bool Stack::isFull(){
    return top == MAX-1;
}

void Stack::push(int newItem){
    if(isFull()){
        cout << "Stack is full. Unable to add elements.\n";
        return;
    }
    items[++top] = newItem;
    cout << "Successfully added: " << items[top] << endl;
}

void Stack::pop(){
    if(isEmpty()){
        cout << "Stack is empty. Unable to remove elements.\n";
        return;
    }
    cout << "Successfully removed: " << items[top] << endl;
    --top;
}

int Stack::peek(){
    if(isEmpty()){
        cout << "Stack is empty.";
        return -1;
    }
    return items[top];
}

int Stack::sizeOfStack() const {
    return top+1;
}

void Stack::displayStack(){
    cout << "The stack:\n";
    for (int i = 0; i<=top; i++){
        cout << items[i] << endl;
    }
}

int main (){
    Stack s1;
    (s1.isEmpty() ? cout << "Stack is empty.\n" : cout << "Stack is not empty.\n");
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    s1.push(6);
    s1.push(7);

    s1.pop();
    s1.push(8);
    cout << "Last element: " << s1.peek() << endl;

    s1.pop();
    s1.push(5);
    cout << "Size of stack: " << s1.sizeOfStack() << endl;
    s1.displayStack();

    s1.push(6);
    cout << "Size of stack: " << s1.sizeOfStack() << endl;
    
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    cout << "Size of stack: " << s1.sizeOfStack() << endl;
}