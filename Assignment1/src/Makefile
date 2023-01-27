findtreasure : main.o MapOperations.o Utility.o
	g++ main.o MapOperations.o Utility.o -o findtreasure

main.o : main.cpp
	g++ -std=c++11 -c main.cpp

MapOperations.o : MapOperations.cpp MapOperations.h
	g++ -std=c++11 -c MapOperations.cpp

Utility.o : Utility.cpp Utility.h
	g++ -std=c++11 -c Utility.cpp

clean :
	rm *.o findtreasure