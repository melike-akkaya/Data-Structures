#include "BinarySearchTree.h"
#include <iostream>

BinarySearchTree::BinarySearchTree(Node *root) {
    this->root = root;
}

Node* BinarySearchTree::add(string item, Node* node) {
    Node* newNode = new Node(item);

    if (this->root == NULL)
        this->root = newNode;

    if (node == NULL)
        return  newNode;

    else {
        if (node->data > item)
            node->leftChild = add (item, node->leftChild);
        else if (node->data < item)
            node->rightChild = add (item, node->rightChild);
    }

    return node;
}

Node* BinarySearchTree::search(Node *node, string name) {
    if (node == NULL || node->data == name)
        return node;

    if (node->data < name)
        return search(node->rightChild, name);

    return search(node->leftChild, name);
}


void BinarySearchTree::levelOrderTraversalAVL(Node *node, fstream &outputFile) {
    if (node == NULL)
        return;

    // in order to print by level, it is necessary to keep the items in a queue
    queue<Node*> q;
    // add first item
    q.push(node);

    while (!q.empty()) {
        Node* node = q.front();
        outputFile << '"'<<node->data<<'"'<<":"<<endl;
        for (int level = 1; level <= node->secondaryAVL->getHeight(node->secondaryAVL->root); level++) {
            outputFile<<"\t";
            AVLTree::levelOrderTraversal(node->secondaryAVL->root, level, outputFile);
            outputFile<<endl;
        }
        q.pop(); //pop the item that has been written

        // add new items to be written
        if (node->leftChild != NULL)
            q.push(node->leftChild);
        if (node->rightChild != NULL)
            q.push(node->rightChild);
    }
}

void BinarySearchTree::levelOrderTraversalRB(Node *node, fstream &outputFile) {
    if (node == NULL)
        return;

    // in order to print by level, it is necessary to keep the items in a queue
    queue<Node*> q;
    // add first item
    q.push(node);

    while (!q.empty()) {
        Node* node = q.front();
        outputFile << '"'<<node->data<<'"'<<":"<<endl;
        for (int level = 1; level <= node->secondaryRB->getHeight(node->secondaryRB->root); level++) {
            outputFile<<"\t";
            RedBlackTree::levelOrderTraversal(node->secondaryRB->root, level, outputFile);
            outputFile<<endl;
        }

        q.pop(); //pop the item that has been written

        if (node->leftChild != NULL)
            q.push(node->leftChild);
        if (node->rightChild != NULL)
            q.push(node->rightChild);
    }
}
