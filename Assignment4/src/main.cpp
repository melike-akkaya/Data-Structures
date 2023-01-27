#include <iostream>
#include <vector>
#include "Utility.h"
#include "AVLTree.h"
#include "RedBlackTree.h"
#include "BinarySearchTree.h"

void firstModel(vector<vector<string>> inputList, string fileName) {
    fstream outputFile;
    outputFile.open(fileName, ios::out);

    BinarySearchTree* bst = new BinarySearchTree;

    for (vector<string> line : inputList) {
        if (line.at(0) == "insert") {
            string category = line.at(1);
            string name = line.at(2);
            int price = Utility::stringToInteger(line.at(3));

            Node* temp = bst->search(bst->root, category);

            if (temp == NULL) {

                bst->root = bst->add(category, bst->root);

                Node* newCategory = bst->search(bst->root, category);

                avlNode* rootOfCategory = new avlNode(name, price);

                newCategory->secondaryAVL = new AVLTree(rootOfCategory, category);
            }
            else
                temp->secondaryAVL->root = temp->secondaryAVL->add(name, price, temp->secondaryAVL->root);
        }
        else if (line.at(0) == "printAllItems") {
            outputFile<<"command:printAllItems"<<endl<<"{"<<endl;
            BinarySearchTree::levelOrderTraversalAVL(bst->root, outputFile);
            outputFile<<"}"<<endl;
        }
        else if (line.at(0) == "printAllItemsInCategory") {
            Node* temp = bst->search(bst->root, line.at(1));
            outputFile << "command:printAllItemsInCategory\t" << line.at(1)<<endl<<"{"<<endl<<'"'<<line.at(1)<<'"'<<":";
            if (temp != NULL) {
                if (temp->secondaryAVL->root != NULL) {
                    int maxH = temp->secondaryAVL->getHeight(temp->secondaryAVL->root);
                    for (int i = 0; i <= maxH; i++) {
                        outputFile<<"\t";
                        AVLTree::levelOrderTraversal(temp->secondaryAVL->root, i, outputFile);
                        outputFile<<endl;
                    }
                    outputFile<<"}"<<endl;
                }
                else {
                    outputFile<< " {}\n}\n";
                }
            }
        }
        else if (line.at(0) == "printItem") {
            Node* temp = bst->search(bst->root, line.at(1));
            outputFile<< "command:printItem\t"<<line.at(1)<<"\t"<<line.at(2)<<endl;
            if (temp != NULL) {
                avlNode* tempAVL = temp->secondaryAVL->search(temp->secondaryAVL->root, line.at(2));
                if (tempAVL == NULL)
                    outputFile << "{}"<<endl;
                else
                    outputFile<<"{\n"<<'"'<<line.at(1)<<'"'<<":\n\t"<<'"'<<line.at(2)<<'"'<<":"<<'"'<<tempAVL->price<<'"'<<endl<<"}\n";
            }
        }
        else if (line.at(0) == "updateData") {
            Node* temp = bst->search(bst->root, line.at(1));
            if (temp == NULL)
                outputFile<<"command:updateData\t"<<line.at(1)<<"\t"<<line.at(2)<<"\nNo such category exist!";
            else {
                avlNode* tempAVL = temp->secondaryAVL->search(temp->secondaryAVL->root, line.at(2));
                if (tempAVL == NULL)
                    outputFile<<"command:updateData\t"<<line.at(1)<<"\t"<<line.at(2)<<"\nNo such item exist!\n";
                else {
                    int newPrice = Utility::stringToInteger(line.at(3));
                    tempAVL->price = newPrice;
                }
            }
        }
        else if (line.at(0) == "find") {
            Node* temp = bst->search(bst->root, line.at(1));
            outputFile<< "command:find\t"<<line.at(1)<<"\t"<<line.at(2)<<endl;
            if (temp != NULL) {
                avlNode* tempAVL = temp->secondaryAVL->search(temp->secondaryAVL->root, line.at(2));
                if (tempAVL == NULL)
                    outputFile << "{}"<<endl;
                else {
                    outputFile<<"{\n"<<'"'<<line.at(1)<<'"'<<":\n\t"<<'"'<<line.at(2)<<'"'<<":"<<'"'<<tempAVL->price<<'"'<<endl<<"}\n";
                }
            }
            else {
                outputFile << "{}" <<endl;
            };
        }
        if (line.at(0) =="remove") {
            Node* temp = bst->search(bst->root, line.at(1));
            if (temp != NULL) {
                if (temp->secondaryAVL != NULL) {
                    temp->secondaryAVL->root = temp->secondaryAVL->remove(temp->secondaryAVL->root, line.at(2));
                }
            }

        }
    }
    outputFile.close();
}

void secondModel(vector<vector<string>> inputList, string fileName) {
    fstream outputFile;
    outputFile.open(fileName, ios::out);

    BinarySearchTree* bst = new BinarySearchTree;

    for (vector<string> line : inputList) {
        if (line.at(0) == "insert") {
            string category = line.at(1);
            string name = line.at(2);
            int price = Utility::stringToInteger(line.at(3));

            Node* temp = bst->search(bst->root, category);

            if (temp == NULL) {

                bst->root = bst->add(category, bst->root);

                Node* newCategory = bst->search(bst->root, category);

                rbNode* rootOfCategory = new rbNode(name, price);

                newCategory->secondaryRB = new RedBlackTree(rootOfCategory,category);
            }
            else
                temp->secondaryRB->root = temp->secondaryRB->add(temp->secondaryRB->root, name, price);
        }
        else if (line.at(0) == "printAllItems") {
            outputFile<<"command:printAllItems"<<endl<<"{"<<endl;
            BinarySearchTree::levelOrderTraversalRB(bst->root, outputFile);
            outputFile<<"}"<<endl;
        }
        else if (line.at(0) == "printAllItemsInCategory") {
            Node* temp = bst->search(bst->root, line.at(1));
            outputFile << "command:printAllItemsInCategory\t" << line.at(1)<<endl<<"{"<<endl<<'"'<<line.at(1)<<'"'<<":";
            if (temp != NULL) {
                if (temp->secondaryRB->root != NULL) {
                    int maxH = temp->secondaryRB->getHeight(temp->secondaryRB->root);
                    for (int i = 0; i <= maxH; i++) {
                        outputFile<<"\t";
                        RedBlackTree::levelOrderTraversal(temp->secondaryRB->root, i, outputFile);
                        outputFile<<endl;
                    }
                    outputFile<<"}"<<endl;
                }
                else {
                    outputFile<< " {}\n}\n";
                }
            }
            else {
                outputFile<<"{}";
            }
        }
        else if (line.at(0) == "printItem") {
            Node* temp = bst->search(bst->root, line.at(1));
            if (temp == NULL)
                outputFile << "No such category exist!";
            else {
                outputFile<< "command:printItem\t"<<line.at(1)<<"\t"<<line.at(2)<<endl;
                rbNode* tempRB = temp->secondaryRB->search(temp->secondaryRB->root, line.at(2));
                if (tempRB == NULL)
                    outputFile << "{}"<<endl;
                else {
                    outputFile<<"{\n"<<'"'<<line.at(1)<<'"'<<":\n\t"<<'"'<<line.at(2)<<'"'<<":"<<'"'<<tempRB->price<<'"'<<endl<<"}\n";
                }
            }
        }
        else if (line.at(0) == "updateData") {
            Node* temp = bst->search(bst->root, line.at(1));
            if (temp != NULL) {
                rbNode* tempRB = temp->secondaryRB->search(temp->secondaryRB->root, line.at(2));
                if (tempRB != NULL) {
                    int newPrice = Utility::stringToInteger(line.at(3));
                    tempRB->price = newPrice;
                }
            }
        }
        else if (line.at(0) == "find") {
            Node* temp = bst->search(bst->root, line.at(1));
            outputFile<< "command:find\t"<<line.at(1)<<"\t"<<line.at(2)<<endl;
            if (temp != NULL) {
                rbNode* tempRB = temp->secondaryRB->search(temp->secondaryRB->root, line.at(2));
                if (tempRB == NULL)
                    outputFile << "{}"<<endl;
                else {
                    outputFile<<"{\n"<<'"'<<line.at(1)<<'"'<<":\n\t"<<'"'<<line.at(2)<<'"'<<":"<<'"'<<tempRB->price<<'"'<<endl<<"}\n";
                }
            }
            else {
                outputFile << "{}" <<endl;
            };
        }
        if (line.at(0) =="remove") {
            Node* temp = bst->search(bst->root, line.at(1));
            if (temp != NULL) {
                if (temp->secondaryRB->root != NULL)
                    temp->secondaryRB->root = temp->secondaryRB->remove(temp->secondaryRB->root, line.at(2));
            }

        }
    }
    outputFile.close();
}



int main(int args, char** argv) {
    vector<vector<string>> inputList = Utility::readFile(argv[1]);
    firstModel(inputList, argv[2]);
    secondModel(inputList, argv[3]);
}
