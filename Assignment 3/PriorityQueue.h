/*
 * PriorityQueue.h
 *
 * Class Description: Models a Priority Queue
 * Class Invariant: - FIFO or LILO
 *                  - Sorted by time and type
 *                  - no access beyond the front of the queue
 *                  - adds elements in sorted order
 * Author: Aditya Rajvanshi
 * Created: 20/02/2019
 *
 */

#pragma once

#include <iostream>
#include "EmptyDataCollectionException.h"

using namespace std;

template <class T> 
class PriorityQueue {

private:

    static const int MAX_ELEMENTS = 50;
    T elements[PriorityQueue::MAX_ELEMENTS];
    int elementCount;
    int capacity;

public:
    // Default Constructor
    PriorityQueue();


    // Description: Returns the number of elements in the Priority Queue (PQ).
    // Time Efficiency: O(1)
    int getElementCount() const;

    // Description: Returns "true" if PQ is empty, otherwise "false".
    // Time Efficiency: O(1)
    bool isEmpty() const;


    // Description: Adds anElement to end of the PQ and
    //              returns "true" if successful, otherwise "false".
    // Precondition: The PQ is sorted.
    // Postcondition: Once anElement is inserted, this PQ remains sorted.
    // Time Efficiency: O(n)
    bool enqueue(const T& anElement);

    // Description: Removes the element with the highest priority.
    //              It returns "true" if successful, otherwise "false".
    // Precondition: The PQ is not empty.
    // Time Efficiency: O(1)
    bool dequeue();

    // Description: Returns a copy of the element with the highest priority.
    // Precondition: This PQ is not empty.
    // Postcondition: This PQ is unchanged.
    // Exceptions: Throws EmptyDataCollectionException if this PQ is empty.
    // Time Efficiency: O(1)
    T peek() const throw(EmptyDataCollectionException);

    // Description: Prints all elements of the PQ.
    // Postcondition: This PQ is unchanged.
    // Time Efficiency: O(n)
    void printPQ() const;

}; // end of publi

// Default Constructor
template <class T>
PriorityQueue<T>::PriorityQueue(): elementCount(0), capacity(PriorityQueue::MAX_ELEMENTS){}

// Description: Returns the number of elements in the Priority Queue (PQ).
// Time Efficiency: O(1)
template <class T>
int PriorityQueue<T>::getElementCount() const {
    return elementCount;
}

// Description: Returns "true" if PQ is empty, otherwise "false".
// Time Efficiency: O(1)
template <class T>
bool PriorityQueue<T>::isEmpty() const {
    return getElementCount() == 0;
}

// Description: Adds anElement to end of the PQ and
//              returns "true" if successful, otherwise "false".
// Precondition: The PQ is sorted.
// Postcondition: Once anElement is inserted, this PQ remains sorted.
// Time Efficiency: O(n)
template <class T>
bool PriorityQueue<T>::enqueue(const T& anElement){
    if (getElementCount() < capacity) {

        for (int i = 0; i < getElementCount(); i++) {
            if (elements[i] < anElement){
            	for (int j = getElementCount(); j > i; j--){
            		elements[j] = elements[j-1];
                }
                elements[i] = anElement;

                elementCount++;
                return true;
            }
        }
        elements[elementCount] = anElement;
        elementCount++;
        return true;
    }
    return false;
}

// Description: Removes the element with the highest priority.
//              It returns "true" if successful, otherwise "false".
// Precondition: The PQ is not empty.
// Time Efficiency: O(1)
template <class T>
bool PriorityQueue<T>::dequeue(){
    if (isEmpty()) {
        return false;
    }
    elementCount--;
    return true;
}

// Description: Returns a copy of the element with the highest priority.
// Precondition: This PQ is not empty.
// Postcondition: This PQ is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this PQ is empty.
// Time Efficiency: O(1)
template <class T>
T PriorityQueue<T>::peek() const throw(EmptyDataCollectionException){
    if (isEmpty()){
        throw EmptyDataCollectionException("Priority Queue is empty");
    }
    return elements[getElementCount()-1];
}

// Description: Prints all elements of the PQ.
// Postcondition: This PQ is unchanged.
// Time Efficiency: O(n)
template <class T>
void PriorityQueue<T>::printPQ() const {
    for (int i = 0; i < getElementCount(); i++){
        cout << elements[i] << endl;
    }
}
