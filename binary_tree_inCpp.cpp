#include <iostream> // input-output 
#include <string>   // strings
#include <fstream>  // file reading-writing
#include "TreeNode.h"

using std::cout; 
using std::cin; 
using std::endl; 
using namespace std; 


// define the structure for a node 
struct node {
    int data;                   // node will store an integer
    struct node *left;          // right child
    struct node *right;         // left child
};

//  function prototypes
struct node* new_node(int);
struct node* insert(struct node*, int); 
void inOrder(struct node *root);
void delete_tree(struct node *root);

// main function
int main(void) {

    // open data file
    std::ifstream file ("data.txt");
    int hold; 
    int num = 0;

    // get first item from data text
    if (file.is_open()) {
        file >> hold; 
        num = hold;
    }

    // create the first node
    node *rootNode = new_node(num);

    // load rest of items from file and put in tree
    if (file.is_open()) {
        while (file >> hold) {
            insert(rootNode, hold);
        }
    }
    
    file.close(); 

    // print nodes in order
    cout << " ";
    inOrder(rootNode);
    cout << "\n";

    // delete tree: not needed for now
    delete_tree(rootNode); 
    
}

// ************ FUNCTIONS ************
 
 /* ---
 * struct node* new_node(int x)
 * Creates a new node
 * 
 * Input:
 *   int x: value to be added to the tree
 * Returns: pointer to the new node
 * --- */

struct node* new_node(int x) {

    node* root = new node();           // create pointer to a node
    root -> data = x;                  // add data value to the node
    return root; 
}

/* ---
 * struct node* insert(struct node *root, int x)
 * Adds a new node in the tree, keeping the
 * tree ordered
 * 
 * Input:
 *  root: pointer to top of tree or subtree
 *  int x: value to be added to the tree
 * Returns: the pointer to top of tree or subtree
 * --- */
struct node* insert(struct node *root, int x) {

    if (root == NULL) {                          // there's no root = no tree yet
        return new_node(x);                      // create new node 
    } else if (x > root->data) {                 // insertion is greater than what the root contains
        root -> right = insert(root->right, x);  // set right side of the root to the data from x 
    } else if (x < root -> data) {               // insertion is less than the root data
        root -> left = insert(root -> left, x);  // insert data to the left of the root
    }

    return root; 
}

/* ---
 * void inOrder(struct node *root)
 * Prints all nodes of the tree in order
 * 
 * Input:
 *  root: pointer to top of tree or subtree
 * Output: Prints values to terminal in a single line
 * --- */
void inOrder(struct node *root) {
    if (root != NULL) {                 // check for no root
        inOrder(root -> left);          // visiting left child
        cout << root -> data << "  ";    // print data at the root 
        inOrder(root -> right);         // visit right child 
    }
}

/* ---
 * void delete_tree(struct node *root)
 * Deletes all nodes of a tree or subtree
 * 
 * Input:
 *  root: pointer to top of tree or subtree
 * --- */
void delete_tree(struct node *root) {
    if(root != NULL) {                  // check that root exists
        delete_tree(root -> left);      
        delete_tree(root -> right);

        printf("Freeing node %d \n", root -> data);
        delete(root);
    }
}
