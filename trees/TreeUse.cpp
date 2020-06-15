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
    // TODO deleting the tree

    return 0;
}