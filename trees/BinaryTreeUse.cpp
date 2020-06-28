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

vector <int> ansinorder;
vector <int> inorder (BinaryTreeNode <int> * root){
    //ansinorder.clear();
    if (root == NULL){
        ansinorder.push_back(-1);
        return ansinorder;
    }
    inorder (root->left);
    ansinorder.push_back(root->data);
    inorder (root->right);

    return ansinorder;
}


vector <int> anspreorder;
vector <int> preorder (BinaryTreeNode <int> * root){
    //anspreorder.clear();
    if (root == NULL){
        anspreorder.push_back(-1);
        return anspreorder;
    }
    anspreorder.push_back (root->data);
    preorder (root->left);
    preorder (root->right);

    return anspreorder;

}

// QUES: Create the binary tree if given its in-order and pre-order in 1-D form.
// NO DUPLICATES ALLOWED IN THE TREE
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
BinaryTreeNode <int> * buildTreeHelper (int * in, int * pre, int inS, int inE, int preS, int preE){
    // base case (size=0) i.e inS > inE
    if (inS > inE){
        return NULL;
    }
    
    // find rootData
    int rootData = pre[preS];
    
    
    // find rootIndex
    int rootIndex = -1;
    for (int i=inS ; i<=inE ; ++i){
        if (in[i]==rootData){
            rootIndex = i;
            break;
        }
    }

    int lInS = inS;
    int lInE = rootIndex - 1;
    int lPreS = preS + 1;
    int lPreE = lInE - lInS + lPreS;;
    int rInS = rootIndex + 1; 
    int rInE = inE;    
    int rPreS = lPreE + 1; 
    int rPreE = preE; 
    

       
    // find the above 8 values to use recursion effectively


    BinaryTreeNode <int> * root = new BinaryTreeNode <int> (rootData);
    root->left = buildTreeHelper (in, pre, lInS, lInE, lPreS, lPreE);
    root->right = buildTreeHelper (in, pre, rInS, rInE, rPreS, rPreE);
    return root;
}

BinaryTreeNode <int> * constructBTree (int * in , int * pre, int size){

    return (buildTreeHelper(in, pre, 0, size-1, 0, size-1));    
}



/*
Leetcode QUES:
Given the root node of a binary search tree (BST) and a value. 
You need to find the node in the BST that the node's value equals the given value. 
Return the subtree rooted with that node. 
If such node doesn't exist, you should return NULL.
*/

BinaryTreeNode <int> * searchBST (BinaryTreeNode <int> * root , int value){
    queue <BinaryTreeNode <int> *> pendingNodes;
    
    if (root == NULL){
        return NULL;
    }

    pendingNodes.push(root);
    int found = -1;
    while (pendingNodes.size()!=0){
        BinaryTreeNode <int> * f = pendingNodes.front();
        pendingNodes.pop();
        if (f->data == value){
            found = 1;
            return f;
        }
        if (f->left != NULL)
            pendingNodes.push(f->left);
        if (f->right != NULL)
        pendingNodes.push(f->right);
    }

    if (found == -1){
        return NULL;
    }
}


/*

LeetCode: 965. Univalued Binary Tree
A binary tree is univalued if every node in the tree has the same value.

Return true if and only if the given tree is univalued.

*/

bool isUnivalTree(BinaryTreeNode <int> * root) {
    
    if (root == NULL){
        return false;
    }
    queue <BinaryTreeNode <int> *> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0){
        BinaryTreeNode <int> * f = pendingNodes.front();
        pendingNodes.pop();

        if (f->left != NULL) {
            if (f->data != f->left->data){
                return false;
            }
            else {
                pendingNodes.push(f->left);
            }
        }

        if (f->right != NULL) {
            if (f->data != f->right->data){
                return false;
            }
            else {
                pendingNodes.push(f->right);
            }
        }
    }

    return true;
}


/*
LeetCode: 101. Symmetric Tree
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
*/

// approach: in-order traversal = [left] [root] [right]
// if left and right are exact mirror images of each other then the tree is symmetric


// NOTE: approach not working when nodes have same data
bool isSymmetric (BinaryTreeNode <int> * root){
    
    if (root == NULL){
        return false;
    }
    
    vector <int> in = inorder (root);
    ansinorder.clear();
    // if size = 1
    if (in.size() == 1){
        return true;
    }

    // size should be odd
    if (in.size()%2 == 0){
        cout << "Size even" << endl;
        return false;
    }

    int rootIndex;

    for (int i=0 ; i<in.size() ; ++i){
        if (in[i] == root->data){
            rootIndex = i;
            break;
        }
    }
    
    // checking if rootIndex is the middle of in
    if (rootIndex != (in.size()-1)/2){
        cout << "Root Index Inmatch" << endl;
        return false;
    }
    
    for (int i=0 ; i<(in.size()-1)/2 ; ++i){
        if (in[rootIndex - i] != in[rootIndex + i]){
            return false;
        }
    }

    return true;
    

}


// approach 2: recursive method
// check if left side of a tree is same as right of another and vice versa
// WORKS GREAT!! USE THIS!

bool isMirror (BinaryTreeNode <int> * p , BinaryTreeNode <int> * q){
    if (p==NULL && q==NULL){
        return true;
    }

    if (p && q && p->data == q->data){
        return (isMirror (p->left , q->right) && isMirror (p->right , q->left));
    }

    return false;
}

bool isSymmetricRec (BinaryTreeNode <int> * root){
    if (root == NULL){
        return true;
    }
    
    return (isMirror (root->left , root->right));
}


/*
100. Same Tree
Given two binary trees, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical and the nodes have the same value.

*/

// Approach 1: two trees with same in-order and pre-order are the same

bool sameTree (BinaryTreeNode <int> * p , BinaryTreeNode <int> * q){

    // in order
    vector <int> inp = inorder (p);
    ansinorder.clear();
    vector <int> inq = inorder (q);
    ansinorder.clear();
    for (int i=0 ; i<inp.size() ; ++i){
        cout << inp[i] << " ";
    }
    cout << endl;


    for (int i=0 ; i<inq.size() ; ++i){
        cout << inq[i] << " ";
    }
    cout << endl;
    // pre order
    vector <int> prep = preorder (p); 
    anspreorder.clear();
    vector <int> preq = preorder (q);
    anspreorder.clear();
    
    for (int i=0 ; i<prep.size() ; ++i){
        cout << prep[i] << " ";
    }
    cout << endl;
    
    for (int i=0 ; i<preq.size() ; ++i){
        cout << preq[i] << " ";
    }
    cout << endl;
    
    /*if (inp.size() != inq.size() && prep.size() != preq.size()){
        cout << "size unequal" << endl;
        return false;
    }*/
    //if (inp.size() == inq.size() && prep.size() == preq.size()) {
        if (inp != inq){
            return false;
        }
        if (prep != preq){
            return false;
        }

        return true;
    
    
}

// approach 2: recursively checking if left of one tree is equal to left of another

bool sameTreeRec (BinaryTreeNode <int> * p , BinaryTreeNode <int> * q){
    if (p==NULL && q==NULL){
        return true;
    }

    if (p && q && p->data == q->data){
        return (sameTreeRec (p->left,q->left) && sameTreeRec (p->right , q->right));
    }

    return false;
}


/*
LeetCode 104. Maximum Depth of Binary Tree
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

*/

// approach: recursive
int maxDepth(BinaryTreeNode <int> * root) {
    int size = 1;
        
    if (root==NULL){
        return 0;
    }
        
    if (root->left == NULL && root->right == NULL){
        return size;
    }
        
    int left = maxDepth (root->left);
    int right = maxDepth (root->right);
    
    if (left > right){
        size += left;
    }
    else {
        size += right;
    }
    return size;
}

int maxDepthBetter (BinaryTreeNode <int> * root){
    if (root == NULL){
        return 0;
    }
    return (1 + max (maxDepthBetter (root->left) , maxDepthBetter (root->right)));
}

// LeetCode 543: Diameter of a binary tree
// maximum distance between any two nodes (may or may not pass through the root)

/*
Approach: both nodes (to be taken into account) can be:
1. on left and right side then dia = left height + right height
2. both on left side (left height + right height) but for root as root->left 
3. both on right side

maximum (dia(root) , dia(root->left) , dia(root->right))

Complexity: for a balanced tree- O(nlogn) [here height of the tree is logn] => n*h
            for an unbalaced tree (slanted towards one side)- o(n^2) [here height is n] => n*h
            hence worst case O(n^2)
*/

int findDia (BinaryTreeNode <int> * root){
    if (root == NULL){
        return 0;
    }

    int option1 = maxDepth (root->left) + maxDepth (root->right);
    int option2 = findDia (root->left);
    int option3 = findDia (root->right);

    return max (option1 , max (option2 , option3));
}

// above code is O(n^2) for one sided trees and hence we require a more optimized solution
// approach 2: we ask root->left and root->right for both height and dia 

// pair is built in and can have different types of inputs
pair <int , int> heightDia (BinaryTreeNode <int> * root){
    if (root == NULL){
        pair <int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }

    pair <int, int> leftAns = heightDia (root->left);
    pair <int, int> rightAns = heightDia (root->right);
    int ld = leftAns.second;
    int lh = leftAns.first;
    int rd = rightAns.second;
    int rh = rightAns.first;

    int height = 1 + max(lh , rh);
    int dia = max (lh + rh , max (ld , rd));
    pair <int , int> p;
    p.first = height;
    p.second = dia;
    return p;

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
    //BinaryTreeNode <int> * root = takeInputLevelWise ();
    //printTreeLevelWise (root);

    //cout << "Total number of nodes = " << countNodes(root) << endl;

    //vector <int> in {4,2,5,1,3,6};
    //vector <int> pre {1,2,4,5,3,6};

    //BinaryTreeNode <int> * f = constructBTree (in , pre);
    //printTreeLevelWise (f);

    //BinaryTreeNode <int> * found = searchBST (root , 2);
    //printTreeLevelWise (found);
    
    //cout << isUnivalTree (root) << endl;
    
    /*
    vector <int> in = inorder (root);
    for (int i=0 ; i<in.size() ; ++i){
        cout << in[i] << " ";
    }
    cout << endl;

    vector <int> pre = preorder (root);
    for (int j=0 ; j<pre.size() ; ++j){
        cout << pre[j] << " ";
    }
    cout << endl;
    */
    /*
    BinaryTreeNode <int> * p = takeInputLevelWise ();
    printTreeLevelWise (p);

    BinaryTreeNode <int> * q = takeInputLevelWise ();
    printTreeLevelWise (q);

    cout << sameTreeRec (p,q) << endl; 

    delete p;
    delete q;
    */

    //cout << isSymmetricRec (root) << endl;
    
    // buildBtree EX
    // 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1 
    //int in[] = {4, 2, 5, 1, 8, 6, 9, 3, 7};
    //int pre[] = {1, 2, 4, 5, 3, 6, 8, 9, 7};
    
    //BinaryTreeNode <int> * root = constructBTree (in , pre, 9);
    //printTreeLevelWise (root);
    
    BinaryTreeNode <int> * root = takeInputLevelWise ();
    printTreeLevelWise (root);
    pair <int , int> p = heightDia (root);

    cout << "height: " << p.first << endl;
    cout << "diameter: " << p.second << endl;
    
    
    delete root;
    return 0;
}