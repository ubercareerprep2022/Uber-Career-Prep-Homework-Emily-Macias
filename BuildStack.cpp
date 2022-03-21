/*
 * File: main.cpp
 * --------------
 * Blank C++ project configured to use Stanford cslib and Qt
 */

#include "console.h"
#include "simpio.h"
#include "stackHeader.h"
#include "error.h"
using namespace std;

Stack::Stack(){
    logicalSize = 0;
    allocatedSize = 10;
    elems = new int[allocatedSize];
}


Stack:: ~Stack(){
    delete[] elems;
}


bool Stack::isEmpty(){
    if(logicalSize == 0){
        return true;
    }
    return false;
}


int Stack::pop(){
    if(isEmpty()){
        error("Sorry, stack is empty");
    } else {
        logicalSize --;
        return elems[logicalSize];
    }
}


int Stack::top(){
    if(isEmpty()){
        error("Sorry, stack is empty");
    } else {
        return elems[logicalSize - 1];
    }
}


int Stack::size(){
    return logicalSize;
}


void Stack::grow(){
    int* helper = new int[allocatedSize * 2];
    for(int i = 0; i < allocatedSize; i ++){
        helper[i] = elems[i];
    }
    delete[] elems;
    elems = helper;
}


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
