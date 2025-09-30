// #include "Stack.hpp"
// #include "Queue.hpp"
// #include <string>
// #include "StackInt.cpp"
// #include <sstream>
// using namespace std;

// bool isValid(string);
// int postEval(string);
// string makeInfix(string);
// int postEval(string s[5]);

// int main (){
//     cout << "--------Balanced Parentheses-------\n";
//     string s;
//     cout << "Enter parentheses: ";
//     cin >> s;
//     bool res = isValid(s);
//     if(res){
//         cout << "Valid.\n";
//     } else {
//         cout << "Invalid.\n";
//     }
    
//     cout << "--------Queue-------\n";
    
//     Queue* q = new Queue();
//     char op;
//     int n;
    
//     cout << "Options\n";
//     cout << "a. Enqueue\n" << "b. Dequeue\n" << "c. Print\n" << "d. Peek\n";
//      do {
//         cout << "Enter option: ";
//         cin >> op;
//         switch(op){
//             case 'a':
//                 cout << "Enter value to enqueue: ";
//                 cin >> n;
//                 q->enqueue(n);
//                 break;

//             case 'b':
//                 n = q->dequeue();
//                 if(n){
//                     cout << "Removed value: " << n << endl;
//                 } else {
//                     cout << "Empty.\n";
//                 }
//                 break;
//             case 'c':
//                 q->print();
//                 break;
                
//             case 'd':
//                 cout << "Front value: " << q->peek() << endl;
//             default:
//                 cout << "Error option.\n";
//         } 
//     } while(op!='x');
    
    
//     cout << "--------Postfix evaluation-------\n";
//     string pf, token, noSpace;
//     cout << "Enter postfix string: ";
//     getchar();
//     getline(cin, pf);
    
//     stringstream ss(pf);
//     while(ss >> token){
//         noSpace += token;
//     }
    
//     int res2 = postEval(noSpace);
//     cout << "Result: " << res2 << endl;
    
//     cout << "--------Making it infix-------\n";
//     string res3 = makeInfix(noSpace);
//     cout << "Result: " << res3 << endl;
    
//     cout << "--------Postfix evaluation array of string-------\n";
//     string arr[5] = {"9", "3", "2", "+", "*"};
//     int res4 = postEval(arr);
//     cout << "Result: " << res4 << endl;
    
    
    
    
// }

// string makeInfix(string s){
//     Stack* st = new Stack();
//     int size = s.length();
//     string temp;
//     for (int i = 0; i<size; i++){
//         if(s[i]!= '+' && s[i]!= '-' && s[i]!= '*' && s[i]!= '/'){
//             st->push(s[i]); //9 3 2 + *
//         } else {
//             char op = s[i];
//             char b = st->top(); st->pop();
//             char a = st->top(); st->pop();
//             temp += a;
//             temp+= op;
//             temp+=b;
//         }
//     }
//     return temp;
// }

// int postEval(string s){
//     StackInt* st = new StackInt();
//     int size = s.length();
    
//     for (int i = 0; i<size; i++){
//         if(isdigit(s[i])){
//             st->push(s[i] - '0');
//         } else {
//             char c = s[i];
//             int stSize = st->size;
//             if(stSize<2) break;
//             int b = st->top(); st->pop();
//             int a = st->top(); st->pop();
            
//             switch(c){
//                 case '+': st->push(a+b); break;
//                 case '-': st->push(a-b); break;
//                 case '*': st->push(a*b); break;
//                 case '/': st->push(a/b); break;
//             }
//         }
//     }
//     return st->top();
// }

// int postEval(string s[5]){
//     StackInt* st = new StackInt();
//     //int size = s.length();
    
//     for (int i = 0; i<5; i++){
//         string temp = s[i];
//         if(isdigit(temp[0]) || (temp.length() >= 2 && isdigit(temp[1]))){
//             st->push(stoi(s[i]));
//         } else {
//             int stSize = st->size;
//             char c = temp[0];
//             if(stSize<2) return st->top();
//             int b = st->top(); st->pop();
//             int a = st->top(); st->pop();
            
//             switch(c){
//                 case '+': st->push(a+b); break;
//                 case '-': st->push(a-b); break;
//                 case '*': st->push(a*b); break;
//                 case '/': st->push(a/b); break;
//             }
//         }
//     }
//     return st->top();
// }

// bool isValid(string s){
//     Stack* st = new Stack();
//     int size = s.length();
    
//     if(size%2!=0 || size < 2) return false;
    
//     for (int i = 0; i<size; i++){
//         if(s[i]=='{' || s[i]=='[' || s[i]=='('){
//             st->push(s[i]);
//         } 
        
//         else if((s[i]=='}' && st->top()=='{') || (s[i]==']' && st->top()=='[') || (s[i]==')' && st->top()=='(')){
//             st->pop();
//         } 
        
//         else {
//             return false;
//         }
//     }
//     return true;
// }
// --------------------------------------------------------------------
// #include "ArrayList.hpp"
// using namespace std;


// class Stack : public ArrayList{
// public:

//     void push(char c){
//         if(size==cap){
//             resizeUp();
//         }
//         array[size++] = c;
//     }

//     void pop(){
//         if(size==0){
//             return;
//         }
//         size--;
//         if(size<=floor(cap * 2.0/3.0)){
//             resizeDown();
//         }
//     }

//     char top(){
//         return array[size-1];
//     }


// };
// -------------------------------------------------
// #include <cstdlib>
// #include <iostream>
// using namespace std;

// struct node{
//   int elem;
//   node* next;
// };

// class Queue{
//   int size;
//   node* front, *rear;
  
// public:
//     Queue(){
//         size = 0;
//         front = nullptr;
//         rear = nullptr;
//     }
    
//     void enqueue(int num){
//         node* n = new node();
//         n->elem = num;
//         if(rear){
//             rear->next = n;
//         } else {
//             front = n;
//         }
        
//         n->next = nullptr;
//         rear = n;
//         size++;
//     }
    
//     int dequeue(){
//         if(!front){
//             return -1;
//         } 
        
//         node* temp = front;
//         int val = temp->elem;
        
//         if(front==rear){
//             front = rear = nullptr;
//             free(temp);
//             size--;
//             return val;
//         }
        
//         front = front->next;
//         free(temp);
//         size--;
//         return val;
//     }
    
//     int peek(){
//         if(size==0) return -1;
//         return front->elem;
//     }
    
//     void print(){
//         node* temp = front;
//         while(temp){
//             cout << temp->elem << " ";
//             temp = temp->next;
//         }
//         cout << endl;
//     }
// };
// ------------------------------------------------------
// #include <iostream>
// #include <math.h>
// #include <algorithm>
// using namespace std;

// class ArrayList{
// public:
//     int size;
//     char* array;
//     int cap;

// public:

//     void resizeUp(){
//         int newCap = ceil(cap*1.5);
//         cap = newCap;
//         array = (char*)realloc(array, cap*sizeof(char));
//     }

//     void resizeDown(){
//         int newCap = ceil(cap*0.75);
//         cap = max(newCap, 5);
//         array = (char*)realloc(array, cap*sizeof(char));
//     }

//     ArrayList(){
//         size = 0;
//         cap = 5;
//         array = (char*)malloc(cap*sizeof(char));
//     }
// };
// ---------------------------------------------------------------
// #include "Stack.hpp"
// using namespace std;

// string rev(string);

// int main (){
//     string s;
//     cout << "Enter a string: ";
//     getline(cin, s);
//     string reverse = rev(s);
//     cout << reverse;
// }

// string rev(string s){
//     Stack* st = new Stack();
//     string temp;
//     int size = s.length();
    
//     for (int i = 0; i<size; i++){
//         st->push(s[i]);
//     }
    
//     for (int i = 0; i<size; i++){
//         temp  += st->top();
//         st->pop();
//     }
    
//     return temp;
// }