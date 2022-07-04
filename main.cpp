/*
 * File: main.cpp
 * --------------
 * Blank C++ project configured to use Stanford cslib and Qt
 */

#include "console.h"
#include "simpio.h"
#include "binaryTree.h"
#include <iostream>
using namespace std;

node* addNode(node*& root, int num){
    if(root == nullptr){
         root = new node;
         root->data = num;
         root->left = nullptr;
         root->right = nullptr;
    } else {
        if(num < root->data){
            addNode(root->left, num);
        } else if(num > root-> data){
            addNode(root->right, num);
        }
    }
    return root;
}


bool find(node*& root, int num){
    if(root == nullptr){
        return false;
    } if(root->data == num){
        return true;
    } else if(num < root->data){
        return find(root->left, num);
    } else if (num > root-> data){
        return find(root-> right, num);
    }
    return false;
}


void printTree(node* root){
    if(root == nullptr){
        return;
    } else {
        cout << root->data << endl;
        printTree(root->left);
        printTree(root->right);
    }
}


int main()
{
    addNode(root, 1);
    addNode(root, 7);
    addNode(root, 17);
    addNode(root, 6);
    addNode(root, 3);
    printTree(root);

    cout << find(root, 3) << endl; //returns True as expected
    cout << find(root, 31) << endl; // returns False as expected
    cout << find(root, 17) << endl; // returns True as expected
    cout << find(root, 1) << endl; // returns True as expected
    cout << find(root, 6) << endl; // returns True as expected
    return 0;
}
