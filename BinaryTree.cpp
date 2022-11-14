// Sarah Kogan
// BinaryTree.cpp
// Constructs, inserts, searches, destroys, and travels the binary tree

#include <iostream> // input-output 
#include <string>   // strings
#include <fstream>  // file reading-writing
#include <string>  
#include <iostream> 
#include <sstream>

#include "TreeNode.h"
#include "BinaryTree.h"

using std::cout; 
using std::cin; 
using std::endl; 
using std::string;
std::stringstream buffer;
using namespace std; 

/* *************************
 * BinaryTree(string a);
 * 
 * Output: initializes the binary tree
 * ************************/
BinaryTree::BinaryTree(string a) {
    root = new TreeNode(a);

} 

/* *************************
 * void deleteTree();
 * 
 * Output: deletes entire tree
 * ************************/
void BinaryTree::deleteTree() {

    // cout << "\nBeginning process of deleting tree... ";

    // if root is deleted, end 
    if (root == NULL) return; 

    root -> remove_Node();

    // delete left and right subtrees
    // (root->get_left())->remove_Node();
    // (root->get_right())->remove_Node();

    // delete node 
   //  cout << "\n Deleting node: " << root->get_word();
    delete root;
}

/* *************************
 * void addNode(string a);
 * 
 * Output: adds node with word a to the tree
 * ************************/
void BinaryTree::addNode(string a) {
    
    // make a lowercase
    transform(a.begin(), a.end(), a.begin(), ::tolower);

    // declare a TreeNode pointer to root
    TreeNode *currentNode = root; 

    // create a flag to tell when we have added a node: 
    int nodeAdded = 0;

    while (nodeAdded == 0) {

        if (a < currentNode->get_word()) {                       // less: left
            if (currentNode->get_left() != NULL) {               // if left node exists visit it
                currentNode = currentNode->get_left();           // switch to left side
            } else {                                             // otherwise add it there
                currentNode -> add_left(new TreeNode(a));
                nodeAdded = 1;                                   // leave the while loop because node was added
            
            }
        } else if (a > currentNode->get_word()) {                // more: right
            if (currentNode->get_right() != NULL) {
                currentNode = currentNode->get_right();          // if right node exists visit it 
            } else {                                             // otherwise add it there
                currentNode -> add_right(new TreeNode(a));
                nodeAdded = 1;                                   // leave the while loop because node was added
            }
        } else if (a == currentNode->get_word()) {               // word is the same
            currentNode->increase_count();                       // increase the count
            nodeAdded = 1;                                       // leave while loop
        }
    }
}

/* *************************
 * void inOrder(std::ofstream &file1);
 * 
 * Output: prints tree to the file1, in order
 * ************************/
void BinaryTree::inOrder(std::ofstream &file1) {

    // start with the current TreeNode
    TreeNode *currentNode = root;

    file1 << inOrderPrinter(currentNode);
};

/* *************************
 * void inOrderPrinter(TreeNode t);
 * 
 * Output: returns a binary tree in the proper format, which is then
 * used by the inOrder function to print into the necessary file. Having
 * a second function that takes in a TreeNode allows for it to be recursive 
 * ************************/
string BinaryTree::inOrderPrinter(TreeNode *root) {

    string output;

    if (root != NULL) {
        // access the left tree through a pointer
        TreeNode *leftTree = root->get_left();
        inOrderPrinter(leftTree);

        // print out the count and word, with tabs and spaces for proper formatting
        buffer << setw(6) << root->get_count() << "  " << root->get_word() << std::endl;

        // access the right tree throught a pointer
        TreeNode *rightTree = root -> get_right();
        inOrderPrinter(rightTree);
    } 

    return buffer.str();
}