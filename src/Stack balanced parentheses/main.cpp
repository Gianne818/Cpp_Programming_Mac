#include "Stack.hpp"
using namespace std;

bool isValid(string);

int main (){
    string s;
    cout << "Enter parentheses: ";
    cin >> s;
    bool res = isValid(s);
    if(res){
        cout << "Valid.\n";
    } else {
        cout << "Invalid.\n";
    }
}

bool isValid(string s){
    Stack* st = new Stack();
    int size = s.length();
    
    if(size%2!=0 || size < 2) return false;
    
    for (int i = 0; i<size; i++){
        if(s[i]=='{' || s[i]=='[' || s[i]=='('){
            st->push(s[i]);
        } 
        
        else if((s[i]=='}' && st->top()=='{') || (s[i]==']' && st->top()=='[') || (s[i]==')' && st->top()=='(')){
            st->pop();
        } 
        
        else {
            return false;
        }
    }
    return true;
}