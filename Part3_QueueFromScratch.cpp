/* File: QueueFromScratch.cpp
 * --------------
 * Within this file, several functions for a queue class
 * are implemented. This includes:
 *
 *  size();
 *  isEmpty();
 *  rear();
 *  front();
 *  enqueue();
 *  dequeue();
 *
 *  Additionally, the grow() and rearrange() functions are
 *  implemented but are private functions.
 */

#include "console.h"
#include "simpio.h"
#include "QueueHeader.h"
#include "error.h"
using namespace std;

/* This serves as the constructor. The logicalSize
 * of the queue(representing how many items it contains)
 * is initialized to 0 and the allocatedSize(the array's actual size)
 * is set to 10 (this is just a value I chose). Our elems pointer
 * is set to point at an int array of the allocatedSize.
 * Next, we want to track the position of the first and last elements
 * in the queue which are both at 0 at the beginning.
 */
Queue::Queue(){
    logicalSize = 0;
    allocatedSize = 10;
    elems = new int[allocatedSize];
    lastElemIndex = 0;
    firstElemIndex = 0;
}


/* This function is the destructor which simply deletes
 * the array that the elems pointer is pointing at.
 */
Queue:: ~Queue(){
    delete[] elems;
}


/* Returns the size of the array by returning
 * its logical size (once again, logicalSize tracks
 * the amount of items in the queue);
 */
int Queue::size(){
    return logicalSize;
}


/* Checks if the queue is empty by checking if the logical
 * size is 0.
 */
bool Queue::isEmpty(){
    if(logicalSize == 0){
        return true;
    }
    return false;
}


/* Returns the number at the end of the queue.
 * We must first check a base case. If the queue
 * is empty, we cannot return any element and
 * instead must raise an error. Otherwise,
 * we simply return the number at the
 * lastElemIndex.
 */
int Queue::rear(){
    if(isEmpty()){
        error("Sorry, the queue is empty");
   }
    return elems[lastElemIndex];
}


/* Returns the number at the front of the queue.
 * We must first check a base case. If the queue
 * is empty, we cannot return any element so
 * we raise an error. Otherwise, we simply
 * return the number at firstElemIndex.
 */
int Queue::front(){
    if(isEmpty()){
        error("Sorry, queue is empty");
    }
    return elems[firstElemIndex];
}


/* This function is a private function which
 * serves the purpose of creating an array double
 * the size of our original array if it gets filled,
 * and transferring all elements over. It makes
 * our array dynamic rather than static.
 */
void Queue::grow(){
    allocatedSize = allocatedSize * 2;
    int* helper = new int[allocatedSize];
    for(int i = 0; i < allocatedSize; i++){
        helper[i] = elems[i];
    }
    delete[] elems;
    elems = helper;
}


/* One of the possible situations with a queue is
 * having it fill up and then dequeuing elements so
 * that only a small portion of the queue's space
 * is actually filled up (example, filling up all indices 0 to 9
 * and then dequeuing elements from 0 to 6 and only leaving indices
 * 7 to 9 still filled. If someone attempts to
 * enqueue in this case, instead of doubling the size of our
 * array and possibly ending up with large, wasted space,
 * we can simply reorganize our array. This means that all the elements
 * are moved down if there is empty space when we are trying to an
 * enqueue an element if the last index is filled. This reorganize
 * function takes care of reorganizing the array/ moving all elemnts
 * down.
 */
void Queue::reorganize(){
    for(int i = firstElemIndex; i < allocatedSize; i++){
        int newIndex = i - firstElemIndex;
        elems[newIndex] = elems[i];
    }
    firstElemIndex = 0;
    lastElemIndex = logicalSize - 1;
}


/* Adds an element to our queue.
 */
void Queue::enqueue(int item){
    if(logicalSize == allocatedSize){  // doubles size of our array if full
        grow();
    }
    if(lastElemIndex == allocatedSize - 1){  //reorganizes array if its not full but the last index is filled
        reorganize();
    }
    if(isEmpty()){
        lastElemIndex = 0;   // resets both the first and last indices to 0 in case they changed from previous enqueues/dequeues
        firstElemIndex = 0;
        elems[lastElemIndex] = item;
        logicalSize ++;  //increases logicalSize since we added an element
    } else {
        lastElemIndex++;
        elems[lastElemIndex] = item;
        logicalSize ++;
    }
}


/* Removes an element from the queue and returns the number
 * removed.
 */
int Queue::dequeue(){
    if(isEmpty()){
        error("Sorry, queue is empty");
    }
    int elemDequeued = elems[firstElemIndex];
    firstElemIndex ++;
    logicalSize --;
    return elemDequeued;
}


/* This function was made solely for testing. It returns the allocatedSize
 * of the queue which allows us to check whether a queue went through thr grow
 * function or was simply reorganized.
 */
int Queue:: checkQueueAllocatedSize(){  // this function is solely used for testing
    return allocatedSize;
}


int main()
{
    Queue test;
    test.enqueue(0);
    test.enqueue(1);
    test.enqueue(2);
    test.enqueue(3);

    cout << test.dequeue() << endl;  //expect 0
    cout << test.dequeue() << endl;  //expect 1
    cout << test.dequeue() << endl; //expect 2

    test.enqueue(4);
    test.enqueue(5);

    cout << test.rear() << endl; //expect 5
    cout << test.front() << endl; // expect 3
    cout << test.size() << endl; // expect 3
    cout << test.isEmpty() << endl; //expect 0

    cout << test.dequeue() << endl; //expect 3
    cout << test.dequeue() << endl; //expect 4
    cout << test.dequeue() << endl; //expect 5

    test.enqueue(100000000);
    for(int i = 0; i <= 10; i ++){
        test.enqueue(106);
    }
    test.enqueue(200000000);  // should call the grow function
    cout << test.checkQueueAllocatedSize() << endl; //expect 20

    cout << test.rear() << endl; //expect 2000000000
    cout << test.front() << endl; //expect 1000000000

    Queue testTwo;
    testTwo.enqueue(323);
    testTwo.enqueue(324);

    for(int i = 3; i < 10; i ++){
        testTwo.enqueue(100);
    }
    testTwo.enqueue(325);

    cout << testTwo.dequeue() << endl; //expect 323
    testTwo.enqueue(910);

    cout << testTwo.front() << endl; //expect 324
    cout << testTwo.rear() << endl; //expect 910
    cout << testTwo.size() << endl; //expect 10
    cout << testTwo.checkQueueAllocatedSize() << endl; //expect 10

    return 0;
}
