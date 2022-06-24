/*
 * File: main.cpp
 * --------------
 * Blank C++ project configured to use Stanford cslib and Qt
 */
#include "phoneTree.h"
#include "console.h"
#include "simpio.h"
using namespace std;

void addNode(node*& root, string name, long phoneNumber){
    if(root == nullptr){
        root = new node;
        root->name = name;
        root->phoneNumber = phoneNumber;
        root->left = nullptr;
        root->right = nullptr;
    } else {
        if(name > root->name){
            addNode(root->right, name, phoneNumber);
        } else if(name < root->name){
            addNode(root-> left, name, phoneNumber);
        }
    }
}


long find(node*& root, string name){
    if(root == nullptr){
        return -1;
    } if(root->name == name){
        return root-> phoneNumber;
    } if(find(root->left, name)!= -1){
        return find(root->left, name);
    } else if(find(root->right, name) != -1){
        return find(root->right, name);
    }
    return -1;
}


int main()
{
    addNode(root, "ABC", 1111111111);
    addNode(root, "XYZ", 999999999);
    addNode(root, "DEF", 222222222);
    addNode(root, "emily", 19191919);
    addNode(root, "LMNO", 123456789);

    // tests start here
    cout << find(root, "ABC") << endl; // prints out 1111111111 as expected
    cout << find(root, "HIJK") << endl; // prints as expected
    cout << find(root, "XYZ") << endl; // prints as expected
    cout << find(root, "DEF") << endl; // prints as expected
    cout << find(root, "emily") << endl; // prints as expected
    cout << find(root, "LMNO") << endl; // prints as expected
    cout << find(root, "HHHH") << endl; // prints as expected
    return 0;
}
