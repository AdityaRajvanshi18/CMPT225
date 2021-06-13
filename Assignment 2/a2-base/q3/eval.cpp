
#include "Scanner.h"
#include "Stack.h"  // GENERIC STACK

#include <iostream>
using namespace std;



int main () {
    Scanner S(cin);
    Token t;
    Token top;
    Token num1;
    Token num2;
    Token oper;
    Token value;
    Stack<Token> numstack, opstack;  // 2x Stacks of type Token
    

    t = S.getnext();

while (t.tt != eof || (opstack.isEmpty() != true)){
	if (t.tt == integer){
		numstack.push(t);
		t = S.getnext();
	}
	else if (t.tt == lptok){
		opstack.push(t);
		t = S.getnext();
	}	
	else if (t.tt == rptok){
		if(opstack.isEmpty() != 1)
		{
			top = opstack.peek();
		}
		if (top.tt == lptok){
			opstack.pop();
			t = S.getnext();
		}
		else{
			num2 = numstack.pop();
			num1 = numstack.pop();
			oper = opstack.pop();
			if (oper.text == "+"){
				value.val = num1.val + num2.val;
				numstack.push(value);

			}
			else if (oper.text == "-"){
				value.val = num1.val - num2.val;
				numstack.push(value);

			}
			else if (oper.text == "*"){
				value.val = num1.val * num2.val;
				numstack.push(value);

			}
			else if (oper.text == "/"){
				value.val = num1.val / num2.val;				
				numstack.push(value);

			}		
		}
	}
	else if (t.tt == pltok || t.tt == mitok || t.tt == eof){
		if(opstack.isEmpty() != 1)
		{
			top = opstack.peek();
		}
				
		if ((opstack.isEmpty() != true) && (top.text == "+" || top.text == "-" || top.text == "*" || top.text == "/")){
			num2 = numstack.pop();
			num1 = numstack.pop();
			oper = opstack.pop();
			if (oper.text == "+"){
				value.val = (num1.val + num2.val);
				numstack.push(value);

			}
			else if (oper.text == "-"){
				value.val = (num1.val - num2.val);
				numstack.push(value);

			}
			else if (oper.text == "*"){
				value.val = (num1.val * num2.val);
				numstack.push(value);


			}
			else if (oper.text == "/"){
				value.val = (num1.val / num2.val);				
				numstack.push(value);

			}
		}		

		else{
			opstack.push(t);
			t = S.getnext();
		}
	}
	else if( t.tt == asttok || t.tt == slashtok){
		if(opstack.isEmpty() != 1){
			top = opstack.peek();
		}	
		if ((opstack.isEmpty() != true) && (top.text == "*" || top.text == "/")){
			num2 = numstack.pop();
			num1 = numstack.pop();
			oper = opstack.pop();
			if (oper.tt == pltok){
				value.val =num1.val * num2.val;
				numstack.push(value);

			}
			else{
				value.val = num1.val / num2.val;
				numstack.push(value);
			}				
		}
		else{
			opstack.push(t);
			t = S.getnext();
		}
	}
}
	Token temp;
	temp = numstack.pop(); //to print
	cout << "The final answer is "<< temp.val << "\n"; //to print
	return 0;
}











