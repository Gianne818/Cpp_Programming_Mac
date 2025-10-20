#include "Node.hpp"
class List {
public: 
    virtual void add(int) = 0;
    virtual void print() = 0;
    virtual int removeHead() = 0;
    virtual int removeTail() = 0;
    virtual Node* find(int) = 0;
    virtual void insertAt(int, int) = 0;
    virtual int removeAt(int) = 0;
    virtual int removeAll(int) = 0;
    virtual void flip() = 0;

};