#include <bits/stdc++.h>
#include "node.cpp"

using namespace std;


node * complen(node * h1 , node * h2){
    node * t1 = h1;
    node * t2 = h2;
    while (t1->next!=NULL && t2->next!=NULL){
        t1 = t1->next;
        t2 = t2->next;
    }

    if (t1->next == NULL){
        return h2;
    }
    else {
        return h1;
    }
    
}

void * insertend(node * head, int val){
    node * temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    node * newnode = new node(val);
    temp -> next = newnode;
}


node * addtwonos(node * h1, node * h2){
    int temp = h1->data + h2->data;
    cout<<temp<<endl;
    node * big = complen(h1 , h2);
    node * small = NULL;

    //cout<<"check1"<<endl;  
    //small = (big==h1) ? h2:h1;
    if (big==h1){
        small = h2;
    }
    else {
        small = h1;
    }
    
    //cout<<"check2"<<endl; 

    if (temp > 9){
        big->next->data = big->next->data + (temp/10);
        temp = temp%10;
    }

    //cout<<"check3";
    node * sol = new node(temp);

    
    
    while (small->next != NULL){
        small = small->next;
        big = big->next;

        int x = big->data + small->data;
        if (big->next!=NULL){
            if (x > 9){
                insertend(sol , x%10);
                big->next->data = big->next->data + (x/10);
            }
            else {
                insertend(sol , x);
            }
        }
        else {
            if (x>9){
                insertend(sol , x%10);
                insertend(sol , x/10);
            }
            else {
                insertend(sol , x);
            }
        }
    }

    //cout<<"check4"<<endl;
    while (big->next != NULL){
        big = big->next;
        if (big->next == NULL){
            if (big->data > 9){
            insertend(sol , big->data%10);
            insertend(sol , big->data/10);
            }
            else {
                insertend(sol , big->data);
            }
        }
        else {
            if (big->data > 9){
                insertend(sol , big->data%10);
                big->next->data = big->next->data + (big->data/10);
            }
            else {
                insertend(sol , big->data);
            }
        }
    }


    /*if (big->data > 9){
        insertend(sol , big->data%10);
        insertend(sol , big->data/10);
    }
    else {
        insertend(sol , big->data);
    }*/
    //cout<<"checck5"<<endl;

    return sol;

}


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


int main(){

    node * h1 = takeinput_better();
    print_ll(h1);
    node * h2 = takeinput_better();
    print_ll(h2);

    //node * big = complen(h1 , h2);
    //print_ll(big);

    //insertend(big , 0);
    //print_ll(big);
    node * res = addtwonos(h1 , h2);
    print_ll(res);

    return 0;
}