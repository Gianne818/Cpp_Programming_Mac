#include <iostream>
using namespace std;

struct node {
    string elem;
    node* parent;
    node* left, *right;
};