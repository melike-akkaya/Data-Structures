#include "RedBlackTree.h"
#include <iostream>
using namespace std;

RedBlackTree::RedBlackTree(rbNode* root, string category) {
    this->root = root;
    this->category = category;
}

rbNode* RedBlackTree::rightRotation(rbNode *node){
    rbNode *oldLeft = node->leftChild;

    node->leftChild = oldLeft->rightChild;
    oldLeft->rightChild = node;

    oldLeft->isRed = node->isRed;
    node->isRed= true;

    return oldLeft;
}

rbNode* RedBlackTree::leftRotation(rbNode *node){
    rbNode *oldRight = node->rightChild;

    node->rightChild = oldRight->leftChild;
    oldRight->leftChild = node;

    oldRight->isRed = node->isRed;
    node->isRed = true;

    return oldRight;
}

void RedBlackTree::flipColor(rbNode* node){
    node->isRed = !node->isRed;
    node->leftChild->isRed = !node->leftChild->isRed;
    node->rightChild->isRed = !node->rightChild->isRed;
}

rbNode* RedBlackTree::fixRule(rbNode *node){
    // to control if both left and right child has red connection
    if(is_red(node->leftChild) && is_red(node->rightChild))
        flipColor(node);

    // to control if there is a red connection in the right side
    if(is_red(node->rightChild) && !is_red(node->leftChild))
        node = leftRotation(node);

    // to control if there is more than one red connection in a row
    if(is_red(node->leftChild) && is_red(node->leftChild->leftChild))
        node = rightRotation(node);

    return node;
}

rbNode* RedBlackTree::fix(rbNode* node){
    if(node==NULL) return NULL;
    fix(node->leftChild);
    fix(node->rightChild);
    fixRule(node);
}

rbNode* RedBlackTree::add(rbNode *node,const string& name, int price){
    if (!node)
        return new rbNode(name, price);

    if (node->name < name)
        node->rightChild = add(node->rightChild, name, price);
    else
        node->leftChild = add(node->leftChild,name,price);

    node = fixRule(node);

    return node;
}

bool RedBlackTree::is_red(rbNode *node) {
    return node != NULL && node->isRed;
}

rbNode* RedBlackTree::removeMin(rbNode* node) {
    if (node->leftChild == NULL)
        return NULL;
    if (!is_red(node->leftChild) && !is_red(node->leftChild->leftChild))
        node = fix(node);
    node->leftChild = removeMin(node->leftChild);
    return fixRule(node);
}

rbNode* RedBlackTree::remove(rbNode* node, string name) {
    if (name < node->name) {
        if (!is_red(node->leftChild) && !is_red(node->leftChild->leftChild))
            node = fix(node);
        node->leftChild = remove(node->leftChild, name);
    }
    else {
        if (is_red(node->leftChild))
            node = rightRotation(node);

        if (name == node->name && (node->rightChild == NULL))
            return NULL;
        if (!is_red(node->rightChild) && !is_red(node->rightChild->leftChild))
            node = fix(node);
        if (name == node->name)
        {
            rbNode* temp = node->rightChild;
            while (temp->leftChild != NULL)
                temp = temp->leftChild;
            node->name = temp->name;
            node->price = temp->price;
            node->rightChild = removeMin(node->rightChild);
        }
        else
            node->rightChild = remove(node->rightChild, name);
    }
    return fixRule(node);
}

int RedBlackTree::getHeight(rbNode *node) {
    if (node == NULL)
        return 0;

    int rightHeight = getHeight(node->rightChild);
    int leftHeight = getHeight(node->leftChild);

    // return whichever is greater than right and left height
    if (rightHeight > leftHeight)
        return rightHeight + 1;

    return leftHeight + 1;
}

rbNode *RedBlackTree::search(rbNode *node, string key) {
    if (node == NULL || node->name == key)
        return node;

    if (node->name < key)
        return search(node->rightChild, key);

    return search(node->leftChild, key);
}

void RedBlackTree::levelOrderTraversal(rbNode *node, int level, fstream &outputFile) {
    if (node == NULL) {
        return;
    }
    if (level == 1)
        outputFile<<'"'<<node->name<<'"'<<":"<<'"'<<node->price<<'"'<<",";
    else if (level > 1) {
        levelOrderTraversal(node->leftChild, level - 1, outputFile);
        levelOrderTraversal(node->rightChild, level - 1, outputFile);
    }
}