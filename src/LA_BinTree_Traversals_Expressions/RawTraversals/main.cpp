#include "../BinaryTree.hpp"
using namespace std;

int main (){
    GenTree* tree = new BinTree();
    char op;
    int num;
    int num2;
    node* parent;

    cout << "CHOICES\n";
    cout << "a. addRoot\n";
    cout << "b. addLeft\n";
    cout << "c. addRight\n";
    cout << "d. getLeft\n";
    cout << "e. getRight\n";
    cout << "f. print\n";
    cout << "g. preOrder\n";
    cout << "h. inOrder\n";
    cout << "i. postOrder\n";


    do{
        try{
            cout << "Enter option: ";
            cin >> op;
            switch(op){
                case 'a':
                    cout << "Enter value to add: ";
                    cin >> num;
                    tree->addRoot(num);
                    break;

                case 'b':
                    cout << "Enter parent value: ";
                    cin >> num2;
                    parent = tree->findNode(num2, tree->getRoot());
                    cout << "Enter value to add to left: ";
                    cin >> num;
                    tree->addLeft(parent, num);
                    break;

                case 'c':
                    cout << "Enter parent value: ";
                    cin >> num2;
                    parent = tree->findNode(num2, tree->getRoot());
                    cout << "Enter value to add to right: ";
                    cin >> num;
                    tree->addRight(parent, num);
                    break;

                case 'd':
                    cout << "Enter parent value to get direct left child: ";
                    cin >> num2;
                    parent = tree->findNode(num2, tree->getRoot());
                    if(parent && parent->left){
                        cout << "Left of " << parent->elem << ": " << tree->left(parent)->elem << endl;
                    }
                    else {
                        throw new exception();
                    }
                    break;

                case 'e':
                    cout << "Enter parent value to get direct right child: ";
                    cin >> num2;
                    parent = tree->findNode(num2, tree->getRoot());
                    if(parent && parent->left){
                        cout << "Right of " << parent->elem << ": " << tree->right(parent)->elem << endl;
                    } else {
                        throw new exception();
                    }
                    break;
        
                case 'f':
                    tree->print();
                    break;

                case 'g':
                    cout << "PREORDER: ";
                    tree->preOrder(tree->getRoot());
                    break;

                case 'h':
                    cout << "INORDER: ";
                    tree->inOrder(tree->getRoot());
                    break;

                case 'i':
                    cout << "POSTORDER: ";
                    tree->postOrder(tree->getRoot());
                    break;
                    
                case 'x':
                    cout << "Exiting...\n";
                    break;
                default:
                    cout << "Invalid input.";
            }
        } catch (exception& e){
           cout << e.what();
        }
        
    } while(op!='x');
}