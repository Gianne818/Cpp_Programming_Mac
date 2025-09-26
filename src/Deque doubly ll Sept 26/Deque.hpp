
class Deque {
public:
   virtual void insertFront(int) = 0;
   virtual void insertRear(int) = 0;
   virtual int removeFront() = 0;
   virtual int removeRear() = 0;

   virtual void print() = 0;
};