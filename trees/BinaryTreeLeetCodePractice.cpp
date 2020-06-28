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

/*
110. Balanced Binary Tree
a binary tree in which the left and right subtrees of every node differ in height by no more than 1.
*/

int height (BinaryTreeNode <int> * root){
    if (root == NULL){
        return 0;
    }
    return 1 + max (height (root->left) , height (root->right)); 
}

bool balancedTree (BinaryTreeNode <int> * root){
    if (root==NULL){
        return true;
    }
    cout << abs (height(root->left) - height (root->right)) << endl;
    if (abs (height(root->left) - height (root->right)) > 1){
        cout << abs (height(root->left) - height (root->left)) << endl;
        return false;
    }
    return (balancedTree (root->left) && balancedTree (root->right));
}

/*
572. Subtree of Another Tree

*/

bool isSame (BinaryTreeNode <int> * p , BinaryTreeNode <int> * q){
    if (p==NULL || q==NULL){
        if (p==NULL && q==NULL)
            return true;
        return false;
    }

    if (p->data != q->data){
        return false;
    }

    return (isSame (p->left , q->left) && isSame (p->right , q->right));
     
}

bool isSubtree (BinaryTreeNode <int> * p , BinaryTreeNode <int> * q){
    if (isSame (p,q)){
        return true;
    }
    bool ans = false;
    if (p!=NULL){
        ans = (isSubtree (p->left , q) || isSubtree (p->right , q));
    }
    return ans;
}


/*
872. Leaf-Similar Trees
Two binary trees are considered leaf-similar if their leaf value sequence is the same.
*/

vector <int> ansLeaf;
vector <int> leafNodes (BinaryTreeNode <int> * root){
    if (root!=NULL){    
        if (root->left == NULL && root->right == NULL){
            ansLeaf.push_back(root->data);
        }
        leafNodes (root->left);
        leafNodes (root->right);
    }
    return ansLeaf;
}

bool leafSimilar (BinaryTreeNode <int> * root1 , BinaryTreeNode <int> * root2){
    vector <int> leaf1 = leafNodes (root1);
    ansLeaf.clear();
    vector <int> leaf2 = leafNodes (root2);
    ansLeaf.clear();
    for (int i=0 ; i<leaf1.size() ; ++i){
        cout << leaf1[i] << " ";
    }
    cout << endl;
    for (int i=0 ; i<leaf2.size() ; ++i){
        cout << leaf2[i] << " ";
    }
    cout << endl;
    return (leaf1 == leaf2);
}

/*
111. Minimum Depth of Binary Tree
The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
*/

int minDepth (BinaryTreeNode <int> * root){
    
}

// 1 2 2 3 3 -1 -1 4 4 -1 -1 -1 -1 -1 -1

/*
3 5 1 6 2 9 8 -1 -1 7 4 -1 -1 -1 -1 -1 -1 -1 -1
3 5 1 6 7 4 2 -1 -1 -1 -1 -1 -1 9 8 -1 -1 -1 -1
*/

int main(){

    BinaryTreeNode <int> * root1 = takeInputLevelWise ();
    printTreeLevelWise (root1);

    
    BinaryTreeNode <int> * root2 = takeInputLevelWise ();
    printTreeLevelWise (root2);

    //cout << findTiltRec (root);
    //cout << height (root) << endl;
    //cout << balancedTree (root) << endl; 
    
    cout << leafSimilar (root1 , root2) << endl;

    return 0;
}