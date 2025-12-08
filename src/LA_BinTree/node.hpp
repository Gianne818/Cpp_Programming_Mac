#include <algorithm>
using namespace std;

struct node {
	int elem;
	node* left;
	node* right;
	node* parent;
	
	 int height() {
        int leftVal = (left) ? left->height() : -1;
        int rightVal = right ? right->height() : -1;
        return 1 + max(leftVal, rightVal);
    }

	int depth() {
        if(!parent) return 0;
        return 1 + parent->depth();
    }
};