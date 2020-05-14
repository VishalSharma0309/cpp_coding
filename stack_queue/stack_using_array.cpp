#include <bits/stdc++.h>

using namespace std;

class stackUsingArray{
    private:
    int * data;
    int nextindex;
    int capacity;

    public:
    //dynamically creating an array of size 'totalsize' as given by the user
    stackUsingArray(int totalsize){
        data = new int[totalsize];
        nextindex = 0;
        capacity = totalsize;
    }

    //return the number of elements in the stack
    int size(){
        return nextindex;
    }

    //check if the stack is empty or not
    bool isEmpty(){
    /*    if (nextindex==0){
            return true;
        }
        return false;
    }*/

    //better version of above if else
    return nextindex==0;
    //returns true if nextindex=0 and false if not
    }

    //function to insert element
    void push(int element){
        //overflow condition
        if (nextindex == capacity){
            cout<<"Error: Stack FULL"<<endl;
            return;
        }
        data[nextindex] = element;
        nextindex++;
    }

    //function to delete element
    //returns the element delted
    int pop(){
        //underflow condition
        if (isEmpty()){
            cout<<"Error: Stack empty"<<endl;
            return INT_MIN;
        }
        nextindex--;
        return data[nextindex];
    }

    //function to display the topmost element
    int top(){
        //underflow condition
        if (isEmpty()){
            cout<<"Error: Stack empty"<<endl;
            return INT_MIN;
        }
        return data[nextindex-1];
    }
};



int main(){

    return 0;
}