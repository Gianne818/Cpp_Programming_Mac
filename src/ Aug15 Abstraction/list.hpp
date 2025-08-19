class List {
    public:
    virtual void add(int num) = 0;
    virtual void print() = 0;
    virtual int getElem(int pos) = 0;
    virtual void remove(int) = 0;
    virtual int getSize() = 0;
};