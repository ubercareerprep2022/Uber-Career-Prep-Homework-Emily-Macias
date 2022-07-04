#ifndef MAPDATA_H
#define MAPDATA_H

#endif // MAPDATA_H
#include <string>

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
