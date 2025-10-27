#include <iostream>
#include "../BinTreeString.hpp"
using namespace std;

node* opInput(BinTree* tree, string prompt, node* parent);

int main(void) {
    BinTree* tree = new BinTree();
    char op;
    int input, ind;
    node* nodes[100];
    int res;
    
    tree->setRoot(opInput(tree, "root", NULL));
    try {
        do {
            cout << "Op: ";
            cin >> op;
            switch (op) {
                case 'p':
                    tree->print();
                    break;
                case 'e':
                    cout << "Answer: " << tree->evaluate() << endl;
                    break;
                case 'x':
                    cout << "Exiting" << endl;
                    break;
                default:
                    cout << "Invalid operation" << endl;
            }
        } while (op != 'x');
    } catch (exception& e){
        e.what();
    }
    
    return 0;
}

node* opInput(BinTree* tree, string prompt, node* parent) {
    string input;
    node* n = nullptr;
    cout << "Enter " << prompt << ": ";
    cin >> input;
    switch (input[0]) {
        // TODO add cases for operations and default case for numbers
        case '+':
        case '-':
        case '/':
        case '*':

            n = new node();
            n->parent = nullptr;
            n->elem = input;
            n->left = nullptr;
            n->right = nullptr;

            n->left = opInput(tree, "left of " + n->elem, n);
            n->right = opInput(tree, "right of " + n->elem, n);
            break;
            
        default:
            n = new node();
            n->parent = nullptr;
            n->elem = input;
            n->left = nullptr;
            n->right = nullptr;   

            if(parent){
                if(!parent->left){
                    tree->addLeft(parent, input);
                } else if (!parent->right){
                    tree->addRight(parent, input);
                }
            }
            break;
    }
    return n;
    
}