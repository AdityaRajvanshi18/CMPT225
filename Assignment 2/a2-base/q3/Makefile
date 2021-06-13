
infixeval:	Scanner.o eval.o
	g++ -o infixeval Scanner.o eval.o -std=c++0x

Scanner.o:	Scanner.cpp Scanner.h
	g++ -c Scanner.cpp -std=c++0x
	
eval.o:	eval.cpp Scanner.h Stack.h
	g++ -c eval.cpp -std=c++0x
	
clean:	
	rm -f *.o infixeval

