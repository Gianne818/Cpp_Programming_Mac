#include <string>
using namespace std;

struct node {
	string elem;
	node* left;
	node* right;
	node* parent;

    // TODO evaluate method
    int evaluate() {
        int answer = 0;
        if(isdigit(this->elem[0])){
            return stoi(this->elem);
        }
        
        if(this->elem[0]=='+' || this->elem[0]=='-' || this->elem[0]=='*' || this->elem[0]=='/'){
            int b = this->right->evaluate();
            int a = this->left->evaluate();
            if(this->elem[0]=='+'){
                return a + b;
            }
            if(this->elem[0]=='-'){
                return a - b;
            }
            if(this->elem[0]=='*'){
                return a * b;
            }
            if(this->elem[0]=='/'){
                return a / b;
            }
        }
    return -1;
    }
};