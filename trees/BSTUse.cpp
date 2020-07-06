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

/*
Functions Included:
    1. Print Tree Level Wise
    2. Take Input Level Wise
    3. Search in BST
    4. In Order vector return
    5. Print in Range 
    6. Check if a Binary tree is BST or not
    7. Construct a balanced BST from a sorted array
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

// print all the elements in a given range
// approach: In order of a BST gives a sorted array

vector <int> inorder;
vector <int> inorder_elements (BinaryTreeNode <int> * root){
    // base case
    if (root==NULL){
        return inorder;
    }

    inorder_elements (root->left);
    inorder.push_back (root->data);
    inorder_elements (root->right);

    return inorder;
}

void printInRange (BinaryTreeNode <int> * root, int lower, int upper){
    vector <int> in = inorder_elements (root);

    for (int i=0 ; i<in.size() ; ++i){
        if (in[i]>=lower && in[i]<=upper){
            cout << in[i] << endl;
        }
        if (in[i]>upper){
            break;
        }
    }
}

// approach 2: recursive
void printInRangeRec (BinaryTreeNode <int> * root, int lower, int upper){
    if (root==NULL){
        return;
    }
    if (root->data <= upper && root->data >= lower){
        cout << root->data << endl;
    }
    if (root->data <= lower){
        printInRangeRec (root->right, lower, upper);
    }
    if (root->data >= upper){
        printInRangeRec (root->left, lower, upper); 
    }
    if (root->data < upper && root->data > lower){
        printInRangeRec (root->left, lower, upper);
        printInRangeRec (root->right, lower, upper);
    }
}

// Check if a binary tree is a BST or not


// approach 1: 
// root->data > max (root->left)
// root->data < min (root->right)

// complexity: O(n*height)

int minimum (BinaryTreeNode <int> * root){
    if (root==NULL){
        return INT_MAX;
    }
    return min (root->data , min (minimum (root->left) , minimum (root->right)));

}

int maximum (BinaryTreeNode <int> * root){
    if (root == NULL){
        return INT_MIN;
    }
    return max (root->data , max (maximum (root->left), maximum (root->right)));
}

bool isBST (BinaryTreeNode <int> * root){
    if (root == NULL){
        return true;
    }

    int leftMax = maximum (root->left);
    int rightMin = minimum (root->right);

    bool output = (root->data > leftMax) && (root->data <= rightMin) && isBST (root->left) && isBST (root->right);
    return output;
}

// approach 2:
// above approach calls the same node to calculate min/max and isBST in two different instances
// which makes it inefficient
// we should make a function which return min, max and isBST for each node

// complexity: O(n)

class isBSTReturn {
    public:
    int minimum;
    int maximum;
    bool isBST;
};

isBSTReturn isBST2 (BinaryTreeNode <int> * root){
    if (root==NULL){
        isBSTReturn output;
        output.minimum = INT_MAX;
        output.maximum = INT_MIN;
        output.isBST = true;
        return output;
    }

    isBSTReturn leftOutput = isBST2 (root->left);
    isBSTReturn rightOutput = isBST2 (root->right);

    int minimum = min (root->data , min (leftOutput.minimum , rightOutput.minimum));
    int maximum = max (root->data , max (leftOutput.maximum , rightOutput.maximum));

    bool isBSTFinal = (root->data > leftOutput.maximum) && (root->data <= rightOutput.minimum) && leftOutput.isBST && rightOutput.isBST;

    isBSTReturn output;
    output.minimum = minimum;
    output.maximum = maximum;
    output.isBST = isBSTFinal;

    return output;
    
}

// approach 3: top-down solution
// put constraints on each node corresponding to the data in its above node

// complexity: O(n)

bool isBST3 (BinaryTreeNode <int> * root, int min = INT_MIN , int max = INT_MAX){
    if (root == NULL){
        return true;
    }

    if (root->data < min || root->data > max){
        return false;
    }

    bool isLeftOk = isBST3 (root->left , min, root->data - 1);
    bool isRightOk = isBST3 (root->right , root->data , max);

    return isLeftOk && isRightOk;

}


// construct a balanced BST from a sorted array
/*
Approach: recurcively mid becomes the root
*/

BinaryTreeNode <int> * constructBST (int arr[] , int si , int ei){
    if (ei<si){
        return NULL;
    }
    
    int mid = (si+ei)/2;
    BinaryTreeNode <int> * root = new BinaryTreeNode <int> (arr[mid]);
    root->left = constructBST (arr, si, mid-1);
    root->right = constructBST (arr, mid+1, ei);

    return root;

}

// 4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1 
int main (){
    //BinaryTreeNode <int> * root = takeInputLevelWise ();
    //printTreeLevelWise (root);

    //cout << searchBST (root , 2)->data << endl;
    //printInRangeRec (root , 2, 4);
    //inorder.clear();
    //isBSTReturn out = isBST2 (root);
    //cout << out.isBST << endl;
    
    //cout << isBST3 (root) << endl;
    int arr[] = {1,2,3,4,5,6,7};
    BinaryTreeNode <int> * root = constructBST (arr, 0, 6);
    printTreeLevelWise (root);
    delete root;
    return 0;
}