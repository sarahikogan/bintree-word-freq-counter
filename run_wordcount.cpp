#include "TreeNode.h"
#include "BinaryTree.h"

#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <sstream>

using std::string;
using std::ofstream;
using std::fstream;
using std::cout;
using std::endl;

int main(int argc, char *argv[]) {

    fstream inputFile;                      // input file
    ofstream outputFile;                    // output file
    string word;                            // word to check if there is a word there
    string firstword;                       // get first word
    string firstline;                       // get first line
    // get the first line of the file
    // for loop along the length of the line 
    // if character is ' ' break
    // firstword += line[i]

    inputFile.open(argv[2]);                // open the file
    std::getline(inputFile, firstline);          // get the first line
    for (int i=0; i<firstline.length(); i++) {   // go down the length of the line
        if (firstline[i] == ' ') {                // break once it reaches a space
            break;                  
        } else {                            
            firstword += firstline[i];
        }
    }
    inputFile.close();

    cout << firstword << endl;
    // initialize binary tree with the first word of the first file
    BinaryTree tree1(firstword);          
    
    for (int i=0; i<argc-2; i++) {

        inputFile.open(argv[i+2]);          // open each input file

        while (inputFile >> word) {         // get each word in the file
            tree1.addNode(word);                  // add node to binary tree
        }

        inputFile.close();

    }

    ofstream out;
    out.open("output.txt");
    tree1.inOrder(out);
    tree1.deleteTree();

}

/*

PSEUDOCODE 

go into each file 

    read in each word, separated by spaces, and add it to the binary tree


*/

