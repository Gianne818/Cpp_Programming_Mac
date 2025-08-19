#include <iostream>
#include <stack>
using namespace std;

void displayStack(stack<int> st){
    while(!st.empty()){
        cout << st.top() << endl;
        st.pop();
    }
}

int main (){
    //empty, full, push, pop, seek, size, display
    stack<int>numStack;
    numStack.push(1);
    numStack.push(2);
    numStack.push(3);

    displayStack(numStack);
    displayStack(numStack);

    if(numStack.empty()){
        cout << "Stack is empty.\n";
    } else {
        cout << "Stack is not empty.\n";
    }
    
    cout << "Stack size: " << numStack.size() << endl;

}