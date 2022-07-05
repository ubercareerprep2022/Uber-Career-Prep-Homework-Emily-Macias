/*
 * File: main.cpp
 * --------------
 * Blank C++ project configured to use Stanford cslib and Qt
 */

#include "console.h"
#include "simpio.h"
#include "graphNodeHeader.h"
#include "map.h"
#include "vector.h"
using namespace std;


void findAndDelete(graphNode& node, Vector<graphNode>& list){
    for(int i = 0; i < list.size(); i ++){
        if(list[i].data == node.data){
            list.remove(i);
        }
    }
}


void addNode(int key){
    graphNode graphNodeToAdd;
    graphNodeToAdd.data = key;
    adjNodes[graphNodeToAdd];
}


void removeNode(int key){
    graphNode NodeToDelete;
    NodeToDelete.data = key;
    if(adjNodes.containsKey(NodeToDelete)) {
        adjNodes.remove(NodeToDelete);
        for(graphNode node: adjNodes){
            findAndDelete(NodeToDelete, adjNodes[node]);
        }
    } else {
        error("Sorry, the map doesn't contain that key");
    }
}


//This assumes that if one of the nodes is not already in the map, we do not want to create it with this function call
void addEdge(int node1, int node2){
    graphNode nodeOne;
    nodeOne.data = node1;
    graphNode nodeTwo;
    nodeTwo.data = node2;

    if(adjNodes.containsKey(nodeOne) && adjNodes.containsKey(nodeTwo)) {
        adjNodes[nodeOne].add(nodeTwo);
        adjNodes[nodeTwo].add(nodeOne);
    } else {
        error("Sorry, both nodes are not in the map");
    }
}


void removeEdge(int node1, int node2){
    graphNode nodeOne;
    nodeOne.data = node1;
    graphNode nodeTwo;
    nodeTwo.data = node2;
    if(adjNodes.containsKey(nodeOne) && adjNodes.containsKey(nodeTwo)){
        findAndDelete(nodeOne, adjNodes[nodeTwo]);
        findAndDelete(nodeTwo, adjNodes[nodeOne]);
    } else {
        error("Sorry both keys are not present in the map");
    }

}


Vector<graphNode> getAdjNodes(int key){
    graphNode nodeToFind;
    nodeToFind.data = key;

    if(adjNodes.containsKey(nodeToFind)){
        return adjNodes[nodeToFind];
    } else {
        error("sorry, the map does not contain that key");
    }
}


void printMap(){
    for(graphNode key: adjNodes){
        cout << "key: " << key.data << endl;
        Vector<graphNode> inner = adjNodes[key];
        cout << "values: " << endl;
        for(int i = 0; i < inner.size(); i++){
            cout << inner[i].data << endl;
        }
    }
}


int main()
{
    addNode(7);
    addNode(6);
    addEdge(6, 7);
    addNode(8);
    addEdge(8, 6);
    removeEdge(6, 7);
    addEdge(7, 8);
    addEdge(6, 7);
    Vector<graphNode> nodes = getAdjNodes(6);
    for(int i = 0; i < nodes.size(); i ++){
        cout << nodes[i].data << endl;
    }
    printMap();
    removeNode(6);
    printMap();
    addEdge(7, 9); // returns error as expected

    // All tests work as expected
    return 0;
}
