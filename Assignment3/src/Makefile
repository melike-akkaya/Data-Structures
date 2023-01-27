Assignment3 : main.o Barista.o Cashier.o DiscreteEventList.o FirstModel.o Queue.o Order.o SecondModel.o Utility.o
	g++ main.o Barista.o Cashier.o DiscreteEventList.o FirstModel.o Queue.o Order.o SecondModel.o Utility.o -o Assignment3

main.o : main.cpp
	g++ -std=c++11 -c main.cpp

Barista.o : Barista.cpp Barista.h
	g++ -std=c++11 -c Barista.cpp

Utility.o : Utility.cpp Utility.h
	g++ -std=c++11 -c Utility.cpp

Cashier.o : Cashier.cpp Cashier.h
	g++ -std=c++11 -c Cashier.cpp

DiscreteEventList.o : DiscreteEventList.cpp DiscreteEventList.h
	g++ -std=c++11 -c DiscreteEventList.cpp

FirstModel.o : FirstModel.cpp FirstModel.h
	g++ -std=c++11 -c FirstModel.cpp

Queue.o : Queue.cpp Queue.h
	g++ -std=c++11 -c Queue.cpp

Order.o : Order.cpp Order.h
	g++ -std=c++11 -c Order.cpp

SecondModel.o : SecondModel.cpp SecondModel.h
	g++ -std=c++11 -c SecondModel.cpp

clean :
	rm *.o Assignment3