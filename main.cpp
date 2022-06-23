/*
 * File: main.cpp for PartOne of the Uber Career Prep Homework 2
 * --------------
 * Blank C++ project configured to use Stanford cslib and Qt
 */

#include "console.h"
#include "simpio.h"
#include "TreeHeader.h"
#include <iostream>
using namespace std;

node* makeNode(int num, node* leftData, node* rightData){
    node* pointer = new node;
    pointer-> data = num;
    pointer-> left = leftData;
    pointer-> right = rightData;
    return pointer;
}

void printTrees(node* root){
    if(root == nullptr){
        return;
    } else {
        cout << root->data << endl;
        printTrees(root->left);
        printTrees(root->right);
    }
}

int main() {
    node* lastRight = makeNode(3, nullptr, nullptr);
    node* lastLeft = makeNode(6,nullptr, nullptr);
    node* rightSide = makeNode(17, lastLeft, lastRight);
    node* leftSide = makeNode(7,nullptr, nullptr);
    root = new node;
    root->data = 1;
    root->left = leftSide;
    root->right = rightSide;

    printTrees(root); //prints expected values of 1 7 17 6 3
    return 0;
}
