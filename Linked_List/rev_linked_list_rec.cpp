//Reverse a linked list
//1. recursively: a) using loop to find tail b) maintaing a tail c) tail from head->next directly
//2. iterative (3 pointers maintained)

#include <bits/stdc++.h>
#include "node.cpp"
using namespace std;

class revLLbetter_sol{
    public:
    node * head;
    node * tail;
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

//complexity O(n^2)
node * revLLrec(node * head){

    //base case
    if (head == NULL || head->next == NULL){
        return head;
    }
    
    //recursive call
    node * smallans = revLLrec(head->next);
    
    //joining the last node 
    node * temp = smallans;
    while (temp->next != NULL){
        temp = temp->next;
    }    

    temp -> next = head;
    head -> next = NULL;

    return smallans;


}






//to improve complexity we maintain both head and tail of the reversed LL
//problem: returning two parameters from a single function
//soln: create a class and make the function return that class type
revLLbetter_sol revLLbetter(node * head){

    if (head == NULL || head->next == NULL){
        revLLbetter_sol ans;
        ans.head = head;
        ans.tail = head;        
        return ans;
    }

    revLLbetter_sol smallans = revLLbetter(head->next);

    smallans.tail -> next = head;
    head -> next = NULL;

    revLLbetter_sol ans;
    ans.head = smallans.head;
    ans.tail = head;
    return ans;
}

//our main expects the result in form of head only so we have to convert this class type to node * type

node * revLL_better (node * head){
    return revLLbetter(head).head;
}


//approach 3 : we take tail = head -> next
//best approach; complexity O(n)
//complexity O(n^2)
node * revLLrec3(node * head){

    //base case
    if (head == NULL || head->next == NULL){
        return head;
    }
    
    //recursive call
    node * smallans = revLLrec3(head->next);
    
    //joining the last node 
    node * tail = head->next;   

    tail -> next = head;
    head -> next = NULL;

    return smallans;


}


//approach 4 : iterative
//maintain three pointer prev, curr, nex and move them accordingly

node * revLLite(node * head){

    if (head==NULL || head->next==NULL){
        return head;
    }
    
    
    node * prev = NULL;
    node * curr = head;
    node * nex = head->next;

    while (nex != NULL){
        curr->next = prev;
        prev = curr;
        curr = nex;
        nex = nex->next;
    }

    curr->next = prev;
    prev = curr;


    return prev;
}


int main(){

    node * head = takeinput_better();
    print_ll(head);

    head = revLLite(head);
    print_ll(head);

}

