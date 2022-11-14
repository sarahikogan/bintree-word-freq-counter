// TreeNode.h
// Class for creating a treeNode that stores a string and a count

#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "TreeNode.h"

#include <string>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <iomanip>

using std::string;

class BinaryTree {

    public:
        BinaryTree(string a);                      // initializes the tree
        void deleteTree();                         // deletes entire tree
        void addNode(string a);                    // Adds node with word a to the tree
        void inOrder(std::ofstream &file1);        // prints tree to file in order
        string inOrderPrinter(TreeNode *root);    // helper function to count nodes for inOrder
    private:
        TreeNode *root;
};

#endif