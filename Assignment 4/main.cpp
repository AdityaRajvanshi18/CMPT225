/*
 * Main.cpp
 *
 * Description: Huffman compression/decompression
 * Author: Aditya Rajvanshi
 * Created: 19/02/2019
 *
 */

#include"PQ.h"
#include"Tree.cpp"

using namespace std;

#include<iostream>
#include<fstream>
#include<cstring>
#include<iomanip>
#include<cctype>
#define HELP_ERROR 99


//the given bit will be written to the output file stream
//input : unsigned char i(:0 or 1 : bit to write ; 2:EOF) 
void hufWrite(unsigned char i, ofstream & outfile){
	static int bit_pos=0; //0 to 7 (left to right) on the byte block
    	static unsigned char c='\0'; //byte block to write

    	if(i<2) //if not EOF
    	{
        	if(i==1){
            		c=c | (i<<(7-bit_pos)); //add a 1 to the byte
        	}
		else{ //i==0
            		c=c & static_cast<unsigned char>(255-(1<<(7-bit_pos))); //add a 0
        	}
		++bit_pos;
        	bit_pos%=8;
        	if(bit_pos==0){
            		outfile.put(c);
            		c='\0';
        	}
    	}
   	else
    	{
        	outfile.put(c);
    	}
}

//input : a input file stream to read bits
//return: unsigned char (:0 or 1 as bit read or 2 as EOF) 
unsigned char hufRead(ifstream & infile){
    	static int bit_pos=0; //0 to 7 (left to right) on the byte block
    	static unsigned char c=infile.get();

    	unsigned char i;

   	i=(c>>(7-bit_pos))%2; //get the bit from the byte
    	++bit_pos;
    	bit_pos%=8;
    	if(bit_pos==0){
        	if(!infile.eof()){
            	c=infile.get();
        	}
        	else{
            	i=2;
		}
	}
    return i;     
}

//Huffman Encoder
void encoder(string ifile, string ofile, bool verbose){
	ifstream infile(ifile.c_str(), ios::in|ios::binary);
    	if(!infile){
        	cerr<<ifile<<" could not be opened!"<<endl;
        	exit(1);
    	}
	if(ifstream(ofile.c_str())){
        	cerr<<ofile<<" already exists!"<<endl;
        	exit(1);
    	}

	//open the output file
    	ofstream outfile(ofile.c_str(), ios::out|ios::binary);
    	if(!outfile){
        	cerr<<ofile<<" could not be opened!"<<endl;
        	exit(1);
    	}

    	//array to hold frequency table for all ASCII characters in the file
    	unsigned int f[256];
    	for(int i=0;i<256;++i){
        	f[i]=0;
	}
    	//read the whole file and count the ASCII char table frequencies
    	char c;
    	unsigned char ch;
    	while(infile.get(c)){
        	ch=c;
        	++f[ch];
    	}

    	infile.clear(); //clear EOF flag
    	infile.seekg(0); //reset get() pointer to beginning

    	PQueue<Tree> q(3); //use a 3-(priority)heap
    	Tree* tp;

    	for(int i=0;i<256;++i){
        	//output char freq table to the output file
        	//divide 32 bit u. int values into 4 bytes
        	outfile.put(static_cast<unsigned char>(f[i]>>24));
        	outfile.put(static_cast<unsigned char>((f[i]>>16)%256));
        	outfile.put(static_cast<unsigned char>((f[i]>>8)%256));
        	outfile.put(static_cast<unsigned char>(f[i]%256));
 	
        	if(f[i]>0){
            	//send freq-char pairs to the priority heap as Huffman trees
            	tp=new Tree;
            	(*tp).setFreq(f[i]);
            	(*tp).setChar(static_cast<unsigned char>(i));
            	q.enqueue(tp);
        	}
    	}

    	//construct the main Huffman Tree
    	Tree* tp2;
    	Tree* tp3;

    	do{
        	tp=q.dequeue();
        	if(!q.isEmpty()){
            	//get the 2 lowest freq. H. trees and combine them into one
            	//and put back into the priority heap
            	tp2=q.dequeue();
            	tp3=new Tree;
            	(*tp3).setFreq((*tp).getFreq()+(*tp2).getFreq());
            	(*tp3).setLeft((*tp).getRoot());
            	(*tp3).setRight((*tp2).getRoot());
            	q.enqueue(tp3);
        	}
    	}
    	while(!q.isEmpty()); //until all sub-trees combined into one

    	//find H. strings of all chars in the H. tree and put into a string table
    	string H_table[256];
    	unsigned char uc;
    	for(unsigned short us=0;us<256;++us){
        	H_table[us]="";
        	uc=static_cast<unsigned char>(us);
        	(*tp).huf((*tp).getRoot(), uc, "", H_table[us]);
    	} 

    	if(verbose){
        	cout<<*tp<<endl; //output the Huffman tree
        	//output the char-H. string list 
        	(*tp).hufList((*tp).getRoot(), "");
        	cout<<"frequency table is "<<sizeof(unsigned int)*256<<" bytes"<<endl;
    	}

    	unsigned int total_chars=(*tp).getFreq();
    	cout<<"total chars to encode:"<<total_chars<<endl;

    	//output Huffman coded chars into the output file
    	unsigned char ch2;
    	while(infile.get(c)){
        	ch=c;
        	//send the Huffman string to output file bit by bit
        	for(unsigned int i=0;i<H_table[ch].size();++i){
            		if(H_table[ch].at(i)=='0')
                		ch2=0;
            		if(H_table[ch].at(i)=='1')
                		ch2=1;
            	hufWrite(ch2, outfile);
        	}
    	}
    	ch2=2; // send EOF
    	hufWrite(ch2, outfile);

    	infile.close();
    	outfile.close();

} //end of Huffman encoder

//Huffman Decoder
void decoder(string ifile, string ofile, bool verbose){
    	ifstream infile(ifile.c_str(), ios::in|ios::binary);
    	if(!infile){
        cerr<<ifile<<" could not be opened!"<<endl;
        exit(1);
    	}	

    	if(ifstream(ofile.c_str())){
        cerr<<ofile<<" already exists!"<<endl;
        exit(1);
    	}

    	//open the output file
    	ofstream outfile(ofile.c_str(), ios::out|ios::binary);
    	if(!outfile){
        cerr<<ofile<<" could not be opened!"<<endl;
        exit(1);
    	}

    	//read frequency table from the input file
    	unsigned int f[256];
    	char c;
    	unsigned char ch;
    	unsigned int j=1;
    	for(int i=0;i<256;++i){
        
	//read 4 bytes and combine them into one 32 bit u. int value
        	f[i]=0;
        	for(int k=3;k>=0;--k){
            		infile.get(c);
            		ch=c;
            		f[i]+=ch*(j<<(8*k));
        	}
    	}

    	//re-construct the Huffman tree
    	PQueue<Tree> q(3); //use a 3-(priority)heap (again)
    	Tree* tp;

    	for(int i=0;i<256;++i){
        	if(f[i]>0){
            
			//send freq-char pairs to the priority heap as Huffman trees
            	tp=new Tree;
            	(*tp).setFreq(f[i]);
            	(*tp).setChar(static_cast<unsigned char>(i));
            	q.enqueue(tp);
       		}
    	}

    	//construct the main Huffman Tree (as in Encoder func.)
    	Tree* tp2;
    	Tree* tp3;

    	do{
        	tp=q.dequeue();
        	if(!q.isEmpty()){
            		//get the 2 lowest freq. H. trees and combine them into one
            		//and put back into the priority heap
            		tp2=q.dequeue();
            		tp3=new Tree;
            		(*tp3).setFreq((*tp).getFreq()+(*tp2).getFreq());
            		(*tp3).setLeft((*tp).getRoot());
            		(*tp3).setRight((*tp2).getRoot());
            		q.enqueue(tp3);
        	}
    	}
    	while(!q.isEmpty()); //until all sub-trees combined into one

    	if(verbose){
        	cout<<*tp<<endl; //output the Huffman tree
        	//output the char-H. string list 
        	(*tp).hufList((*tp).getRoot(), "");
        	cout<<"frequency table is "<<sizeof(unsigned int)*256<<" bytes"<<endl;
    	}

    	//read Huffman strings from the input file
    	//find out the chars and write into the output file
    	string st;
    	unsigned char ch2;
    	unsigned int total_chars=(*tp).getFreq();
    	while(total_chars>0){
        	st=""; //current Huffman string
        	do{
            		//read H. strings bit by bit
            		ch=hufRead(infile);
            		if(ch==0)
               			st=st+'0';
            		if(ch==1)
                		st=st+'1';
        	} //search the H. tree
        	while(!(*tp).getHufChar(st, ch2)); //continue until a char is found

        	//output the char to the output file
        	outfile.put(static_cast<char>(ch2));
        	--total_chars;
    	}

	infile.close();
    	outfile.close();

} //end of Huffman decoder

void usage_msg ( const string & pname ){
   	cerr << "Usage: " << pname << " : valid flags are :" << endl;
        cerr << " -c compress file  : required" << endl;
        cerr << " -d decompress file : required" << endl;
//      << " -v  : verbose mode" << endl
	cerr << " -h  : this help screen" << endl;
}

int main( int argc, char * argv[] )
{
    	string in_name;
    	string out_name;
    	bool encode = true;
   	bool verbose = false;

    	for ( int i = 1 ; i < argc ; ++i ){
        	if ( !strcmp( "-h", argv[i] ) || !strcmp( "--help", argv[i] ) ){
            		usage_msg( argv[0] );
            		exit( HELP_ERROR );
        	}
        	else if ( !strcmp( "-i", argv[i] ) ){
            		cerr << "input file is '" << argv[++i] << "'" << endl;
            		in_name = argv[i];
        	}
        	else if ( !strcmp( "-o", argv[i] ) ){
            		cerr << "output file is '" << argv[++i] << "'" << endl;
            		out_name = argv[i];
        	}
        	else if ( !strcmp( "-d", argv[i] ) ){
            		encode = false;
			in_name = argv[i+1];
			out_name = argv[i+2];
			
        	}
        	else if ( !strcmp( "-c", argv[i] ) ){
            		encode = true;
			in_name = argv[i+1];
			out_name = argv[i+2];
			
        	}

    	}
    	if ( !in_name.size() || !out_name.size() ){
        	cerr << "input and output file are required, nothing to do!" << endl;
        	usage_msg( argv[0] );
        	exit( HELP_ERROR );
    	}

    	if ( encode ){
         	encoder( in_name, out_name, verbose );
		cerr << in_name << " -> " << in_name.size() << "bytes" << endl;
		cerr << out_name << " -> " << out_name.size() << "bytes" << endl;
		if (out_name.size() > in_name.size()){
			cerr << "*** Size of compressed file > size of source file ***" << endl;
		}
    	}
    	else{
        	decoder( in_name, out_name, verbose );
    	}
    	return 0;
}



