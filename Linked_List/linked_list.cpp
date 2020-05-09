#include <iostream>
#include "node.cpp"

using namespace std;

int main(){

    //create objects of class node and also pass the data for the constructor
    node n1(1);
    //storing the address of head i.e. n1
    node *head = &n1;

    node n2(2);
    //to connect the two nodes we should put the address of n2 in the next of n1
    n1.next = &n2;

    //dynamically
    node *n3 = new node(10);
    n2.next = n3;
    node *n4 = new node(20);
    n3 -> next = n4; 
}