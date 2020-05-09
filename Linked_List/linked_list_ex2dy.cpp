//dynamic linked list
//doubt- deallocation?
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

void print(node * head){
    while (head != NULL){
        cout<< head -> data;
        head = head -> next;        
    }
}




int main(){

    node *n1 = new node(1);
    node *head = n1;

    node *n2 = new node(2);
    n1 -> next = n2;

    node *n3 = new node(3);
    n2 -> next = n3;

    node *n4 = new node(4);
    n3 -> next = n4;

    node *n5 = new node(5);
    n4 -> next = n5;

    print (head);

    //deallocating memory?
    /*node *temp = head -> next;
    while (head != NULL){
        
        delete head;
        head = temp;
        temp = temp -> next;
   
    }*/


}