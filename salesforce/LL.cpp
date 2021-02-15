#include <bits/stdc++.h>


class node {
    public:
    int data;
    node * next;

    node (int data){
        this->data = data;
        next = NULL;
    }

};


// find mid
struct mid {
    int data;
    node * slow;
}

mid find_mid (node * head){
    if (head == NULL){
        mid sol;
        sol.data = -1;
        sol.slow = NULL;
        return sol;
    }

    node * slow = head;
    node * fast = head;

    while (fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    mid sol;
    if (fast->next == NULL){
        // odd no. of elements
        sol.data = 1;
        sol.slow = slow;
    }

    if (fast->next->next == NULL){
        // even no. of elements
        sol.data = 0;
        sol.slow = slow;
    }

    return sol;
}

node * take_input_better (){
    int data;
    cin >> data;

    node * head = NULL;
    node * tail = NULL;

    while (data != -1){
        node * newnode = new node (data);

        if (head == NULL){
            head = newnode;
            tail = newnode;
        }

        else {
            tail->next = newnode;
            tail = tail->next;
        }

        cin >> data;
    }

    return head;

}


