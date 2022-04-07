#ifndef STACKHEADER_H
#define STACKHEADER_H

#endif // STACKHEADER

class Stack {
public:
    Stack();
    ~Stack();

   void push(int item);
   int pop();
   int top();
   bool isEmpty();
   int size();

private:
   int logicalSize;
   int allocatedSize;
   int* elems = nullptr;

   void grow();

};
