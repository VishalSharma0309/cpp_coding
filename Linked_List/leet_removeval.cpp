
#include <iostream>

using namespace std;


class node{
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

node * deletenode(node * head, int pos){
    
    node * temp = head;
    if (pos == 0){
        head = head -> next;
        return head;
    }
    else {
       
        for (int i=0 ; i<pos-1 && temp!=NULL; ++i){
            temp = temp -> next;
        }

        if (temp!=NULL){    
            node * a = temp -> next;
            if (a -> next != NULL)
                temp -> next = a -> next;
            else 
                temp -> next = NULL;

            delete a;
        }
        else {
            cout<<"pos out of range"<<endl;
        }
    }

    return head;

}


//deleting all nodes with a particular value
node * removeval(node * head, int val){
    int count = 0;
    node * temp = head;
    while (temp != NULL){
        if (temp->data==val){
            head = deletenode(head , count);
            count = 0;
            temp = head;
           
        }
        else {
            count++;
            temp = temp->next;
        }             
    }
    
    return head;
}


int main(){

    node * head = takeinput_better();
    print_ll(head);

    //int pos;
    //cin>>pos;
    //head = deletenode(head , pos);
    
    //removeduplicates(head);
    print_ll(head);

    return 0;
}