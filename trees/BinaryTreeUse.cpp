/* 
Binary Trees:
A special type of tree in which each node has at most 2 children.
i.e. children.size() <= 2 for each node in the tree
*/
#include <bits/stdc++.h>
#include "BinaryTreeNode.h"

using namespace std;

void printTree (BinaryTreeNode <int> * root){
    // base case required in case of binary trees
    if (root == NULL){
        return;
    }
    
    cout << root->data << " : " ;
    if (root->left != NULL){
        cout << " L " << root->left->data ;
    }
    if (root->right != NULL){
        cout << " R " << root->right->data ;
    }
    cout << endl;
    printTree (root->left);
    printTree (root->right);
}

// using a queue
void printTreeLevelWise (BinaryTreeNode <int> * root){
    cout << "Root Data : " << root->data << endl;

    queue <BinaryTreeNode <int> *> pendingNodes;
    pendingNodes.push (root);
    while (pendingNodes.size() != 0){
        BinaryTreeNode <int> * f = pendingNodes.front();
        cout << f->data << " : ";
        pendingNodes.pop();

        if (f->left != NULL){
            cout << " L " << f->left->data << " ";
            pendingNodes.push (f->left); 
        }

        if (f->right != NULL){
            cout << " R " << f->right->data;
            pendingNodes.push (f->right); 
        }

        cout << endl;
    
    
    }
}

BinaryTreeNode <int> * takeInput (){
    // if the user inputs -1 then user do not want a node there
    int rootData;
    cout << "Enter Data: " << endl;
    cin >> rootData;

    if (rootData == -1){
        return NULL;
    }

    BinaryTreeNode <int> * root = new BinaryTreeNode <int> (rootData);
    BinaryTreeNode <int> * leftChild = takeInput ();
    BinaryTreeNode <int> * rightChild = takeInput ();
    root->left = leftChild;
    root->right = rightChild;

    return root;
}

// taking input for a binary tree using a queue
BinaryTreeNode <int> * takeInputLevelWise () {
    int rootData;
    cout << "Enter root data" << endl;
    cin >> rootData;
    // adding this if just as a convention, it has no purpose here
    if (rootData == -1){
        return NULL;
    }

    BinaryTreeNode <int> * root = new BinaryTreeNode <int> (rootData);

    queue <BinaryTreeNode <int> *> pendingNodes;
    pendingNodes.push (root);
    while (pendingNodes.size() != 0) {
        BinaryTreeNode <int> * front = pendingNodes.front();
        pendingNodes.pop();

        cout << "Enter left child of " << front->data << endl;
        int leftChildData;
        cin >> leftChildData;

        if (leftChildData != -1) {
            BinaryTreeNode <int> * child = new BinaryTreeNode <int> (leftChildData);
            front->left = child;
            pendingNodes.push(child);
        }

        cout << "Enter right child of " << front->data << endl;
        int rightChildData;
        cin >> rightChildData;

        if (rightChildData != -1) {
            BinaryTreeNode <int> * child = new BinaryTreeNode <int> (rightChildData);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    
    return root;
}

int countNodes (BinaryTreeNode <int> * root) {
    
    // base case
    if (root == NULL){
        return 0;
    }
    int count = 1;
    count += countNodes (root->left);
    count += countNodes (root->right);

    return count;
    
}

// Binary Tree Traversal
/*  1. Level order (level wise) 
    2. Pre order (first root then its children)
    3. Post order (first the children then the root itself)
    4. In order (new)
*/
// first print my left then myself and then right
void inorderPrint (BinaryTreeNode <int> * root) {
    if (root == NULL){
        return;
    }

    inorderPrint (root->left);
    cout << root->data << " ";
    inorderPrint (root->right);

}

// QUES: Create the binary tree if given its in-order and pre-order in 1-D form.
/*
soln;
pre: [root] [left] [right]
in: [left] [root] [right]
STEP 1: Obtain the root which is pre[0]
STEP 2: break into smaller ques i.e. obtain pre and in of 
    left sub-tree
    
    LeftIn Start: index 0 of in
    LeftIn End: Obtain root from pre[0] and search for it in In. Once found, LeftIn End = rootIndex-1
    LeftPre Start: index 1 of in (just after the root)
    LeftPre End: Basically obtain size of [left] from LeftIn Start - LeftIn End and equate to the size here

    & right sub-tree

    RightIn Start: rootIndex + 1
    RightIn End: in.size()-1
    RightPre Start: LeftPre End + 1
    RightPre End: pre.size()-1
    

*/

BinaryTreeNode <int> * constructBTree (vector <int> in , vector <int> pre){

    if (in.size() == 0){
        return NULL;
    }

    if (in.size() == 1){
        BinaryTreeNode <int> * root = new BinaryTreeNode <int> (pre[0]);
        return root;
    }
    
    
    BinaryTreeNode <int> * root = new BinaryTreeNode <int> (pre[0]);
    int rootIndex;
    for (int i=0 ; i<in.size() ; ++i){
        if (in[i] == pre[0]){
            rootIndex = i;
            break;
        }
    }

    vector <int> :: const_iterator LInS = in.begin() + 0;
    vector <int> :: const_iterator LInE = in.begin() + rootIndex - 1;
    vector <int> :: const_iterator LPreS = pre.begin() +  1;
    vector <int> :: const_iterator LPreE = pre.begin() + 1 + rootIndex;
    /*
    int LInE = in[rootIndex-1];
    int LPreS = pre[1];
    int LPreE = pre[1+rootIndex];  
    */
    vector <int> inL (LInS , LInE);
    vector <int> preL (LPreS, LPreE);
    root->left = constructBTree (inL, preL);

    vector <int> :: const_iterator RInS = in.begin() + rootIndex + 1;
    vector <int> :: const_iterator RInE = in.end();
    vector <int> :: const_iterator RPreS = LPreE + 1;
    vector <int> :: const_iterator RPreE = pre.end();

    vector <int> inR (RInS , RInE);
    vector <int> preR (RPreS, RPreE);
    root->right = constructBTree (inR, preR);

    return root;

    
}


// 1 2 3 4 5 -1 6 -1 -1 -1 -1 -1 -1
int main (){

    // create a simple 3 node tree
    /*BinaryTreeNode <int> * root = new BinaryTreeNode <int> (1);
    BinaryTreeNode <int> * node1 = new BinaryTreeNode <int> (2);
    BinaryTreeNode <int> * node2 = new BinaryTreeNode <int> (3);
    root->left = node1;
    root->right = node2;
    */
    BinaryTreeNode <int> * root = takeInputLevelWise ();
    printTreeLevelWise (root);

    cout << "Total number of nodes = " << countNodes(root) << endl;

    vector <int> in {4,2,5,1,3,6};
    vector <int> pre {1,2,4,5,3,6};

    BinaryTreeNode <int> * f = constructBTree (in , pre);
    printTreeLevelWise (f);

    delete root;
    
    return 0;
}