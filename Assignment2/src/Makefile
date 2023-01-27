networkmap : main.o Operations.o Utility.o Apartment.o ApartmentLinkedList.o Flat.o FlatLinkedList.o
	g++ main.o Operations.o Utility.o Apartment.o ApartmentLinkedList.o Flat.o FlatLinkedList.o -o networkmap

main.o : main.cpp
	g++ -std=c++11 -c main.cpp

Operations.o : Operations.cpp Operations.h
	g++ -std=c++11 -c Operations.cpp

Utility.o : Utility.cpp Utility.h
	g++ -std=c++11 -c Utility.cpp

Apartment.o : Apartment.cpp Apartment.h
	g++ -std=c++11 -c Apartment.cpp

ApartmentLinkedList.o : ApartmentLinkedList.cpp ApartmentLinkedList.h
	g++ -std=c++11 -c ApartmentLinkedList.cpp

Flat.o : Flat.cpp Flat.h
	g++ -std=c++11 -c Flat.cpp

FlatLinkedList : FlatLinkedList.cpp FlatLinkedList.h
	g++ -std=c++11 -c FlatLinkedList.cpp


clean :
	rm *.o findtreasure