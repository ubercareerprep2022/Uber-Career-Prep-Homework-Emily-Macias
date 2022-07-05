#ifndef GRAPHNODEHEADER_H
#define GRAPHNODEHEADER_H

#endif // GRAPHNODEHEADER_H
#include "map.h"
#include "vector.h"

struct graphNode {
    int data;
};

bool operator < (const graphNode& One, const graphNode& Two){
    return (One.data < Two.data);
}

Map<graphNode, Vector<graphNode>> adjNodes;
