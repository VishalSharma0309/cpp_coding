#include <bits/stdc++.h>
#include "TreeNode.h"

using namespace std;

//  take input level-wise using queue
// maintain a queue with TreeNodes
// each element from the front is taken and its children are then added to the queue 
TreeNode <int> * takeInputLevelWise(){
    int rootData;
    cout << "Enter root data" << endl;
    cin >> rootData;
    TreeNode <int> * root = new TreeNode <int> (rootData);

    queue <TreeNode <int> *> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0){
        TreeNode <int> * front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter Number of Children of " << front->data << endl;
        int numChild;
        cin >> numChild;

        for (int i=0 ; i<numChild ; ++i){
            int childData;
            cout << "Enter " << i << "th child of " << front->data << endl;
            cin >> childData;
            TreeNode <int> * child = new TreeNode <int> (childData);
            front -> children. push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

// take input recursively
TreeNode <int> * takeinput(){
    int rootData;
    cout << "Enter data" << endl;
    cin >> rootData;

    TreeNode <int> * root = new TreeNode <int> (rootData);

    int n=0;
    cout << "Enter Number of Children for " << root->data << endl;
    cin >> n;

    for (int i=0 ; i<n ; ++i){
        TreeNode<int> * child = takeinput();
        root->children.push_back(child);
    }

    return root;
}



void printTree (TreeNode<int> * root){

    // edge case: if the root is NULL
    if (root == NULL){
        return;
    }

    cout << root->data << " : " ;

    for (int j=0 ; j<root->children.size() ; ++j){
        cout << root->children[j]->data << " , ";
    }
    cout << endl;
    for (int i=0 ; i<root->children.size() ; ++i){
        printTree(root->children[i]);
    }

}


int countNodes (TreeNode <int> * root){
    
    // edge case
    if (root == NULL){
        return 0;
    }
    
    int Size = 1;
    
    for (int i=0 ; i<root->children.size() ; ++i){
        Size += countNodes(root->children[i]);     
    }
    return Size;
}

// height = number of levels

int height (TreeNode <int> * root){
    if (root == NULL){
        return 0;
    }
    int max = 1;
    for (int i=0 ; i<root->children.size() ; ++i){
        int temp = 1;
        temp += height(root->children[i]);
        if (temp>max){
            max = temp;
        } 
    }
    return max;
}


// print all nodes at depth (used interchangeably with level) k
// depth/level starts at zero
void printNodesAtk (TreeNode <int> * root, int k){

    // base case
    if (k==0){
        cout << root->data << endl;
        return;
    }

    // recursive loop
    for (int i=0 ; i<root->children.size() ; ++i){
        printNodesAtk (root->children[i] , k-1);
    }

}

// return the number of leafs in a tree
// a leaf is a node which does not have any children
int countLeaf (TreeNode <int> * root){
    // edge case
    if (root == NULL){
        return 0;
    }
        
    // base case    
    int count = 0;
    if (root->children.size() == 0){
        return 1;
    }

    // recursive loop
    for (int i=0 ; i<root->children.size() ; ++i){
        count += countLeaf (root->children[i]); 
    }

    return count;
}


// Tree traversal methods
/*  1. Pre-Order Traversal
        - the root gets printed first and then its children
        - the usual recursive traversal (refer printTree)
    2. Post-Order Traversal
        - root says first print my children and then myself
        
*/

void postOrderTraversal (TreeNode <int> * root){
    if (root == NULL){
        return;
    }
    
    if (root->children.size() == 0){
        cout << root->data << endl;
    }

    for (int i=0 ; i<root->children.size() ; ++i){
        postOrderTraversal (root->children[i]);
        if (i == root->children.size() - 1){
            cout << root->data << endl;
        }
    }
}



// input tree: 1 3 2 3 4 2 5 6 1 7 1 8 2 9 10 0 0 0 0 0
int main(){
    
    // create a simple 3 node trees s.t. {1}->{2,3}
    
    // creating the nodes
   
    /*TreeNode <int> * root = new TreeNode <int> (1);
    TreeNode <int> * node1 = new TreeNode <int> (2);
    TreeNode <int> * node2 = new TreeNode <int> (3);
    */

    // linking the children with the root
    //root->children.push_back(node1);
    //root->children.push_back(node2);

    // taking input using takeinput
    TreeNode <int> * root = takeInputLevelWise();
    
    printTree (root);
    postOrderTraversal (root);

    cout << "Total number of nodes : " << countNodes(root) << endl;
    cout << "Height of the tree : " << height(root) << endl;


    cout << "Nodes at depth 2: " << endl;
    printNodesAtk (root , 2);

    cout << "No. of leaves = " << countLeaf (root) << endl;
    // TODO deleting the tree

    return 0;
}