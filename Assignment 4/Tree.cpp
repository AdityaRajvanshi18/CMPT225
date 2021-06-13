/*
 * Tree.cpp
 *
 * Class Description: A huffman tree
 * Class Invariant:  Left means "0" in the char string and right means "1"
 * Author: Aditya Rajvanshi
 * Created: 18/03/2019
 *
 */

#include<iostream>
#include<cstring>
#include<fstream>
#include<iomanip>
#include<cctype>
#include "Tree.h"


//Constructors and Destructors
	
//Constructor
Tree::Tree(){
    Node* N = new Node;
    root = N;
}

//Destructor
Tree::~Tree(void){
	cut(root);
}

/********************************************************/

//Private methods implementation
/*
//Description: Copy constructor
Tree::Tree(const Tree &);

//Description: Assignment operator overload
const Tree::Tree & operator=(const Tree &);
*/
//Description: Recursively destroys the tree
void Tree::cut(Node * N){
	if (N){
		cut(N->left);
		cut(N->right);
		delete N;
	}
}

//Description: Recursive tree print
void Tree::print(ostream & os, Node * curr, int level) const{
	if(curr){
		print(os, curr->right, level+1);
		os << setw(level*5) << printChar(curr)<< ":" << curr->freq << endl;
		print(os, curr->left, level+1);
	}
}
//Description: Recursive tree print
void Tree::print(Node * curr, int level) const{
 	if(curr){
		print(curr->right,level+1);
        	cout<<setw(level*5)<<printChar(curr)<<":"<<curr->freq<<endl;
        	print(curr->left,level+1);
   	}
}

/********************************************************/
//Description: Overload operator
ostream & operator<<(ostream &os, const Tree &t){
	t.print(os, t.root, 1);
	return os;
}


//Getters and Setters

//Description: Gets frequency
unsigned int Tree::getFreq(void) const{
	return root->freq;
}

//Description: Gets char
unsigned char Tree::getChar(void) const{
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
Node* Tree::getRoot(void) const{
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
bool Tree::operator==(const Tree & T) const{
	return (root->freq == T.root->freq);
}
bool Tree::operator!=(const Tree & T) const{
	return (root->freq != T.root->freq);
}
bool Tree::operator<(const Tree & T) const{
	return (root->freq < T.root->freq);
}
bool Tree::operator>(const Tree & T) const{
	return (root->freq > T.root->freq);
}
bool Tree::operator<=(const Tree & T) const{
	return (root->freq <= T.root->freq);
}
bool Tree::operator>=(const Tree & T) const{
	return (root->freq >= T.root->freq);
}


//Description: Recursively get Huffman string of a given char
//Postcondition: Tree is unchanged, huffman string is returned
void Tree::huf(Node * N, unsigned char c, string st, string & s) const{
	if(N){
		if(!N->left && !N->right && N->ch == c){
			s = st;
		}
		else{
			huf(N->left, c, st+"0", s);
			huf(N->right, c, st+"1", s);
		}
	}
}

//Description: Recursively outputs the Huffman char-string pairs list
//Postcondition: Huffman tree is unchanged, returns list of chars and their string code in the huffman tree
void Tree::hufList(Node * N, string st) const{
	if(N){
        	if(!N->left && !N->right){
            		cout<<printChar(N)<<" "<<st<<endl;
        	}
		else
        	{
            	hufList(N->left, st+"0");
            	hufList(N->right, st+"1");
        	}
    	}
}

//Description: To get char equivalent of a Huffman string 
//Postcondition: True if char is found, else false
bool Tree::getHufChar(string s, unsigned char & c) const{
    	Node * curr=root;
	for(unsigned int i=0;i<s.size();++i){
        	if(s[i]=='0'){
         		curr=curr->left;
		}
        		if(s[i]=='1'){
            		curr=curr->right;
		}
    	}		
    	bool found=false;
    	if(!curr->left && !curr->right){
        	found=true;
        	c=curr->ch;
    	}
   	return found;
}

//Description: Prints chars
//Postcondition: Tree is unchanged, returns string form of inputted char
string Tree::printChar(Node * N) const{
    	string s="";
	unsigned char c;

    	if(!N->left && !N->right){
        c = N->ch;
	}
        //if the char is not printable then output its ASCII code
        if(iscntrl(c) || c==32){
            	char* cp = new char;
            	for(int i=0;i<3;++i){
                	sprintf(cp,"%i",c%8);
                	c -= c%8;
                	c/=8;
                	s=(*cp)+s;
            	}
            	s='/'+s; 
        }
        else{
        	s=c;
	}
    return s;
}
