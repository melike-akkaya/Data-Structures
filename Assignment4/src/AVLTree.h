#ifndef ASS4_AVLTREE_H
#define ASS4_AVLTREE_H

#include <string>
#include <queue>
#include <fstream>
using namespace std;

struct avlNode {
    string name;
    int price;
    int balanceFactor;
    avlNode* leftChild;
    avlNode* rightChild;

    avlNode(string name, int price) {
        this->name = name;
        this->price = price;
        this->balanceFactor = 0;
        this->leftChild = NULL;
        this->rightChild = NULL;
    }
};

class AVLTree {
    public:
        avlNode* root;
        string category;

        AVLTree(avlNode* root, string category);

        // function that calculates the height of the node:
        int getHeight (avlNode* node);

        // function that calculates the balance factor by using the height information of the node:
        void calculateBalanceFactor (avlNode* node);

        // rotation functions used to provide balance:
        avlNode* leftLeftRotation (avlNode* node);
        avlNode* rightRightRotation (avlNode* node);
        avlNode* leftRightRotation (avlNode* node);
        avlNode* rightLeftRotation (avlNode* node);

        // function that provides balance using rotation functions
        avlNode* balance (avlNode* node);

        // function that adds a new name to the tree:
        avlNode* add (string name, int price, avlNode* node);

        // function that remove the chosen name from the tree:
        avlNode* remove (avlNode* node, const string& name);

        // function that returns if the node exists:
        avlNode* search (avlNode* node, string name);

        // function that creates the desired output by traversing the tree by level:
        static void levelOrderTraversal (avlNode* node, int level, fstream& outputFile);
};


#endif //ASS4_AVLTREE_H
