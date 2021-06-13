/* 
 * Stack.h
 *
 * Description: Implementation of an int sequence with push/pop ...
 * Class Invariant: ... in a LIFO order
 *
 * Author: Aditya Rajvanshi	
 * Date: 01/02/2019
 */
 
class Stack {

    private:

        // Desc:  Nodes for a singly-linked list
        class StackNode {
            public:
                int data;
                StackNode * next;
        };
        

        // Desc:  head = ptr to the first StackNode (NULL if empty)
        //        tail = ptr to the last StackNode (NULL if empty)
        //  Inv:  Follows the A2 Spec, namely that the implementation 
        //        is a singly-linked list, with insert/remove 
        //        operations at the list's tail.
        StackNode * head;
        StackNode * tail;

    public:

        // Desc:  Constructor
        // Post:  Stack is empty
        Stack();


        // Desc:  Destructor
        // Post:  There is no stack
        ~Stack();


        // Desc:  Insert element x to the top of the stack.
        // Post:  Tail points to element x
        void push(int x);


        // Desc:  Remove and return element at the top of the stack.
        //  Pre:  Stack is not empty
        // Post:  Popped element is no longer part of stack
        int pop();


        // Desc:  Return the topmost element of the stack.
        //  Pre:  Stack is not empty
        // Post:  Topmost element is unchanged
        int peek() const;


        // Desc:  Return whether stack is empty or not
        // Post:  Stack is unchanged
        bool isEmpty() const;
};


