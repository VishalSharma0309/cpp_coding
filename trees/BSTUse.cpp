#include <bits/stdc++.h>
#include "BinaryTreeNode.h"

using namespace std;

/* 
Binary Search Tree
- A type of Binary Tree inspired from Binary Search (O(logn))
- suppose you're searching for 's'. We start the search from root 'r'
    - if r==s -> found
    - else if r>s -> seach in right sub-tree
    - else search in left sub-tree

- Properties of BST:
    1. For every node 'n': 
        everyting left to n is smaller than n->data
        everything right to n is greater than n->data
*/

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

// Search in BST
BinaryTreeNode <int> * searchBST (BinaryTreeNode <int> * root, int val){
    // base case
    if (root == NULL){
        return root;
    }
    // case 1
    if (root->data == val){
        return root;
    }
    // case 2
    if (val < root->data){
        return searchBST (root->left , val);
    }
    // case 3
    return searchBST (root->right , val);
}


// 4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1 
int main (){
    BinaryTreeNode <int> * root = takeInputLevelWise ();
    printTreeLevelWise (root);

    cout << searchBST (root , 2)->data << endl;
    return 0;
}