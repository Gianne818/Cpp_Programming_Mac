#include <algorithm>
using namespace std;

struct node{
    int elem;
    node* right, *left;
    node* parent;

    int getHeight(){
        int leftVal = left ? left->getHeight() : -1;
        int rightVal = right ? right->getHeight() : -1;

        return 1 + max(leftVal, rightVal);
    }

    int getDepth(){
        if(parent == nullptr) return 0;
        return 1+parent->getDepth();
    }
};

//implement getHeight and getDepth

