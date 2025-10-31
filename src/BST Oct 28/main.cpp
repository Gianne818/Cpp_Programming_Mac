#include "BinaryTree.hpp"
using namespace std;

int main (){
    GenTree* tree = new BinTree();
    char op;
    int num;
    int num2;
    node* parent;
    node* temp;

    cout << "CHOICES\n";
    cout << "a. insert\n";
    cout << "b. getLeft\n";
    cout << "c. getRight\n";
    cout << "d. print\n";
    cout << "e. preOrder\n";
    cout << "f. inOrder\n";
    cout << "g. postOrder\n";
    cout << "h. breadthFirst\n";
    cout << "i. remove node only\n";
    cout << "j. node height\n";
    cout << "k. node depth\n";


    do{
        try{
            cout << "Enter option: ";
            cin >> op;
            switch(op){
                case 'a':
                    cout << "Enter value to insert: ";
                    cin >> num;
                    tree->insert(num, tree->getRoot());
                    break;

                case 'b':
                    cout << "Enter parent value to get direct left child: ";
                    cin >> num2;
                    parent = tree->findNode(num2, tree->getRoot());
                    cout << "Left of " << parent->elem << ": " << tree->left(parent)->elem << endl; 
                    break;

                case 'c':
                    cout << "Enter parent value to get direct right child: ";
                    cin >> num2;
                    parent = tree->findNode(num2, tree->getRoot());
                    
                    cout << "Right of " << parent->elem << ": " << tree->right(parent)->elem << endl;
                    
                    break;
        
                case 'd':
                    tree->print();
                    break;

                case 'e':
                    cout << "PREORDER: ";
                    tree->preOrder(tree->getRoot());
                    cout << endl;
                    break;

                case 'f':
                    cout << "INORDER: ";
                    tree->inOrder(tree->getRoot());
                    cout << endl;
                    break;

                case 'g':
                    cout << "POSTORDER: ";
                    tree->postOrder(tree->getRoot());
                    cout << endl;
                    break;

                case 'h':
                    cout << "BREADTHFIRST: ";
                    tree->breadthFirst();
                    cout << endl;
                    break;
                
                case 'i':
                    cout << "Enter value of node to remove: ";
                    cin >> num;
                    cout << "Removed: " << tree->removeNodeOnly(num) << endl;
                    break;

                case 'j':
                    cout << "Enter node to get height: ";
                    cin >> num;
                    temp = tree->findNode(num, tree->getRoot());
                    if(!temp){
                        throw logic_error("Node does not exist\n");
                    }
                    cout << "Node height: " << temp->getHeight() << endl;
                    break;
                    
                case 'k':
                    cout << "Enter node to get depth: ";
                    cin >> num;
                    temp = tree->findNode(num, tree->getRoot());
                    if(!temp){
                        throw logic_error("Node does not exist\n");
                    }
                    cout << "Node depth: " << temp->getDepth() << endl;
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