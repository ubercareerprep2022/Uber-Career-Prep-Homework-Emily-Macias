/*
 * File: BuildStack.cpp
 * --------------
 * This program implements several functions for
 * a stack including:
 *
 * isEmpty();
 * pop();
 * top();
 * size();
 * push();
 *
 * It also implements the private member function
 * grow();
 */

#include "console.h"
#include "simpio.h"
#include "stackHeader.h"
#include "error.h"
using namespace std;


/* Constructor which sets logicalSize (the number of elements in the stack
 * to 0) and allocatedSize (the actual size of the array) to 10. Our pointer,
 * elems, is changed to point at an array of integers of the allocatedSize.
 */
Stack::Stack(){
    logicalSize = 0;
    allocatedSize = 10;
    elems = new int[allocatedSize];
}


/* Destructor which deletes the array our pointer is pointing at.
 */
Stack:: ~Stack(){
    delete[] elems;
}


/* Checks if the stack is empty by checking if the logicalSize is 0.
 */
bool Stack::isEmpty(){
    if(logicalSize == 0){
        return true;
    }
    return false;
}

/* Returns and removes the element at the top of the stack.
 * It first checks a base case however. If the stack is empty,
 * then we cannot pop anything and an error message must be
 * given.
 */
int Stack::pop(){
    if(isEmpty()){
        error("Sorry, stack is empty");
    } else {
        logicalSize --;
        return elems[logicalSize];
    }
}


/* Returns the integer at the top of the stack but does not remove
 * it.
 */
int Stack::top(){
    if(isEmpty()){
        error("Sorry, stack is empty");
    } else {
        return elems[logicalSize - 1];
    }
}


/* Returns the size of the stack by returning its logicalSize.
 *
 */
int Stack::size(){
    return logicalSize;
}


/* Creates a new array double the size of the original
 * and transfers all elements from the old array over.
 */
void Stack::grow(){
    int* helper = new int[allocatedSize * 2];
    for(int i = 0; i < allocatedSize; i ++){
        helper[i] = elems[i];
    }
    delete[] elems;
    elems = helper;
}


/* Adds an element to the stack. If the stack is full,
 * the grow function is called in order to create space.
 * Note: I am assuming the stack is dynamic and not static.
 */
void Stack::push(int item){
    if(logicalSize == allocatedSize){
        grow();
    }
    elems[logicalSize] = item;
    logicalSize ++;
}


int main()
{
    Stack test;
    test.push(1);
    test.push(5);
    test.push(3);

    cout << test.size() << endl;   //expect 3
    cout << test.pop() << endl;    //expect 3
    cout << test.size() << endl;  //expect 2
    cout << test.top() << endl;   // expect 5
    cout << test.size() << endl;   // still expect 2
    cout << test.isEmpty() << endl;  //expect false (0)
    cout << test.pop() << endl; // expect 5
    cout << test.pop() << endl; //expect 1
    cout << test.pop() << endl; //expect error

    return 0;
}
