#ifndef EMPLOYEETREE_H
#define EMPLOYEETREE_H

#endif // EMPLOYEETREE_H

#include <string>
#include <list>
#include "vector.h"

struct employee {
    std::string name;
    std::string title;
    Vector<employee> directReports;
};
employee front;
