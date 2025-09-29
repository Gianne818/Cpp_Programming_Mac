#include <stack>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

int  postFix(vector<string>);

int main (){
    vector<string> s = {"-5", "6", "+"};
    int res = postFix(s);
    if(res==-1){
        cout << "Invalid input."<< endl;
    } else {
        cout << "Res: " << res << endl;
    }

}

int postFix(vector<string> pf){
    stack<int> s;
    int size = (pf).size();

    if(size<=2 || !isdigit((pf[0][0])) || (size>=2 && !isdigit(pf[1][0]))){
        return -1;
    }

    for (int i = 0; i<size; i++){
        if((isdigit(pf[i][0]) || isdigit(pf[i][1]) && pf[i][0]=='-')){
            s.push(stoi(pf[i]));
        } else {
            char c = pf[i][0];
            int stackSize = s.size();
            if(stackSize<2) return s.top();

            int second = s.top();
            s.pop(); 
            
            int first = s.top();
            s.pop();
            

            switch(c){
                case '+':
                    s.push((first+second));
                    cout << "add Res: " << first+second << " size: " << stackSize << endl;
                    break;

                case '-':
                    s.push((first-second));
                    cout << "add Res: " << first-second << " size: " << stackSize << endl;
                    break;

                case '*':
                    s.push((first*second));
                    cout << "add Res: " << first*second << " size: " << stackSize << endl;
                    break;

                case '/':
                    s.push((first/second));
                    cout << "add Res: " << first/second << " size: " << stackSize << endl;
                    break;
            }
            
        }
    }
    return s.top();
}

// bool isValid(string s){
//     Stack* charStack = new Stack();
//     int size = s.length();
//     if(size%2!=0 || size==0){
//         return false;
//     }
//     for (int i = 0; i<size; i++){
//         if(s[i]=='{' || s[i]=='(' || s[i]=='['){
//             charStack->push(s[i]);
//         }

//         else if((s[i]=='}' && charStack->top()=='{') || 
//         (s[i]==']' && charStack->top()=='[') || 
//         (s[i]==')' && charStack->top()=='('))
//         {
//             charStack->pop();
//         } else {
//             return false;
//         }
//     }
//     return true;
// }