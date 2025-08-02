#include <iostream>
#include <string>
using namespace std;

//Binary Trees can have a maximum of two child nodes. This restriction is what gives many benefits of the binary tree.
//Algorithms like traversing, searching, insertion, deletion is easier and faster.
//Keeping data sorted is easier in BST making searching very efficient.
//Balancing trees is easier with the limited amount of child nodes like AVL.

//----Types of Binary Trees----
//Balanced - at most has 1 difference between left and right subtree height for each node.
//Complete - all levels full of nodes except the last, which can be full, or filled from left to right.
//Full - each node has either 0 or 2 child nodes.
//Perfect - has all leaf nodes on the same level. It is full, balanced, and complete.

//This implementation is a singly linked list, but instead of next, we split it up to left and right.

class Tree{
public:
    char data;
    Tree* left;
    Tree* right;

    Tree(char data) : data(data), left(nullptr), right(nullptr){}
    //Traversals will be implemented later.
};

//Example of a Complete Binary Tree.

int main (){
    Tree* root = new Tree('R');
    Tree* nodeA = new Tree('A');
    Tree* nodeB = new Tree('B');
    Tree* nodeC = new Tree('C');
    Tree* nodeD = new Tree('D');
    Tree* nodeE = new Tree('E');
    Tree* nodeF = new Tree('F');
    Tree* nodeG = new Tree('G');

    //Child of root
    root->left = nodeA;
    root->right = nodeB;

    //Child of A
    nodeA->left = nodeC;
    nodeA->right = nodeD;

    //Child of B
    nodeB->left = nodeE;
    nodeB->right = nodeF;

    //Child of C
    nodeC->left = nodeG;
}