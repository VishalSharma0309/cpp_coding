//merge two sorted linked lists

#include<bits/stdc++.h>

using namespace std;

class node {
    public:
    int data;
    node * next;

    node (int data){
        this -> data = data;
        next = NULL;
    }
};


//complexity O(n)
node * takeinput_better(){
    //instead of running a loop to find the tail we maintain it in a pointer called tail
    int data;
    cin>>data;
    node * head = NULL;
    node * tail = NULL;
    while (data != -1){
        node *newnode = new node(data);
        if (head == NULL){
            head = newnode;
            tail = newnode;
        }

        else {
            tail->next = newnode;
            tail = tail -> next;
        }

        cin>>data;
    }
    return head;
}


void print_ll(node *head){
    node *temp = head;

     while (temp != NULL){
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }

    cout<<endl;

}

//merge two individually sorted LLs into one
node * mergetwosortedLL(node * h1 , node * h2){

    node * fh = NULL;
    node * ft = NULL;
        
    if (h1 == NULL || h2 == NULL){
        if (h1 == NULL && h2 == NULL){
            return NULL;
        }
        else if (h1 == NULL) {
            return h2;
        }
        else if (h2 == NULL){
            return h1;
        }
    }
    else {
        if (h1->data < h2->data){
            fh = h1;
            ft = h1;
            h1 = h1->next;
        }

        else {
            fh = h2;
            ft = h2;
            h2 = h2->next;
        }

        while (h1 != NULL && h2 != NULL){
            if (h1->data < h2->data){
                ft -> next = h1;
                ft = h1;
                h1 = h1->next;
            }
            else {
                ft -> next = h2;
                ft = h2;
                h2 = h2->next;
            }

        }

        if (h1 == NULL){
            while (h2 != NULL){
                ft -> next = h2;
                ft = h2;
                h2 = h2->next;
            }
        }

        else {
            while (h1 != NULL){
                ft -> next = h1;
                ft = h1;
                h1 = h1->next;
            }
        }
    }
    return fh;
}


//finding the mid point using slow and fast pointers
node * findmid(node * head){
    
    if (head == NULL){
        return NULL;
    }
    
    node * slow = head;
    node * fast = head;
    
    while (fast->next != NULL && fast->next->next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;

    }
   return slow;
}

//merge sort a LL
node * mergesortLL(node * head){
    
    if (head->next == NULL){
        return head;
    }

    
    node * h1 = head;
    node * mid = findmid(head);
    node * h2 = mid->next;
    
    node * ret = NULL;
    mid->next = NULL;
    /*print_ll(h1);
    print_ll(h2);
    char stop;
    cin>>stop;*/

    //only one element left in the LL
           
    if (h1->next == NULL && h2->next == NULL){
            ret = mergetwosortedLL(h1 , h2);
            return ret;
    }  
        
    h1 = mergesortLL(h1);
    h2 = mergesortLL(h2);

    ret = mergetwosortedLL(h1 , h2);

    return ret;
}

int main(){

    node * h1 = takeinput_better();
    print_ll(h1);
    //node * h2 = takeinput_better();
    //print_ll(h2);
    node * head = mergesortLL(h1);
    //node * mid = findmid(h1);
    //cout<<mid->data;
    print_ll(head);
    return 0;
}