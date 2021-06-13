/*
 * Node.h
 *
 * Class Description: Models a node with a Linked List structure
 * Class Invariant: - next points to another node or NULL.
 * Author: Aditya Rajvanshi
 * Created: 20/02/2019
 *
 */

#include <cstdio>


#pragma once


template <class T> class Node {

public:
    T data;
    Node<T>* next;

    // Default Constructor
    Node();
    // Constructor with data parameter
    Node(T aData);
};


/*******************************************************/


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
