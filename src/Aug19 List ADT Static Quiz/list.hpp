class List {
public:
    virtual void add(int) = 0;
    virtual void print() = 0;
    /*1*/virtual int remove(int) = 0; //removes first instance of num, and return its index. if not found, return -1.
    /*2*/virtual int addFirst(int) = 0; //add element at first index and return element. else if full, return -1.

    /*3*/virtual int removeFirst() = 0; //remove first element and return removed element. if there is nothing to remove, return -1.
    /*3*/virtual int removeLast() = 0; //remove last element and return removed element. if there is nothing to remove, return -1.

    /*7*/virtual void flip() = 0; //reverse whole array.
    /*8*/ virtual void clear() = 0; //clear the array;
    /*9*/ virtual void addAtPos(int, int) = 0; //add at specified position
    /*10*/ virtual int removeAllInstance(int) = 0; //remove all instances of specified number and return the number of removed elements.
    /*11*/ virtual int removeAtPos(int) = 0; //remove element at specified index. 
    /*12*/ virtual void sortDescending() = 0;//sort array
    /*13*/ virtual int positionOf(int) = 0; //returns the position of value. if none, return -1.
};