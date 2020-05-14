// stack explicit and inbuilt
#include <bits/stdc++.h>

using namespace std;


// explicit stack implementation
//template has to be labelled before each class explicitely
template <typename T>
class node {
    public:
    T data;
    node<T> * next;
    node (T data){
        this->data = data;
        next = NULL;
    }
};


//all functions are in order O(1), hence same as that using an array 
template <typename T>
class stackUsingLL {
    private:
    node<T> * head;
    int size; //contains the number of elememts the stack currently has
        
    public:
    stackUsingLL() {
        head = NULL;
        size = 0;
    }


    //insertion at head only 
    //i.e. if temp->next == NULL then temp = tail 
    void * push (T element){

        node <T> * newnode = new node <T>(element);
        size++;
            
        newnode->next = head;
        head = newnode;
        //works when head==NULL as well
    }

    
    //delete also from the head
    T pop(){

        if (head==NULL){
            cout<<"Underflow error"<<endl;
            return 0;
        }
        
        T temp = head->data;
        node<T> * x = head->next;
        
        delete head;
        size--;
        
        head = x;
        return temp;
    }

    T top(){
        if (head==NULL){
            cout<<"Underflow error"<<endl;
            return 0;
        }
        
        return head->data;
    }

    bool isEmpty(){
        return head==NULL;
    }

    int getsize(){
        return size; 
    }

};

//Inbuilt Stack
// #include <stack>
// stack<int> s1;
// functions:
//      1. void push(T element)
//      2. void pop()
//      3. T top()
//      4. int size()
//      5. bool empty()


int main(){
    stackUsingLL <int> s;
    s.push(10);
    cout<<s.top()<<endl;
    cout<<s.pop()<<endl; 
    //cout<<s.top()<<endl;
    //cout<<s.getsize()<<endl; 
    s.push(20);
    cout<<s.top()<<endl;
    
    return 0;
}