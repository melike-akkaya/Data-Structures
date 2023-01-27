webstore : main.o AVLTree.o BinarySearchTree.o RedBlackTree.o Utility.o
	g++ main.o AVLTree.o BinarySearchTree.o RedBlackTree.o Utility.o -o webstore

main.o : main.cpp
	g++ -std=c++11 -c main.cpp

Utility.o : Utility.cpp Utility.h
	g++ -std=c++11 -c Utility.cpp

AVLTree.o : AVLTree.cpp AVLTree.h
	g++ -std=c++11 -c AVLTree.cpp

BinarySearchTree.o : BinarySearchTree.cpp BinarySearchTree.h
	g++ -std=c++11 -c BinarySearchTree.cpp

RedBlackTree.o : RedBlackTree.cpp RedBlackTree.h
	g++ -std=c++11 -c RedBlackTree.cpp