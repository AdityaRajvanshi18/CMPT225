/*
 * Node.h
 *
 * Class Description: Node class for tree
 * Class Invariant: Leaf nodes always point to NULL

 * Author: Aditya Rajvanshi
 * Created: 16/03/2019
 *
 */

#include <cstdio>

class Node{
	public:
		//Constructor  
               	Node(void):freq(0), ch('\0'), left(NULL), right(NULL) {}
	
               	unsigned int freq;
               	unsigned char ch;
               	Node *left, *right;
}; //Node.h

