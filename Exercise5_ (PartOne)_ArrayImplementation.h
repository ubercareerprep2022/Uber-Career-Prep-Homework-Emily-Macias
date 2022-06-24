#ifndef ARRAYIMPLEMENTATION_H
#define ARRAYIMPLEMENTATION_H

#endif // ARRAYIMPLEMENTATION_H
#include <string>
//Questions:
//why do we need std?
//Long just means it can be a decimal?

class dictionary{
public:
    dictionary();
    ~dictionary();
    long find(std::string name);
    int size();
    void insert(std::string name, long phoneNumber);

private:
    struct pair{
        std::string name;
        long phoneNumber;
    };

    int logicalSize;
    int allocatedSize;
    void grow();
    pair* elems;


};
