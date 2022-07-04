/*
 * File: main.cpp
 * --------------
 * Blank C++ project configured to use Stanford cslib and Qt
 */

#include "phoneTreeTime.h"
#include "console.h"
#include "simpio.h"
#include <fstream>
#include "error.h"
#include <chrono>
using namespace std;

void addNode(node*& root, string name, long phoneNumber){
    if(root == nullptr){
        root = new node;
        root->name = name;
        root->phoneNumber = phoneNumber;
        root->left = nullptr;
        root->right = nullptr;
        treeSize++;
    } else {
        if(name > root->name){
            addNode(root->right, name, phoneNumber);
        } else if(name < root->name){
            addNode(root-> left, name, phoneNumber);
        }
    }
}


int size(){
    return treeSize;
}


long find(node*& root, string name){
    if(root == nullptr){
        return -1;
    } if(root->name == name){
        return root-> phoneNumber;
    } else if(name < root->name){
        return find(root->left, name);
    } else if(name > root->name) {
        return find(root->right, name);
    }
    return -1;
}


int main() {
    // The following portion of the program reads in data and inserts it into the binary tree
    ifstream treeInsert;
    treeInsert.open("data.csv");
    auto startTime = chrono::steady_clock::now();
    if(!treeInsert.is_open()){
        error("Sorry, file is not open");
    } else {
        while(treeInsert){
            string line;
            getline(treeInsert, line);
            int index = line.find(",");
            if(index != -1){
               string ID = line.substr(0, index);
               string phoneString = line.substr(index + 1);
               long long phoneNumber = stoll(phoneString);
               addNode(root, ID, phoneNumber);
            }
        }
    }
    auto endTime = chrono:: steady_clock::now();
    cout << "The size is: " << size() << endl;
    cout << "Time to insert is: " << chrono::duration_cast<chrono:: milliseconds>(endTime-startTime).count() << "ms" << endl;



    // The following portion of the program checks that tree contains all IDs in the search file
    ifstream checkContents;
    checkContents.open("search.txt");
    int found = 0;
    auto timeForLookupsStart = chrono::steady_clock::now();
    if(!checkContents.is_open()){
        error("Sorry, the search file is not open.");
    } else {
        while(checkContents){
            string checkLine;
            getline(checkContents, checkLine);
            if(find(root, checkLine) != -1){
                found++;
            }
        }
    }
    auto timeForLookupsEnd = chrono::steady_clock:: now();
    cout << "Find was called " << found << " times" << endl;
    cout << "Time for lookups was " << chrono::duration_cast<chrono::milliseconds>(timeForLookupsEnd - timeForLookupsStart).count() << "ms" << endl;

    // Overall conclusions when comparing the binary tree phone book and the array based phonebook:
    // Looking up the 1000 IDs from the search file was much faster when utilizing a binary tree (better time complexity)

    return 0;
}
