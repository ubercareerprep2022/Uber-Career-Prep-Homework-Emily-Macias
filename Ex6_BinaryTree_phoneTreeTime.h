#ifndef PHONETREETIME_H
#define PHONETREETIME_H

#endif // PHONETREETIME_H
#include <string>

struct node{
    std::string name;
    long phoneNumber;
    node* left;
    node* right;
};

node* root = nullptr;
int treeSize = 0;
