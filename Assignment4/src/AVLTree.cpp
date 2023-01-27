#include "AVLTree.h"

AVLTree::AVLTree(avlNode *root, string category) {
    this->root = root;
    this->category = category;
}

int AVLTree::getHeight(avlNode *node) {
    if (node == NULL)
        return 0;

    // calculating both left and right heights
    int rightHeight = getHeight(node->rightChild);
    int leftHeight = getHeight(node->leftChild);

    // return whichever is greater than right and left height
    if (rightHeight > leftHeight)
        return rightHeight + 1;

    return leftHeight + 1;
}

void AVLTree::calculateBalanceFactor(avlNode *node) {
    if (node != NULL) {
        int rightHeight = getHeight(node->rightChild);
        int leftHeight = getHeight(node->leftChild);

        // balance factor of a tree with a heavier left is positive,
        // and the balance factor of a tree with a heavy right is negative
        node->balanceFactor = leftHeight - rightHeight;
    }
}

avlNode* AVLTree::leftLeftRotation(avlNode *node) {
    // this function represents a single rotation to left side
    avlNode* temp = node->leftChild;
    node->leftChild = temp->rightChild;
    temp->rightChild = node;

    // control if the root is changed
    if (node == this->root)
        this->root = temp;

    // updating balance factors
    calculateBalanceFactor(temp);

    return temp;
}

avlNode* AVLTree::rightRightRotation(avlNode *node) {
    // this function represents a single rotation to right side
    avlNode* temp = node->rightChild;
    node->rightChild = temp->leftChild;
    temp->leftChild = node;

    // control if the root is changed
    if (node == this->root)
        this->root =  temp;

    // updating balance factors
    calculateBalanceFactor(temp);

    return temp;
}


avlNode* AVLTree::leftRightRotation(avlNode *node) {
    // this function represents a double rotation
    // first the left child is rotating to the right side (in order to make its balance factor positive)
    // then the parent is rotating to the left side

    avlNode* temp = node->leftChild;
    node->leftChild = rightRightRotation(temp);

    avlNode* parent = leftLeftRotation(node);

    return parent;
}

avlNode* AVLTree::rightLeftRotation(avlNode *node) {
    // this function represents a double rotation
    // first the right child is rotating to the left side (in order to make its balance factor negative)
    // then the parent is rotating to the left side

    avlNode* temp = node->rightChild;

    node->rightChild = leftLeftRotation(temp);

    avlNode* last = rightRightRotation(node);

    return last;
}

avlNode* AVLTree::balance(avlNode* node) {
    this->calculateBalanceFactor(node);

    // left side is heavier
    if (node->balanceFactor < -1) {
        if (node->rightChild->balanceFactor > 0) // right size is heavier
            node = rightLeftRotation(node);
        else
            node = rightRightRotation(node);
    }

    // right side is heavier
    else if (node->balanceFactor > 1) {
        if (node->leftChild->balanceFactor > 0)
            node = leftLeftRotation(node);
        else // left size is heavier
            node = leftRightRotation(node);
    }

    return node;
}

avlNode *AVLTree::add(string name, int price, avlNode* node) {
    if (node == NULL)
        node = new avlNode(name, price);

    // add operation is on left side
    else if (node->name > name) {
        node->leftChild = add (name, price, node->leftChild);
        node = balance(node);
    }
    // add operation is on right side
    else if (name > node->name) {
        node->rightChild = add(name, price, node->rightChild);
        node->rightChild = balance(node->rightChild);
    }
    node = balance(node);
    return node;
}

avlNode *AVLTree::remove(avlNode *node, const string& name) {
    if(node==NULL)
        return NULL;

    // finding the node to be removed
    if(name < node->name)
        node->leftChild = remove(node->leftChild, name);
    else if(name > node->name)
        node->rightChild = remove(node->rightChild, name);
    else{ // found
        if (node->rightChild == NULL) {
            if (node->leftChild == NULL) { //both left and right child is null
                delete (node);
                return NULL;
            }
            else { //right child is null but left child is not
                avlNode *left = node->leftChild;
                delete (node);
                node = left;
            }
        }
        else if (node->leftChild==NULL){ //left child is null but right child is not
            avlNode* right = node->rightChild;
            delete (node);
            node = right;
        }
        else { // neither left child nor right child is null
            avlNode* temp = node->rightChild;
            while (temp->leftChild != NULL)
                temp = temp->leftChild; //minimum value on left side
            node->name = temp->name;
            node->price = temp->price;
            node->rightChild = remove (node->rightChild, temp->name);
        }
    }

    if (node==NULL)
        return node;

    this->calculateBalanceFactor(node);

    if(node->balanceFactor > 1) {
        int hLeft = getHeight(node->leftChild);
        int hRight = getHeight(node->rightChild);

        if(hLeft >= hRight)
            return rightRightRotation(node);
        else
            return rightLeftRotation(node);
    }

    else if(node->balanceFactor < -1){
        int hLeft = getHeight(node->leftChild);
        int hRight = getHeight(node->rightChild);

        if(hRight >= hLeft)
            return leftLeftRotation(node);
        else
            return leftRightRotation(node);
    }
    return node;
}

avlNode* AVLTree::search(avlNode *node, string name) {
    if (node == NULL || node->name == name)
        return node;

    if (node->name < name)
        return search(node->rightChild, name);

    return search(node->leftChild, name);
}

void AVLTree::levelOrderTraversal(avlNode* node, int level, fstream& outputFile) {
    if (node == NULL)
        return;
    if (level == 1)
        outputFile<<'"'<<node->name<<'"'<<":"<<'"'<<node->price<<'"'<<",";
    else if (level > 1) {
        levelOrderTraversal(node->leftChild, level - 1, outputFile);
        levelOrderTraversal(node->rightChild, level - 1, outputFile);
    }
}