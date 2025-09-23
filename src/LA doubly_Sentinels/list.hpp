#include "node.hpp"

class list {
    virtual void add(int) = 0;
    virtual void print() = 0;
    virtual void reversePrint() = 0;
    virtual void addHead(int) = 0;
    virtual void addTail(int) = 0;
    virtual int get(int) = 0;
    virtual int remove(int) = 0;
    virtual int removeAt(int) = 0;
    virtual int removeAll(int) = 0;
    virtual void addMid(int) = 0;

    virtual void addAt(int num, int pos) = 0;
};