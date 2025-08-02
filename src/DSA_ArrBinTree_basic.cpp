#include <iostream>
#include <vector>
using namespace std;

//Array implementation is useful when you just want more read operations.
//It takes less memory than pointers from one element to the next.
//It is not good however for adding nodes or modifying, since array shifting is not efficient.

vector<char> tree = {
    'R', 'A', 'B', 'C', 'D', 'E', 'F',
    '-', '-', '-', '-', '-', '-', 'G'
};

bool isValid(int index){
    return index>=0 && index<tree.size() && tree[index]!='-';
}

int leftChild(int index){
    return 2*index + 1;
}

int rightChild(int index){
    return 2*index + 2;
}

void preOrderTraversal(int root){
    if(!isValid(root)) return;
    cout << tree[root] << " ";
    preOrderTraversal(leftChild(root));
    preOrderTraversal(rightChild(root));
}

void inOrderTraversal(int root){
    if(!isValid(root)) return;
   
    inOrderTraversal(leftChild(root));
    cout << tree[root] << " ";
    inOrderTraversal(rightChild(root));
}

void postOrderTraversal(int root){
    if(!isValid(root)) return;
    
    postOrderTraversal(leftChild(root));
    postOrderTraversal(rightChild(root));
    cout << tree[root] << " ";
}

int main (){
    cout << "Preorder Traversal:\n";
    preOrderTraversal(0);
    cout << endl << endl;

    cout << "Inorder Traversal:\n";
    inOrderTraversal(0);
    cout << endl << endl;

    cout << "Postorder Traversal:\n";
    postOrderTraversal(0);
    cout << endl << endl;



}