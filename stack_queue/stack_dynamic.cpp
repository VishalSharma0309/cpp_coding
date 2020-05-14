#include <bits/stdc++.h>


using namespace std;

// template is used to make the stack more generic. We can declare it to store any data type (even user defined)
template <typename T>
class stackUsingArray{
    private:
    T * data;
    int nextindex;
    int capacity;

    public:
    //all these funtions work in O(1)->constant time
    
    //dynamically creating an array of size 'totalsize' as given by the user

    stackUsingArray(){        
        nextindex = 0;
        capacity = 4;
        data = new int[capacity];
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
    void push(T element){
        //overflow condition
        if (nextindex == capacity){
            T * newdata = T int[2*capacity];
            for (int i=0 ; i<capacity ; ++i){
                newdata[i]=data[i];
            }
            delete [] data;
            data = newdata;
            capacity *= 2;
        }
        data[nextindex] = element;
        nextindex++;
    }

    //function to delete element
    //returns the element delted
    T pop(){
        //underflow condition
        if (isEmpty()){
            cout<<"Error: Stack empty"<<endl;
            //return INT_MIN;
            //with T we cannot return INT_MIN as its specific to integers
            //hence we return 0 which can be used for any type
            return 0;
        }
        nextindex--;
        return data[nextindex];
    }

    //function to display the topmost element
    T top(){
        //underflow condition
        if (isEmpty()){
            cout<<"Error: Stack empty"<<endl;
            //return INT_MIN;
            return 0;
        }
        return data[nextindex-1];
    }
};



int main(){

    // we have to specify while creating the object of a class using template, which data type it has to use
    stackUsingArray<int> p1;

    return 0;
}