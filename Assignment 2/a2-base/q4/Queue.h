/* 
 * Queue.h
 *
 * Description: Implementation of an int sequence with enqueue/dequeue ...
 * Class Invariant: ... in FIFO order
 *
 * Author:
 * Date:
 */
  
class Queue {
    private:
        static unsigned const INITIAL_SIZE = 6;
        int * elements[INITIAL_SIZE];  // replace this by int * elements in Question 4(a)

        unsigned elementCount;  // number of elements in the queue
        unsigned capacity;      // number of cells in the array
        unsigned frontindex;    // index the topmost element
        unsigned backindex;     // index where the next element will be placed

    public:
        // Desc:  Constructor
        Queue();
		
		//Desc:   Destructor
		~Queue();


        // Desc:  Inserts element x at the back (O(1))
        void enqueue(int x);


        // Desc:  Removes the frontmost element (O(1))
        //  Pre:  Queue not empty
        void dequeue();


        // Desc:  Returns a copy of the frontmost element (O(1))
        //  Pre:  Queue not empty
        int peek() const;


        // Desc:  Returns true if and only if queue empty (O(1))
        bool isEmpty() const;
};


