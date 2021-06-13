/*
 * List.h
 * 
 * Class Description: List data collection ADT.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicates).
 *                   - Each element is added in order of Care Card Number.
 *
 * Author: Aditya Rajvanshi - 301349754
 * Date: 20/01/2019
 */

#include <iostream>
#include <string>
#include "Patient.h"
#include "List.h"

// Default constructor

	List::List() {
	Patient elements[MAX_ELEMENTS];
	elementCount = 0;
	capacity = MAX_ELEMENTS;
}
	//Getters

	// Description: Returns the total element count currently stored in List.
	int  List::getElementCount() const{
		return elementCount;
}

	// Description: Search for target element.
	//              Returns a pointer to the element if found,
	//              otherwise, returns NULL.
	Patient* List::search(const Patient& target){
		for (int i=0; i< getElementCount(); i++){
			if (elements[i]  == target){
				return &elements[i];
			}
		}
		return NULL;
}

	//Setters

	// Description: Insert an element.
	// Precondition: newElement must not already be in data collection.  
	// Postcondition: newElement inserted and elementCount has been incremented.   
	bool List::insert(const Patient& newElement){
		//check if newElement is not already in the list.
		Patient* check = search(newElement);
		if (check != NULL){
			return false;
		}
		//else if (newElement.length() != 10)
		//	return false;
		else{
			//See if there is still space in array.
			if (elementCount < capacity){
				//Insert new patient in array based on CareCard order
				for(int i = 0; i < getElementCount(); i++){
					if (elements[i] > newElement){
						for(int j = getElementCount(); j>i; j--){ 
							elements[j] = elements[j-1];
						}
						elements[i] = newElement;
						elementCount++;
						return true;
					}
					if (elements[i] == newElement){
						return false;
					}
				}
				elements[elementCount] = newElement;
				elementCount++;
				return true;
			}
			return true;
		}
}

	// Description: Remove an element. 
	// Postcondition: toBeRemoved is removed and elementCount has been decremented.	
	bool List::remove( const Patient& toBeRemoved ){
		//Find element toBeRemoved from list.
		for (int i = 0; i< getElementCount(); i++){
			if(elements[i] == toBeRemoved){			//Once element to remove is found
				for(int j = i+1; j<elementCount; j++){	//Set current element to 1 + toBeRemoved	
					elements[j-1] = elements[j];	//Set current-1 (which is toBeRemoved) as current
				}					//toBeRemoved is removed, decrease element count.
				elementCount--;	
				return true;
			}
		}
		return false;
}
	// Description: Remove all elements.
	void List::removeAll(){
		elementCount = 0;
		return;
}


	//Print

	//Description: Prints all elements in the list.
	void List::fullprint(){
		for (int i = 0; i< getElementCount(); i++){
			operator<<(cout, elements[i]);
		}
}

// end of List.cpp
