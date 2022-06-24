#ifndef PHONETREE_H
#define PHONETREE_H

#endif // PHONETREE_H
#include <string> 

struct node{
    std::string name;
    long phoneNumber;
    node* left;
    node* right;
};

node* root = nullptr;
