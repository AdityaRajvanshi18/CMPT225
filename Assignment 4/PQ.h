/*
 * PriorityQueue.h
 *
 * Class Description: A priority queue class that uses heaps
 * Class Invariant: After each enqueue and dequeue the PQ is in order.
 *                   
 * Author: Aditya Rajvanshi
 * Created: 15/03/2019
 *
 */

#include<iostream>

using namespace std;

template<class T>
class PQueue{
 
    private:

        int back; //the last element in the queue
        T* *arr; //dynamic array
        int size; //current size of the queue array
        static const int SIZE=10; //size increment step size  
        int D; //max number of children for a parent>=2 

        //copy constructor and assignment are hidden to protect 
        PQueue(const PQueue &);
        const PQueue & operator=(const PQueue &);

        //utility functions to fix the heap when an element added or removed 

	//Description: Recursive function to fix order upwards after a new element is added to the queue
	//Precondition: An element was just added to the queue
	//Postcondition: The PQ is in order again
        void reheapup(int root, int bottom);
 
	//Description: Recursive function to fix the order downwards after an element is removed from the queue 
	//Precondition: An element was dequeued
	//Postcondition: The PQ is in order again
        void reheapdown(int root, int bottom); 

	//Description: Swaps the values of two variables
	//Postcondition: a is now b and b is now a
        void swap(T* &a, T* &b); 
   public:

	//Constructors and Destructors

	//Constructor
        PQueue(int d=2);

	//Deconstructor
        ~PQueue(void);

/**************************************************/
	
	//Description: Enqueue's in the back then reordered
	//Postcondition: element is enqueued in PQueue
        void enqueue(T* element); 

	//Description: Dequeues's front of queue
	//Postcondition: Element is dequeued in PQueue
        T* dequeue(void); 

	//Description: Returns the element at the front of queue
	//Postcondition: element and PQ is unchanged
        T* front(void); 

	//Description: Returns true if queue is empty, false otherwise
	//Postcondition: PQ is unchanged
        bool isEmpty(void) const; 

	//Description: Returns true if queue is full, false otherwise
	//Postcondition: PQ is unchanged
        bool isFull(void) const; 

	void printPQ(void) const;


}; //PQ.h

//Constructors and Deconstructors

//Constructor
template<class T>
PQueue<T>::PQueue(int d){
    if(d<2) d=2; 
    D=d;
    back=0;
    size=SIZE;
    arr=new T*[size];
}

//Deconstructor
template<class T>
PQueue<T>::~PQueue(void){
    delete[] arr;
}

/************************************************/


//Description: Enqueues element to the back then reorders
//Postcondition: element is enqueued in PQueue
template<class T>
void PQueue<T>::enqueue(T* element){
    if(isFull()){ //Expand array if full

        int newsize=size+SIZE; 
        T* *newarr=new T*[newsize];
        for(int i=0;i<size;++i){
		newarr[i]=arr[i];
	}
        delete[] arr;
        arr=newarr; 
        size=newsize; 
    }

    //the new element added to the back of the queue
    //and the reheapup called to fix the order back
    arr[back++]=element;
    reheapup(0, back-1); 
}

//Description: Dequeues from the front of queue
//Postcondition: Element is dequeued in PQueue
template<class T>
T* PQueue<T>::dequeue(void){
    if(isEmpty()){
        cerr<<"dequeue error! exiting..."<<endl; //stream for errors, included in iostream
        exit(1);
    }

    T* val=arr[0];
    arr[0]=arr[back-1];
    --back;
    reheapdown(0, back-1); //reheapdown to fix the order 
    return val;
}

//Description: Returns the element at the front of queue
//Postcondition: element and PQ is unchanged
template<class T>
T* PQueue<T>::front(void){
    if(isEmpty()){
        cerr<<"dequeue error! exiting..."<<endl; //stream for errors, included in iostream
        exit(1);
    }

    return arr[0];
}

//Description: Returns true if queue is empty, false otherwise
//Postcondition: PQ is unchanged
template<class T>
bool PQueue<T>::isEmpty(void) const{
    return (back<=0);
}

//Description: Returns true if queue is full, false otherwise
//Postcondition: PQ is unchanged
template<class T>
bool PQueue<T>::isFull(void) const{
    return (back>=size);
}


/**********************************************************************/

//Private utility functions implementation

//Description: Recursive function to fix order upwards after a new element is added to the queue
//Precondition: An element was just added to the queue
//Postcondition: The PQ is in order again
template<class T>
void PQueue<T>::reheapup(int root, int bottom){
    int parent;

    if(bottom > root){
        parent=(bottom-1)/D;

        if(*arr[parent] > *arr[bottom]){
            swap(arr[parent], arr[bottom]);
            reheapup(root, parent);
        }
    }
}

//Description: Recursive function to fix the order downwards after an element is removed from the queue 
//Precondition: An element was dequeued
//Postcondition: The PQ is in order again
template<class T>
void PQueue<T>::reheapdown(int root, int bottom){
    int minchild, firstchild, child;

    firstchild=root*D+1; //the position of the first child of the root

    if(firstchild <= bottom){
        minchild=firstchild; 

        for(int i=2;i <= D;++i){
            child=root*D+i;
            if(child <= bottom){
                if(*arr[child] < *arr[minchild]){
                    minchild=child;
                }
            }
        }
        if(*arr[root] > *arr[minchild]){
            swap(arr[root], arr[minchild]);
            reheapdown(minchild, bottom);
        }
    } 
}

//Description: Swaps the values of two variables
//Postcondition: a is now b and b is now a
template<class T>
void PQueue<T>::swap(T* &a, T* &b){
    T* c;
    c=a;
    a=b;
    b=c;
}

template<class T>
void PQueue<T>::printPQ(void) const{
	for(int i = 0; i < size; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
	return;
}



