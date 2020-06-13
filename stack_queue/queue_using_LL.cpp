// implementing queue using linked list
// each function has a time complexity of O(1)
#include <bits/stdc++.h>

using namespace std;

template <typename T>
class node {
    public:
    T data;
    node<T> * next;
    
    node(T data){
        this->data = data;
        next = NULL;
    }

};


template <typename T>
class Queue {
    private:

    node<T> * head;
    node<T> * tail;
    int size;
        
    public:
    
    Queue (){
        head = NULL;
        tail = NULL;
        size = 0;
    }
    
    void * enqueue (T info){
        node <T> * newNode = new node <T> (info);

        if (head == NULL){
            // the queue is Empty
            head = newNode;
            tail = head;
            size++;
        }

        else {
            // queue not empty
            tail->next = newNode;
            tail = newNode;
            size++;
        }
    }

    T dequeue (){
        
        if (isEmpty()){
            cout<<"Error: Underflow Condition. The queue is EMPTY"<<endl;
            return 0;
        }
        
        
        node<T> * temp = head->next;
        T ret = head->data;

        delete head;
        size--;
        head = temp;
        return ret;
    }

    T front (){
        if (isEmpty()){
            return 0;
        }
        
        return (head->data);
    }

    bool isEmpty (){
        return (size==0);
    }

    int getSize (){
        return size;
    }
};

/*
Inbuilt Queue
How to include? 
    #include<queue>

Functions:
    1. void push (T elem)
    2. T front ();
    3. void pop ();
    4. int size ();
    5. bool empty ();
*/


int main(){
    Queue <int> q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    cout<<q.front()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.getSize()<<endl;
    return 0;
}