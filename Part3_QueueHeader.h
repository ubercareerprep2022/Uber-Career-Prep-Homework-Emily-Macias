#ifndef QUEUEHEADER_H
#define QUEUEHEADER_H

#endif // QUEUEHEADER_H

class Queue {
public:

    int size();
    bool isEmpty();
    int rear();
    int front();
    void enqueue(int item);
    int dequeue();
    int checkQueueAllocatedSize();

     Queue();
    ~Queue();

private:
     int logicalSize;
     int allocatedSize;
     int firstElemIndex;
     int lastElemIndex;
     int* elems = nullptr;

     void grow();
     void reorganize();
};
