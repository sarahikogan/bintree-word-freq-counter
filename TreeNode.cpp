// Sarah Kogan
// TreeNode.cpp
// Contains the node that represents individual words in the input text as nodes of a tree

// TODO: node removed not working

#include <iostream> // input-output 
#include <string>   // strings
#include <fstream>  // file reading-writing

#include "TreeNode.h"

using std::cout; 
using std::cin; 
using std::endl; 
using std::string;
using namespace std; 


// ----- CONSTRUCTORS ------

/* *************************
 * TreeNode(string a);
 * 
 * Input: String a 
 * Output: creates a TreeNode
 * ************************/
TreeNode::TreeNode(string a) {
    transform(a.begin(), a.end(), a.begin(), ::tolower); // make a lowercase to be stored in word
    word = a;
    count = 1;
    leftP = NULL;
    rightP = NULL;
}

/* *************************
 * TreeNode();
 * 
 * Output: Creates a TreeNode
 * ************************/
TreeNode::TreeNode() {
    count = 0;
    word = ""; 
    leftP = NULL;
    rightP = NULL;
}

/**** FUNCTIONS *****/

/* *************************
 * remove_Node();
 * 
 * Output: Destroys a TreeNode
 * ************************/
void TreeNode::remove_Node() {

    if (leftP != NULL) {
        leftP->remove_Node();
    }

    if (rightP != NULL) {
        rightP->remove_Node();
    }

    count = 0; 
    word = ""; 
}

/* *************************
 * void increase_count();
 * 
 * Output: increases the count of a node by 1
 * ************************/
void TreeNode::increase_count() {
    this -> count++;
}

/* *************************
 * int get_count();
 * 
 * Output: returns the count of a node
 * ************************/
int TreeNode::get_count() {
    return this -> count;
}

/* *************************
 * string get_word();
 * 
 * Output: returns the string from a node
 * ************************/
string TreeNode::get_word() {
    return this -> word;
}

/* *************************
 * void add_left(TreeNode * subTree);
 * 
 * Output: add subTree to left
 * ************************/
void TreeNode::add_left(TreeNode *subTree) {
    this -> leftP = subTree;
}

/* *************************
 * void add_right(TreeNode * subTree);
 * 
 * Output: add subTree to right
 * ************************/
void TreeNode::add_right(TreeNode *subTree) {
    this -> rightP = subTree;
}

/* *************************
 * TreeNode *get_left();
 * 
 * Output: return left subtree
 * ************************/
TreeNode* TreeNode::get_left() {
    return leftP;
}

/* *************************
 * TreeNode *get_right();
 * 
 * Output: return right subtree
 * ************************/
TreeNode* TreeNode::get_right() {
    return rightP;
}

/* *************************
 * void inOrder(std::ofstream &file1);
 * 
 * Output: return file1 in order
 * ************************/
void TreeNode::inOrder(std::ofstream &file1) {
    inOrder(file1);
}
