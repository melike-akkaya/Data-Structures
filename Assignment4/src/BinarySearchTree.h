#ifndef ASS4_BINARYSEARCHTREE_H
#define ASS4_BINARYSEARCHTREE_H

#include <fstream>
#include <queue>
#include <string>
#include "AVLTree.h"
#include "RedBlackTree.h"
using namespace std;

struct Node {
    string data;
    Node* leftChild;
    Node* rightChild;

    AVLTree* secondaryAVL;
    RedBlackTree* secondaryRB;


    Node(string data) {
        this->data = data;
        this->leftChild = NULL;
        this->rightChild = NULL;
        this->secondaryAVL = NULL;
        this->secondaryRB = NULL;
    }
};

class BinarySearchTree {
    public:
        Node* root;

        BinarySearchTree(Node* root = NULL);

        // function that adds a new item to the tree:
        Node* add (string item, Node* node);
        // function that returns if the node exists:
        Node* search (Node* node, string name);

        // functions that traverse the tree with the level order and print it to the output file to create the desired output:
        static void levelOrderTraversalAVL(Node* node, fstream &outputFile); //first model
        static void levelOrderTraversalRB(Node* node, fstream &outputFile);//second model
    };

#endif //ASS4_BINARYSEARCHTREE_H
