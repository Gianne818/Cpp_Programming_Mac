struct node {
    int elem;
    node** children; //array of nodes
    node* parent;
    int numChild;
};