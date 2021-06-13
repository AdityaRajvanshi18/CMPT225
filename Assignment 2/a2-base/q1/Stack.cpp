/*
 * Stack.cpp
 *
 * Description: Implementation of an int sequence with push/pop ...
 * Class Invariant: ... in a LIFO order
 *
 * Author: Aditya Rajvanshi
 * Date: 01/02/2019
 */

#include <cstddef>  // For NULL
#include "Stack.h"
#include <iostream>

using namespace std;

// Desc:  Constructor
// Post:  Stack is empty
Stack::Stack() {
	head = NULL;
	tail = NULL;
}


// Desc:  Destructor
// Post:  There is no stack
Stack::~Stack() {
	StackNode *ptr = head;
		while (ptr != NULL) {
        		head = head->next;
        		delete ptr;
        		ptr = head;
    }
}


// Desc:  Insert element x to the top of the stack.
// Post:  Tail points to element x
void Stack::push(int x) {
	StackNode *newTail = new StackNode;
	newTail->data = x;
	newTail->next = NULL;
	if (head == NULL){
		head = newTail;
		tail = newTail;
	}
	else{
		tail->next = newTail;
		tail = tail->next;
	}
	return;
}


// Desc:  Remove and return element at the top of the stack.
//  Pre:  Stack is not empty
// Post:  Popped element is no longer part of stack
int Stack::pop() {
	StackNode *prev, *ptr;
	int value = tail->data;
	if (head == NULL){
		cout << "The stack is empty, nothing to pop.\n";
		return 0;
	}
	else if (head->next == NULL){
		ptr = head;
		value = head->data;
		head = NULL;
		tail = NULL;
		delete ptr;
	}
	else{
		value = tail->data;
		ptr = head->next;
		prev = head;
		while (ptr->next != NULL){
			ptr = ptr->next;
			prev = prev->next;			
		}
		tail = prev;	
		tail->next = NULL;
		delete ptr;
	}
	return value;
/**/
}


// Desc:  Return the topmost element of the stack.
//  Pre:  Stack is not empty
// Post:  Topmost element is unchanged
int Stack::peek() const {
	return tail->data;
}


// Desc:  Return whether stack is empty or not
// Post:  Stack is unchanged
bool Stack::isEmpty() const {
	return (head == NULL);

}