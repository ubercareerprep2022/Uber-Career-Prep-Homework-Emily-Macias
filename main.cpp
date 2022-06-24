/*
 * File: main.cpp
 * --------------
 * Blank C++ project configured to use Stanford cslib and Qt
 */

#include "console.h"
#include "simpio.h"
#include "ArrayImplementation.h"
using namespace std;

dictionary::dictionary(){
    allocatedSize = 5;
    logicalSize = 0;
    elems =  new pair[allocatedSize];
}


dictionary::~dictionary(){
    delete[] elems;
}


int dictionary::size(){
    return logicalSize;
}


void dictionary::grow(){
    pair* helper = new pair[allocatedSize * 2];
    for(int i = 0; i < allocatedSize; i ++){
        helper[i] = elems[i];
    }
    allocatedSize = allocatedSize * 2;
    delete[] elems;
    elems = helper;
}


long dictionary::find(string name){
    for(int i = 0; i < logicalSize; i ++){
        if(elems[i].name == name){
            return elems[i].phoneNumber;
        }
    }
    return -1;
}


void dictionary::insert(string name, long phoneNumber){
    if(logicalSize == allocatedSize){
        grow();
    }
    elems[logicalSize].name = name;
    elems[logicalSize].phoneNumber = phoneNumber;
    logicalSize++;
}

int main()
{
    dictionary test;
    test.insert("ABC", 1111111111);
    cout << "size:" << test.size() << endl;
    test.insert("XYZ", 999999999);
    cout << "size:" << test.size() << endl;
    test.insert("emily", 0000000000);
    cout << "size:" << test.size() << endl;
    test.insert("Stanford", 202520252);
    cout << "size:" << test.size() << endl;
    test.insert("QRS", 888888888);
    cout << "size:" << test.size() << endl;
    test.insert("LMNO", 444444444); //Question: How do I know when something will violate the long classification
    cout << "size:" << test.size() << endl;

    cout<< test.find("XYZ") << endl;
    cout<< test.find("ABC") << endl;
    cout<< test.find("HHH") << endl;

    return 0;
}
