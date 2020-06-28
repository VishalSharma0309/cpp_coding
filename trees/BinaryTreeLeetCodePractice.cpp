#include <bits/stdc++.h>
#include "BinaryTreeNode.h"

using namespace std;


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






/*
563. Binary Tree Tilt
The tilt of a tree node is defined as the absolute difference between the 
sum of all left subtree node values and the sum of all right subtree node values. 
Null node has tilt 0.
*/

// approach 1: iterative

int findSum (BinaryTreeNode <int> * root){
    if (root==NULL){
        return 0;
    }

    int sum = root->data;
    return sum + findSum (root->left) + findSum (root->right);
}


int findTilt (BinaryTreeNode <int> * root){
    if (root==NULL){
        return 0;
    }
    
    queue <BinaryTreeNode <int> *> pendingNodes;
    int tilt=0;
    pendingNodes.push(root);
    while (pendingNodes.size()!=0){
        BinaryTreeNode <int> * f = pendingNodes.front();
        pendingNodes.pop();
        tilt += abs (findSum (f->left) - findSum (f->right));
        if (f->left != NULL){
            pendingNodes.push(f->left);
        }
        if (f->right != NULL){
            pendingNodes.push (f->right);
        }
    }

    return tilt;
}

// approach 2: recursive
int findTiltRec (BinaryTreeNode <int> * root){
    if (root==NULL){
        return 0;
    }
    int left = findSum (root->left);
    int right = findSum (root->right);
    int tilt = abs (left-right);
    return tilt + findTiltRec (root->left) + findTiltRec (root->right);
}


/*
226. Invert Binary Tree

approach: recursive
swap the address of each corresponding nodes 

*/

void NodeSwap (BinaryTreeNode <int> * & p , BinaryTreeNode <int> * & q){
                   
    BinaryTreeNode <int> * temp = p;
    p = q;
    q = temp;    
}
    
BinaryTreeNode <int> * invertTree(BinaryTreeNode <int> * root) {
    if (root==NULL){
        return NULL;
    }
        
    NodeSwap (root->left , root->right);
    invertTree (root->left);
    invertTree (root->right);
    return root;    
}



int main(){

    BinaryTreeNode <int> * root = takeInputLevelWise ();
    printTreeLevelWise (root);

    cout << findTiltRec (root);
    return 0;
}