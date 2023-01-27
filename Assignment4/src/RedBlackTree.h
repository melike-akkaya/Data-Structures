#ifndef ASS4_REDBLACKTREE_H
#define ASS4_REDBLACKTREE_H

#include <string>
#include <fstream>
using namespace std;

struct rbNode {
    rbNode* leftChild;
    rbNode* rightChild;
    string name;
    int price;
    bool isRed; //true if it is red, false if it is black

    rbNode(string data, int price) {
        this->price = price;
        this->leftChild = NULL;
        this->rightChild = NULL;
        this->name = data;
        // color will be red when new node is created
        this->isRed = true;
    }
};

class RedBlackTree {
    public:
        RedBlackTree(rbNode* root, string category);

        rbNode* root;
        string category;

        // these functions are used to provide balance
        rbNode* leftRotation(rbNode* node);
        rbNode* rightRotation(rbNode* node);
        void flipColor (rbNode* node);

        // function that sets tree to satisfy left leaning red black tree conditions
        rbNode* fixRule(rbNode* node);
        rbNode* fix(rbNode* node);

        // function to add new item to the tree
        rbNode* add(rbNode* node, const string& name, int price);

        // function which controls if the node is red
        bool is_red(rbNode* node);

        // functions to remove an item from the tree while keeping balance
        rbNode* removeMin(rbNode* node);
        rbNode* remove(rbNode* node, string name);

        // function that calculates the height of the node:
        int getHeight (rbNode* node);
        // function that returns if the node exists:
        rbNode* search (rbNode* node, string key);
        // function that creates the desired output by traversing the tree by level:
        static void levelOrderTraversal (rbNode* node, int level, fstream& outputFile);

};


#endif //ASS4_REDBLACKTREE_H
