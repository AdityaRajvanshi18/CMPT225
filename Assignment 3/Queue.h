/*
 * Queue.h
 *
 * Class Description: Models a Queue
 * Class Invariant: - FIFO or LILO
 *                  - no access beyond the front of the queue
 *                  - only add new element to the back
 * Author: Aditya Rajvanshi
 * Created: 20/02/2019
 *
 */

#pragma once

#include <iostream>
#include "Node.h"
#include "EmptyDataCollectionException.h"

using namespace std;


template <class T> 
class Queue {

private:

    int elementCount;
    Node<T>* head;
    Node<T>* tail;

public:

	//Constructors and Destructors
    // Default Constructor
    Queue();
    // Default Destructor
    ~Queue();


    // Description: Returns the number of elements in the Queue.
    // Time Efficiency: O(1)
    int getElementCount() const;

    // Description: Returns "true" if Queue is empty, otherwise "false".
    // Time Efficiency: O(1)
    bool isEmpty() const;

    // Description: Adds anElement to end of the Queue and
    //              returns "true" if successful, otherwise "false".
    // Time Efficiency: O(1)
    bool enqueue(const T& anElement);

    // Description: Removes the element at the front of the Queue and
    //              returns "true" if successful, otherwise "false".
    // Precondition: This Queue is not empty.
    // Time Efficiency: O(1)
    bool dequeue();

    // Description: Returns a copy of the element located at the front of the Queue.
    // Precondition: This Queue is not empty.
    // Postcondition: This Queue is unchanged.
    // Exceptions: Throws EmptyDataCollectionException if this Queue is empty.
    // Time Efficiency: O(1)
    T peek() const throw(EmptyDataCollectionException);

    // Description: Prints all elements of the queue.
    // Postcondition: The queue is unchanged.
    // Time Efficiency: O(n)
    void printQ() const;
}; //end of public

// Basic Constructor for Queue
template <class T>
Queue<T>::Queue(){
    elementCount = 0;
    head = NULL;
    tail = NULL;
}

// Basic Destructor for Queue
template <class T>
Queue<T>::~Queue(){
    for (int i = 0; i < getElementCount(); i++){
        dequeue();
    }
}

// Description: Returns the number of elements in the Queue.
// Time Efficiency: O(1)
template <class T>
int Queue<T>::getElementCount() const {
    return this->elementCount;
}

// Description: Returns "true" if Queue is empty, otherwise "false".
// Time Efficiency: O(1)
template <class T>
bool Queue<T>::isEmpty() const {
    return this->elementCount == 0;
}

// Description: Adds anElement to end of the Queue and
//              returns "true" if successful, otherwise "false".
// Time Efficiency: O(1)
template <class T>
bool Queue<T>::enqueue(const T& anElement){

    Node<T>* newNode = new Node<T>(anElement);
    if (isEmpty()){
        this->head = newNode;
        this->tail = newNode;
    } else {
        this->tail-> next = newNode;
        this->tail = this->tail->next;
    }
    elementCount++;
    return true;
}

// Description: Removes the element at the front of the Queue and
//              returns "true" if successful, otherwise "false".
// Precondition: This Queue is not empty.
// Time Efficiency: O(1)
template <class T>
bool Queue<T>::dequeue(){
    if (isEmpty())
        return false;

    Node<T>* removing;
    if (getElementCount() == 1) {
        removing = this->head;
        this->head = NULL;
        this->tail = NULL;
    } else {
        removing = this->head;
        this->head = this->head->next;
    }

    delete removing;
    removing = NULL;
    elementCount--;
    return true;
}

// Description: Returns a copy of the element located at the front of the Queue.
// Precondition: This Queue is not empty.
// Postcondition: This Queue is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this Queue is empty.
// Time Efficiency: O(1)
template <class T>
T Queue<T>::peek() const throw(EmptyDataCollectionException){
    if (isEmpty()){
        throw EmptyDataCollectionException("Queue is empty");
    } else {
        return head->data;
    }
}

// Description: Prints all elements of the queue.
// Postcondition: The queue is unchanged.
// Time Efficiency: O(n)
template <class T>
void Queue<T>::printQ() const {
    Node<T>* current = head;
    while (current != NULL){
        cout << current->data << endl;
        current = current->next;
    }
}
