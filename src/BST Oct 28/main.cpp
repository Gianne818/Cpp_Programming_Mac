#include "BinaryTree.hpp"
using namespace std;

int main (){
    GenTree* tree = new BinTree();
    char op;
    int num;
    int num2;
    node* parent;

    cout << "CHOICES\n";
    cout << "a. addRoot\n";
    cout << "b. insert\n";
    cout << "c. getLeft\n";
    cout << "d. getRight\n";
    cout << "e. print\n";
    cout << "f. preOrder\n";
    cout << "g. inOrder\n";
    cout << "h. postOrder\n";
    cout << "i. breadthFirst\n";
    cout << "j. remove node only\n";


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
                    cout << "Enter value to insert: ";
                    cin >> num;
                    tree->insert(num, tree->getRoot());
                    break;

                case 'c':
                    cout << "Enter parent value to get direct left child: ";
                    cin >> num2;
                    parent = tree->findNode(num2, tree->getRoot());
            
                    cout << "Left of " << parent->elem << ": " << tree->left(parent)->elem << endl;
                
                    
                    break;

                case 'd':
                    cout << "Enter parent value to get direct right child: ";
                    cin >> num2;
                    parent = tree->findNode(num2, tree->getRoot());
                    
                    cout << "Right of " << parent->elem << ": " << tree->right(parent)->elem << endl;
                    
                    break;
        
                case 'e':
                    tree->print();
                    break;

                case 'f':
                    cout << "PREORDER: ";
                    tree->preOrder(tree->getRoot());
                    cout << endl;
                    break;

                case 'g':
                    cout << "INORDER: ";
                    tree->inOrder(tree->getRoot());
                    cout << endl;
                    break;

                case 'h':
                    cout << "POSTORDER: ";
                    tree->postOrder(tree->getRoot());
                    cout << endl;
                    break;

                case 'i':
                    cout << "BREADTHFIRST: ";
                    tree->breadthFirst();
                    cout << endl;
                    break;
                
                case 'j':
                    cout << "Enter value of node to remove: ";
                    cin >> num;
                    cout << "Removed: " << tree->removeNodeOnly(num);
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