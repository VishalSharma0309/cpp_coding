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
    delete root;
    
    return 0;
}