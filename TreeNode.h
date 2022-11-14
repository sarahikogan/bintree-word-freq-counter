// TreeNode.h
// Class for creating a treeNode that stores a string and a count

#ifndef TREENODE_H
#define TREENODE_H

#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <algorithm>

using std::string;

class TreeNode{

    public:
        TreeNode(string a);                     // Constructor
        TreeNode();
        void remove_Node();                     // Deconstructor
        void increase_count();                  // increase count by 1
        int get_count();                        // return the count
        string get_word();                      // Return word                
        void add_left(TreeNode * subTree);      // add subTree to left
        void add_right(TreeNode * subTree);     // add subTree to right
        TreeNode * get_left();
        TreeNode * get_right();
        void inOrder(std::ofstream &file1);

    private:
        int count;
        string word;
        TreeNode * leftP;
        TreeNode * rightP;
};

#endif