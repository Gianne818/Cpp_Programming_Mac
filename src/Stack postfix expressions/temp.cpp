#include <stack>
#include <cctype>
#include <cstdlib>
#include <iostream>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int size = tokens.size();
        int res = 0;

        for (int i = 0; i<size; i++){
            if(isdigit(tokens[i][0]) || isdigit(tokens[i][1])){
                int temp = stoi(tokens[i]);
                s.push(temp);
            }
            else {
                //navigate stack
                char c = tokens[i][0];
                int stackSize = s.size();
                if(stackSize<2) return s.top();

                int second = s.top();
                s.pop();
                int first = s.top();
                s.pop();

                switch(c){
                    case '+':
                        res = first+second;
                        s.push(res);
                        cout << "add Res: " << res << " size: " << stackSize << endl;
                    break;

                    case '-':
                        res = first-second;
                        s.push(res);
                        cout << "minus Res: " << res << " size: " << size << endl;
                    break;

                    case '*':
                        res = first*second;
                        s.push(res);
                        cout << "multiply Res: " << res << " size: " << size << endl;
                    break;

                    case '/':
                        res = first/second;
                        s.push(res);
                        cout << "divide Res: " << res << " size: " << size << endl;
                        break;
                }
            }
        }
    return s.top();
    }   
};

int main() {
    Solution solution;
    vector<string> tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout << "Result: " << solution.evalRPN(tokens) << endl;  // Output: 9
    return 0;
}
