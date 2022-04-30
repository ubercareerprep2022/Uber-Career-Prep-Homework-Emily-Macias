/*
 * File: main.cpp
 * --------------
 * Configured to use Stanford cslib and Qt
 */

#include "console.h"
#include "simpio.h"
#include "ReverseHeader.h"
#include "stack.h"
using namespace std;


void PrintLinkedList(Node* list){
    while(list != nullptr){
        cout << list->value << endl;
        list = list->next;
    }
}


Node* BuildLinkedList(int length){
    Node* front = new Node;
    front->value = 0;
    Node* helper = front;
    for(int i = 1; i < length; i++){
        helper->next = new Node;
        helper->next->value = i;
        helper = helper->next;
    }
    helper->next = nullptr;
    return front;
}


Node* ReverseLinkedListIterative(Node* front){
    if(front == nullptr){
        return nullptr;
    }
    if(front->next == nullptr){
        return front;
    }
    Node* prev = front;
    Node* current = front->next;
    prev->next = nullptr;
    Node* newFront = current->next;

    while(current != nullptr){
        current->next = prev;
        prev = current;
        current = newFront;
        if(current != nullptr){
             newFront = current->next;
        }
    }
    return prev;
}


Node* ReverseLinkedListStack(Node* front){
    Stack<int> reversedList;
    if(front == nullptr){
        return nullptr;
    }
    if(front->next == nullptr){ // do not need to reverse a one element linkedlist
        return front;
    }
    while(front != nullptr){
        reversedList.push(front->value);
        front = front->next;
    }
    Node* newFront = new Node;
    Node* first = newFront;
    newFront-> value = reversedList.pop();

    while(!reversedList.isEmpty()){
        newFront->next = new Node;
        newFront->next->value = reversedList.pop();
        newFront = newFront->next;
    }
    newFront-> next = nullptr;
    return first;
}


Node* ReverseLinkedListRecursion(Node* front){
    if(front == nullptr){
        return nullptr;
    }
    if(front->next == nullptr){
        return front;
    }
    Node* reversed = ReverseLinkedListRecursion(front->next);
    front->next->next = front;
    front->next = nullptr;
    return reversed;
}


int main()
{
    Node* front = BuildLinkedList(5);
    PrintLinkedList(front);  // works as expected

    Node* reversed = ReverseLinkedListIterative(front);
    PrintLinkedList(reversed); //works as expected

    Node* reversedTwo = ReverseLinkedListStack(front);
    PrintLinkedList(reversedTwo); //works as expected

    Node* reversedThree = ReverseLinkedListRecursion(front);
    PrintLinkedList(reversedThree); //works as expected

    return 0;
}
