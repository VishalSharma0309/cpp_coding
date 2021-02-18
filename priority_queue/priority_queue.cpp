/*
PRIORITY QUEUE
An importance factor is associated with every element. 
In case of FCFS, time is this importance factor.

Types:
1. Min priority queue
2. Max priority queue

Functions:
1. Insert
2. Get Max/ Min element
3. Remove Max/ Min element

Suggested Data Structure: Balanced BST (because all 3 functions will take logn)
A balanced trees should not have a height difference of more than 1 b/w two braches

For n insertions & n deletions
arrays, LL will have n^2 complexity
while BST will have nlogn complexity

Issues with BST:
1. Balancing the height
2. Storing the BST

HEAP:
* Heap is a complete binary tree (CBT) i.e. every level except the last one should be completely filled
& the last level will be filled from left to right
Also, deletion can also occer only at the rightmost element in the last level

* Heap follows its order property


* Min no. of nodes for height h in a CBT = 2^0 + 2^1 + 2^2 + ... + 1
                                        = 2^(h-1)
* Max no. of nodes for height h in a CBT = 2^h - 1
Hence this is the range for no. of nodes in a CBT

* Similarly log(n+1) <= h <= log2(n) + 1
            O(log2(n)) <= h <= O(log2(n))
Hence, height of CBT is of the order is log2(n) for both best & worst case

If we store a CBT in the form of an array, we can insert directly at the end
and each element at ith position will have its children at 2i+1 & 2i+2

Deletion can also occur only at the end of this array. Hence, nextindex --
To find the parent of xth index = (x-1)/2 -> integer part only

For min heap-
Every parent should be smaller than its children

FOR INSERT FUNCTION:
Insert at the left-most available position in the last level.
Then compare with parent and swap values if children < parent.
Repeat this process till either parent < children or we reach root.
This process is called up-heapify.
Complexity -> O(h) = o(logn)

FOR DELETION FUNCTION:
This process is called down-heapify.
STEP 1: Swap the element to be deleted (root value) with the last element 
STEP 2: Delete the last element
STEP 3: Compare the swaped element with its children.
Swap with the smaller of two children if required.
Repeat.
Complexity -> O(h) = O(logn)

GET MIN FUNCTION:
The value at root.
Complexity -> O(1)

*/

/*
HEAP SORT
The insert & deletion function in priority queue results in a sorted array
This is called the HEAP SORT

Time Complexity -> O(nlogn)
Space Complexity -> O(n)
*/

/*
In-built Priority Queue
header: #include <queue>
priority_queue <int> pq;
* By Default MAX priority order in in-built

* Creating a min heap
priority_queue <int, vector<int>, greater<int> > pq;

FUNCTIONS:
1. empty ()
2. size ()
3. void push (element)
4. T top ()
5. void pop ()

*/


#include <bits/stdc++.h>
using namespace std;

class PriorityQueue {
    vector <int> pq;
    
    public:
    PriorityQueue (){

    }

    bool isEmpty (){
        return pq.size() == 0;
    }

    int getSize (){
        return pq.size();
    }

    int getMin (){
        if (!isEmpty())
            return pq[0];
        return 0;
    }

    void insert (int element){
        pq.push_back(element);
        int childIndex = pq.size() - 1;
        
        while (childIndex > 0)
            {int parentIndex = (childIndex - 1)/2;
            if (pq[childIndex] < pq[parentIndex]){
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else {
                break;
            }
            childIndex = parentIndex;
        }
    }

    int removeMin_selfattempt (){
        
        if (isEmpty()){
            return 0;
        }
        
        // STEP 1: swap last element & root
        int temp = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq[pq.size() - 1] = temp;

        // STEP 2: delete the last element
        pq.pop_back();

        // STEP 3: Re-order -> Down-Heapify
        int parent = 0;
        int flag = 0;

        while (flag != 1)
        {
        int ch1 = 2*parent + 1;
        int ch2 = 2*parent + 2;
        int x=-1;
        // both children present
        if (ch1 <= pq.size()-1 && ch2 <= pq.size()-1){
        if (pq[parent] > pq[ch1] || pq[parent] > pq[ch2]){
            if (pq[parent] > pq[ch1] && pq[parent] > pq[ch2]){
                if (pq[ch1] < pq[ch2]){
                    // swap oth with 1st
                    int te = pq[parent];
                    pq[parent] = pq[ch1];
                    pq[ch1] = te;
                    x = ch1;
                }

                else {
                    // swap with 2nd
                    int tem = pq[parent];
                    pq[parent] = pq[ch2];
                    pq[ch2] = tem;
                    x = ch2;
                }
            }
            else if (pq[parent] > pq[ch1] && pq[parent] < pq[ch2]){
                // swap with 1st
                int te = pq[parent];
                pq[parent] = pq[ch1];
                pq[ch1] = te;
                x = ch1;
            }
            else {
                // swap with 2nd
                int tem = pq[parent];
                pq[parent] = pq[ch2];
                pq[ch2] = tem;
                x = ch2;
            }
        }
        if (x!=-1){
            parent = x;
        }

        else {
            flag = 1;
        }
        }

        else if (ch1 <= pq.size()-1 && ch2 > pq.size()-1){
            if (pq[parent] > pq[ch1]){
                int te = pq[parent];
                pq[parent] = pq[ch1];
                pq[ch1] = te;
                x = ch1;
            }

        }

        else {
            flag = 1;
        }

        }
        return temp;
    }

    int removeMin (){
        if (isEmpty()){
            return 0;
        }

        int ans = pq[0];
        pq[0] = pq[pq.size()-1];
        pq.pop_back();

        // down-heapify

        int parentIndex = 0;
        int leftChildIndex = 2*parentIndex + 1;
        int rightChildIndex = 2*parentIndex + 2;

        while (leftChildIndex < pq.size()){
            int minIndex = parentIndex;
            if (pq[minIndex] > pq[leftChildIndex]){
                minIndex = leftChildIndex;
            }
            if (pq[rightChildIndex] < pq[minIndex] && rightChildIndex < pq.size()){
                minIndex = rightChildIndex;
            }
            if (minIndex == parentIndex){
                break;
            }
            int temp = pq[minIndex];
            pq[minIndex] = pq[parentIndex];
            pq[parentIndex] = temp;

            parentIndex = minIndex;
            leftChildIndex = 2*parentIndex + 1;
            rightChildIndex = 2*parentIndex + 2;

        }

        return ans;
    }


};

// Space Complexity O(1)
// min heap will return desc arr
vector <int> InplaceHeapSort (vector <int> arr){
    // create heap in the input array
    // we assume the first element is the first insertion in the heap
    // remaining elements are treated as insertions


    int n = arr.size(); 
    for (int i=1 ; i<n ; ++i){
        int childIndex = i;
        while (childIndex > 0){
            int parentIndex = (childIndex - 1)/2;
            
            if (arr[childIndex] < arr[parentIndex]){
                int temp = arr[childIndex];
                arr[childIndex] = arr[parentIndex];
                arr[parentIndex] = temp;
            }

            else {
                break;
            }

            childIndex = parentIndex;

        }
    }

    // sorting starts
    // downheapify

    while (n>1){
        // STEP 1: swap first & last elements
        int temp = arr[0];
        arr[0] = arr[n-1];
        arr[n-1] = temp;

        // STEP 2: downsize the arr
        n--;

        int parentIndex = 0;
        int leftChildIndex = 2*parentIndex + 1;
        int rightChildIndex = 2*parentIndex + 2;
        int minIndex = parentIndex;

        while (leftChildIndex < n){

            if (arr[leftChildIndex] < arr[parentIndex]){
                minIndex = leftChildIndex;
            }

            if (arr[rightChildIndex] < arr[leftChildIndex] && rightChildIndex < n){
                minIndex = rightChildIndex;
            }

            if (minIndex == parentIndex){
                break;
            }
            
            int temp = arr[parentIndex];
            arr[parentIndex] = arr[minIndex];
            arr[minIndex] = temp;

            parentIndex = minIndex;
            leftChildIndex = 2*parentIndex + 1;
            rightChildIndex = 2*parentIndex + 2;
        }


    }

    return arr;

}

/*
QUES: K-SORTED ARRAY
Sort a given array in the desc order with k given.
It means that any element at ith index cannot move more than 
(k-1) units left or right to its position.
*/
/*
Rather than traversing the complete array to find the maxima, 
in a k-sorted array you have to check only k-1 elements left & right
and one at the same position have to be checked.
This gives a complexity less than nlogn
*/
/*
Solution: create a max heap of size k and remove the top element to find each element
*/
void kSortedArray (int input[], int n, int k) {
    priority_queue<int> pq;

    for (int i=0 ; i<k ; ++i){
        pq.push(input[i]);
    }
    // to find the position we're working on in sorted ans
    int j=0;
    for (int i=k ; i<n ; ++i){
        input[j] = pq.top();
        pq.pop();
        pq.push(input[i]);
        j++;
    }

    while (!pq.empty()){
        input [j] = pq.top();
        pq.pop();
    }
}

/*
QUES: K-SMALLEST ELEMENTS ARRAY
*/
void kSmallestElements (vector <int> arr, int k){
    priority_queue <int> pq;

    for (int i=0 ; i<k ; ++i){
        pq.push(arr[i]);
    }

    for (int i=k ; i<arr.size() ; ++i){
        if (pq.top() > arr[i]){
            pq.pop ();
            pq.push (arr[i]);
        }
    }

    for (int i=0 ; i<k ; ++i){
        cout << pq.top() << " ";
        pq.pop();
    }

}

/*
Leetcode 455: Assign cookies
*/
int findContentChildren (vector <int> & g, vector <int> & s){
    priority_queue <int> gr;
    priority_queue <int> si;

    int ans=0;

    for (int i=0 ; i<g.size() ; ++i){
        gr.push(g[i]);
    }

    for (int i=0 ; i<s.size() ; ++i){
        si.push(s[i]);
    }

    for (int i=0 ; i<g.size() && !gr.empty() && !si.empty() ; ++i){
        if (gr.top() <=  si.top()){
            ans++;
            gr.pop();
            si.pop();
        }
        else {
            gr.pop();
        }
    }

    return ans;
} 



/*
LeetCode 215. Kth Largest Element in an Array

*/
int findKthLargest(vector<int>& nums, int k) {
    priority_queue <int, vector<int>, greater<int> > pq;
    for (int i=0 ; i<k ; ++i){
        pq.push(nums[i]);
    }
        
    for (int i=k ; i<nums.size() ; ++i){
        if (nums[i] > pq.top()){
            pq.pop();
            pq.push(nums[i]);
        }
    }
        
    return pq.top();
}


/*
1046. Last Stone Weight
*/
    int lastStoneWeight(vector<int>& stones) {
        priority_queue <int> pq;
        
        for (int i=0 ; i<stones.size() ; ++i){
            pq.push(stones[i]);
        }
        
        while (pq.size()!=1 && pq.size()!=0){
            int s1 = pq.top();
            pq.pop();
            int s2 = pq.top();
            pq.pop();
            if (s1!=s2)
                pq.push(abs(s1-s2));
        }
        
        if (pq.size()==1){
            return pq.top();
        }
        else {
            return 0;
        }
    }


/*
378. Kth Smallest Element in a Sorted Matrix

*/

int kthSmallest(vector<vector<int>>& matrix, int k){

    priority_queue <int> pq;
    int o = 0;
    for (int i=0 ; i<matrix.size() ; ++i){

        for (int j=0 ; j<matrix[i].size() && o!=k ; ++j){
            pq.push(matrix[i][j]);
            //cout << matrix[i][j] << " ";
            ++o;
        }
    }
        cout << endl;

    o = 0;
    for (int i=0 ; i<matrix.size() ; ++i){

        for (int j=0 ; j<matrix[i].size(); ++j){
            if (o<k){
                o++;
            }
            else {
                //cout << matrix[i][j] << " " << pq.top() << endl;
                if (matrix[i][j] < pq.top()){
                    pq.pop();
                    pq.push(matrix[i][j]);
                }
            }
        }
    }
    return pq.top();
}

int main(){
    vector <int> in;
    in.push_back(5);
    in.push_back(1);
    in.push_back(2);
    in.push_back(0);
    in.push_back(8);

    kSmallestElements (in, 2);
    cout << endl;
    return 0;
}
