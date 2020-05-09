#include <bits/stdc++.h>
#include "node.cpp"

using namespace std;


//approach 1: maintain a record of all addresses. If any of them gets repeated then there is a cycle
//time: O(n^2) and space: O(n)
bool hasCycle(node *head) {
    node * temp = head;
    vector<node *> add;
    while(temp!=NULL){
        for(int i=0 ; i<add.size() ; ++i){
            if (add[i]==temp){
                return true;
            }
        }
                      
        add.push_back(temp);
        temp = temp->next;            
    }
    return false;
}


//approach 2: using fast and slow pointers. If there is a cycle, they will eventually meet
//time complexity: O(n) and space complexity O(1)
bool hasCycle2(node * head){
    if (head==NULL || head->next==NULL){
        return false;
    }
    
    node * slow = head;
    node * fast = head;

    while (fast != NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast){
            return true;
        }
    } 

    return false;
}

int main(){


    return 0;
}