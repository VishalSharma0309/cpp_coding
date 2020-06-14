#include <bits/stdc++.h>
#include "TreeNode.h"

using namespace std;

int main(){
    
    // create a simple 3 node trees s.t. {1}->{2,3}
    
    // creating the nodes
    TreeNode <int> * root = new TreeNode <int> (1);
    TreeNode <int> * node1 = new TreeNode <int> (2);
    TreeNode <int> * node2 = new TreeNode <int> (2);

    // linking the children with the root
    root->children.push_back(node1);
    root->children.push_back(node2);
    

    return 0;
}