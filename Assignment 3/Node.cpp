/*
 * Node.h
 *
 * Class Description: Models a node with a Linked List structure
 * Class Invariant: - next points to another node or NULL.
 * Author: Aditya Rajvanshi
 * Created: 20/02/2019
 *
 */
#include <cstdio>  // Needed for NULL
#include "Node.h"

// Default Constructor
// Post Condition: Data not set, next set to NULL
template <class T>
Node<T>::Node(){
    next = NULL;
}

// Parametrized Constructor
// Post Condition: Data set from input, next set to NULL
template <class T>
Node<T>::Node(T aData){
    data = aData;
    next = NULL;
}
