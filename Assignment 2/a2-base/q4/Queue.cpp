/* 
 * Queue.cpp
 *
 * Description: Implementation of an int sequence with enqueue/dequeue ...
 * Class Invariant: ... in FIFO order
 *
 * Author:
 * Date:
 */
 
#include "Queue.h"


// Desc:  Constructor
Queue::Queue() : elementCount(0), capacity(INITIAL_SIZE), frontindex(0), backindex(0) {
} // constructor

//Desc:	  Destructor
Queue::Queue() {

}

// Desc:  Inserts element x at the back (O(1))
void Queue::enqueue(int x) {
    elementCount++;
    *elements[backindex] = x;
    backindex = (backindex + 1) % capacity;
} // enqueue


// Desc:  Removes the frontmost element (O(1))
//  Pre:  Queue not empty
void Queue::dequeue() {
    elementCount--;
    frontindex = (frontindex + 1) % capacity;
} // dequeue


// Desc:  Returns a copy of the frontmost element (O(1))
//  Pre:  Queue not empty
int Queue::peek() const {
    return elements[frontindex];
} // top


// Desc:  Returns true if and only if queue empty (O(1))
bool Queue::isEmpty() const {
    return elementCount == 0;
} // isempty




