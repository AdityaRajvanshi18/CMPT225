/*
 * Tree.h
 *
 * Class Description: A huffman tree
 * Class Invariant:  Left means "0" in the char string and right means "1"
 * Author: Aditya Rajvanshi
 * Created: 18/03/2019
 *
 */

#include<iostream>
#include<cstring>
#include "Node.h"

using namespace std;

class Tree{

private:

	Node* root;
	//Description: Copy constructor
	Tree(const Tree &);

	//Description: Assignment operator overload
        const Tree & operator=(const Tree &);

	//Description: Destroys the tree
        void cut(Node * N);

	//Description: Prints tree
        void print(ostream & os, Node * curr, int level) const; 
        void print(Node * curr, int level) const; 

public:

	//Constructors and Destructors
	
	//Constructor
	Tree(); 

	//Destructor
        ~Tree(void);

	//Description: Overload operator
        friend ostream & operator<<(ostream & os, const Tree & t);


        //Getters and Setters

	//Description: Gets frequency
        unsigned int getFreq(void) const;

	//Description: Gets char
        unsigned char getChar(void) const;

	//Description: Gets left child
        Node* getLeft(void) const;

	//Description: Gets right child
        Node* getRight(void) const;

	//Description: Gets root node
        Node* getRoot(void) const;

	//Description: Sets frequency
        void setFreq(unsigned int aFreq);

	//Description: Sets char
        void setChar(unsigned char aCh);

	//Description: Sets left child
        void setLeft(Node * aLc);

	//Description: Sets right child
        void setRight(Node * aRc);

        //Description: Comparison operators overloaded to compare 2 objects of the class
        bool operator==(const Tree & T) const;
        bool operator!=(const Tree & T) const;
        bool operator<(const Tree & T) const;
        bool operator>(const Tree & T) const;
        bool operator<=(const Tree & T) const;
        bool operator>=(const Tree & T) const;

//Description: To get Huffman string of a given char
void huf(Node * N, unsigned char c, string st, string & s) const; 

//Description: Outputs the Huffman char-string pairs list
void hufList(Node * N, string st) const; 

//Description: To get char equivalent of a Huffman string 
bool getHufChar(string s, unsigned char & c) const;

//Description: Prints chars
string printChar(Node * N) const;

};
