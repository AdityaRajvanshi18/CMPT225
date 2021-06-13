#include<iostream>
#include<cstring>
#include "Node.h"

using namespace std;

//Private methods implementation

//Description: Copy constructor
Tree::Tree(const Tree &);

//Description: Assignment operator overload
const Tree::Tree & operator=(const Tree &){

}

//Description: Recursively destroys the tree
void Tree::cut(Node * N){
	if (N){
		cut(N->left);
		cut(N->right);
		delete N;
	}
}

//Description: Prints tree
void Tree::print(ostream &, Node *, int) const{

}
void Tree::print(Node *, int) const{

}

/********************************************************/

//Constructors and Destructors
	
//Constructor
Tree::Tree(void){
    Node* N = new Node;
    root = N;
}

//Destructor
Tree::~Tree(void){
	cut(root);
}

/********************************************************/
//Description: Overload operator
friend ostream & operator<<(ostream &, const Tree &){

}


//Getters and Setters

//Description: Gets frequency
unsigned int Tree::getFreq(void) const{
	return root->freq;
}

//Description: Gets char
unsigned char Tree:getChar(void) const{
	return root->ch;
}

//Description: Gets left child
Node* Tree::getLeft(void) const{
	return root->left;
}

//Description: Gets right child
Node* Tree::getRight(void) const{
	return root->right;
}

//Description: Gets root node
Node* Tree:getRoot(void) const{
	return root;
}

//Description: Sets frequency
void Tree::setFreq(unsigned int aFreq){
	root->freq = aFreq;
}

//Description: Sets char
void Tree::setChar(unsigned char aCh){
	root->ch = aCh;
}
//Description: Sets left child
void Tree::setLeft(Node * aLc){
	root->left = aLc;
}
//Description: Sets right child
void Tree::setRight(Node * aRc){
	root->right = aRc;
}

//Description: Comparison operators overloaded to compare 2 objects of the class
bool operator==(const Tree &) const;
bool operator!=(const Tree &) const;
bool operator<(const Tree &) const;
bool operator>(const Tree &) const;
bool operator<=(const Tree &) const;
bool operator>=(const Tree &) const;


//Description: To get Huffman string of a given char
void Tree::huf(Node *, unsigned char, string, string &) const{

}

//Description: Outputs the Huffman char-string pairs list
void Tree::hufList(Node *, string) const{

}

//Description: To get char equivalent of a Huffman string 
bool Tree::getHufChar(string, unsigned char &) const{

}

//Description: Prints chars
string printChar(Node *) const{

}
