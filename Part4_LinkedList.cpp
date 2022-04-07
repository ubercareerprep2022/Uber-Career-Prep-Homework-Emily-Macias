/* File: LinkedListClass.cpp
 * --------------
 * Within this file, a linked List is implemented. The following
 * functions are included:
 *
 * Size();
 * push();
 * pop();
 * insert();
 * remove();
 * elementAt();
 * printList();
 */

#include "console.h"
#include "simpio.h"
#include "LinkedListHeader.h"
#include "error.h"
using namespace std;


/* Output: the size of the linkedlist
 *
 * This function simply returns the size of our linkedList. In
 * our header file we have a variable listLength which tracks the
 * lists length at all times; we simply return this value.
 */
int Size(){
    return listLength;
}


/* The purpose of this function is to be a helper function for
 * push. It initializes the new node added to the end of the list
 * and increases listLength by one.
 */
void setUpNewEnd(Node nodetoAdd, Node*& end){
    end->num = nodetoAdd.num;
    end->next = nullptr;
    listLength ++;
}


/* Input: a node
 * Output: our linkedList changed so that the inputed
 * node is added to the end
 *
 * Firstly, within this function we address a form of "special case".
 * If our linkedList is empty, we want to make our "first" pointer
 * point to the added element. We want to do the same with our "last"
 * pointer (Note: the first pointer should always point to the first element
 * in the linkedList and the last pointer should always point to the last
 * element in the linkedList).
 *
 * If the linkedList was not empty then we want to last->next equal to the
 * node being added.
 */
void push(Node nodeToAdd) {  // from the instructions it seemed a node was passed in rather than a pointer to a node
    if(Size() == 0){
        last = new Node;
        setUpNewEnd(nodeToAdd, last);
        first = last;
    } else {
       last->next = new Node;
       Node* newLast = last->next;
       setUpNewEnd(nodeToAdd, newLast);
       last = newLast;
    }
}


/* Within this function a pointer to the last element in the linkedList
 * is returned and the element is removed.
 *
 * Firstly, we check a base case. We cannot remove from an empty list.
 * Also, if the list only has one node, we have to re-organize
 * first and last so that they point to a nullptr.
 *
 * Otherwise, we find the node before the last element and make it the
 * new last element. We return a pointer to the node that used to be at the
 * end (which we just removed by making nodeBeforeLastElem->next = nullptr).
 */
Node* pop(){
    if(Size() == 0){
        error("Sorry, linkedList is empty");  //cannot remove from an empty list
    }
    if(Size() == 1){
        Node* toReturn = first;
        first = last = nullptr;
        listLength --;
        return toReturn;
    }
    Node* nodeBeforeLastElem = first;
    while(nodeBeforeLastElem->next != last){
        nodeBeforeLastElem = nodeBeforeLastElem->next;
    }
    Node* toReturn = last;
    nodeBeforeLastElem->next = nullptr;
    last = nodeBeforeLastElem;
    listLength --;
    return toReturn;
}


/* Input: index to insert a new node at, node to insert
 *
 * Note: I am assuming that nothing else in the linkedList changes,
 * everything just gets shifted down if something is inserted into
 * the linkedList. For example if we insert at the last index of
 * the linkedList, the inserted element does not become the new
 * last element, rather it is inserted right before the last element
 * in the list.
 */
void insert(int index, Node node){
    if(index >= Size() || index < 0){
        error("Sorry, the index is not in the linkedList");
    }
    else if(index == 0){
        Node* helper = first;
        first = new Node;
        first->num = node.num;
        first->next = helper;
    } else {
        Node* prev = first;
        index --;
        while(index > 0){
            prev = prev->next;
            index --;
        }
        Node* after = prev->next;
        prev->next = new Node;
        prev->next->num = node.num;
        prev->next->next = after;
    }
    listLength ++;
}


/* Inputs: index where an element is removed from.
 *
 * Within this function we aim to remove a node from a certain index
 * in the linkedList. First, we check a few base cases. If the
 * index is not in the linkedList, we cannot remove it. If the index is
 * 0, we have to rearrange the pointer to the front of our linkedList.
 *
 * Otherwise, we must rearrange our linkeddList so that the node that
 * was before it now points to the node that was after it.
 */
void remove(int index){
    if(index >= Size() || index < 0 || Size() == 0){
        error("Sorry, the index is not in the linkedList");
    }
    if(index == 0){
        Node* newFirst = first->next;
        delete first;
        first = newFirst;
    } else {
        Node* prev = first;
        index --;
        while(index > 0){
            prev = prev->next;
            index --;
        }
        Node* toDelete = prev->next;
        Node* newNext = prev->next->next;
        prev->next = newNext;
        if(newNext == nullptr){  // resets last if we deleted the last element (not including nullptr as last)
            last = prev;
        }
        delete toDelete;         // avoids memory leak
    }
    listLength --;
}


/* Within this function we want to return a pointer to the node at a certain index
 * in our linkedList.
 *
 * Major Assumption Made: within this function, I assume that we want a pointer
 * to the node specified which also yields information about all of the node's
 * connections. This means that if we ever print out what the pointer
 * is pointing to, it will include our "target node" but will also include all
 * of the nodes after our specified node (node->next, node->next->next, etc.)
 * If we wanted a pointer which solely had information about the specified node
 * and no information about the nodes after it, we could manipulate it so that we
 * returned a pointer to our specified node whose "next" we would set to nullptr.
 */
Node* elementAt(int index){
    if(index >= Size() || index < 0 || Size() == 0){
        return nullptr;
    }
    if(index == 0){
        return first;
    }
    Node* element = first;
    while(index > 0){
        element = element->next;
        index --;
    }
    return element;
}


/* This function prints out all of the elements within our linkedList.
 */
void printList(){
        Node* helper = first;
        while(helper != nullptr){
            cout << helper->num << endl;
            helper = helper-> next;
        }
}


/* This function is used solely for testing purposes and prints out the
 * contents of any inputted linkedList (not just the contents of the linkedList
 * represented by our "first" pointer).
 */
void printForTesting(Node* pointer){
    Node* helper = pointer;
    while(helper != nullptr){
        cout << helper->num << endl;
        helper = helper->next;
    }
}


int main()
{
    //testPushBackAddsOneNode
    push({1, nullptr});
    push({2, nullptr});
    push({3, nullptr});
    printList();                          // successful in adding a node
    cout << Size() << endl;               // expect 3


    //testsPopBackRemovesCorrectNode
    Node* popped = pop();
    cout << popped->num << endl;           // expect 3
    printList();                           // expect just 1 and 2 to remain
    cout << Size() << endl;                // expect 2


    //testEraseRemovesCorrectNode
    remove(0);
    printList();                          // expect just 2
    remove(0);
    printList();                          // expect nothing


    //testElementAtReturnNode
    push({0, nullptr});
    push({1, nullptr});
    push({2, nullptr});
    push({3, nullptr});
    push({4, nullptr});

    Node* observeOne = elementAt(0);
    cout << observeOne->num << endl;                // expect 0
    cout << Size() << endl;                         // expect 5

    Node* observeTwo = elementAt(1);
    cout << observeTwo->num << endl;                // expect 1

    Node* observeEnd = elementAt(4);
    cout << observeEnd->num << endl;                // expect 4

    //testElementAtReturnNoNodeIfIndexDoesNotExist
    Node* observeNotExist = elementAt(8);
    printForTesting(observeNotExist);              // expect nothing to print


    //testSizeReturnCorrectSize
    cout << Size() << endl;                       // expect 5
    for(int i = 0; i < 5; i++){
        pop();
    }
    cout << Size() << endl;                       // expect 0


    //Testing if all functions work when there is only one element left in the linkedList
    push({326, nullptr});
    printList();                                // expect 326

    Node* oneNodeOnly = pop();
    cout << oneNodeOnly->num << endl;           // expect 326
    printList();                                // expect nothing
    push({327, nullptr});

    Node* observeOneNodeOnly = elementAt(0);
    cout << observeOneNodeOnly-> num << endl;   // expect 327
    remove(0);
    printList();                                // expect nothing

    //Testing Insert Function
    push({329, nullptr});
    insert(0, {328, nullptr});
    printList();
    insert(1, {330, nullptr});
    printList();

    return 0;
}
