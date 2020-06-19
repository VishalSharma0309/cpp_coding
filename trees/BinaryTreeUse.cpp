/* 
Binary Trees:
A special type of tree in which each node has at most 2 children.
i.e. children.size() <= 2 for each node in the tree
*/
#include <bits/stdc++.h>
#include "BinaryTreeNode.h"

using namespace std;

int main (){

    // create a simple 3 node tree
    BinaryTreeNode <int> * root = new BinaryTreeNode <int> (1);
    BinaryTreeNode <int> * node1 = new BinaryTreeNode <int> (2);
    BinaryTreeNode <int> * node2 = new BinaryTreeNode <int> (3);
    root->left = node1;
    root->right = node2;
    
    return 0;
}