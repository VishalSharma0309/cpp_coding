#include <bits/stdc++.h>

using namespace std;

template <typename T>

class QueueUsingArray{
    private:
    T * data;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;

    public:
    QueueUsingArray(int totalsize){
        data = new T[totalsize];
        this->capacity = totalsize;
        nextIndex = 0;
        firstIndex = -1;
        size = 0;
    }

    void enqueue(int info){
         // Toremove the limitation of size 
        // we will create a new array of the double capacity once our earlier array is full

        // first we need to copy all the elements of the original array to the new one
        // elements should be copied in the order of their insertion to the original array
        // to do this we start from firstIndex and run in circle to reach firstIndex again copying 
        // update: firstIndex=0 and nextIndex=capacity
    
        
        
        
        if (firstIndex == nextIndex){
            //cout<<"Error: Overflow. Cannot insert"<<endl;
            //return;
            T * newData = new T[2*capacity];
            for (int i=0 ; i<capacity ; ++i){
                //cout<<data[firstIndex]<<endl;
                newData[i] = data[firstIndex];
                if (firstIndex==capacity-1){
                    firstIndex = 0;
                }
                else {
                    firstIndex++;
                }
            }
            
            delete [] data;
            data = newData;
            
            firstIndex = 0;
            //cout<< data[firstIndex]<< endl;
            nextIndex = capacity;
            capacity = 2*capacity;
        }
             
        data[nextIndex] = info;
        //cout<<nextIndex<<" : "<<data[nextIndex]<<endl;
        size++;
        //cout<<size<<endl;
        nextIndex = (nextIndex + 1) % capacity;
        if (firstIndex == -1){
            firstIndex = 0;
        }

        //cout<< firstIndex << ": : : "<< nextIndex<<endl;
        
    }

    T front(){
        if (isEmpty()){
            cout<<"Queue is Empty"<<endl;
            return 0;
        }
        return data[firstIndex];
    }

    T dequeue(){
        if (isEmpty()){
            cout<< "Queue is Empty"<<endl;
            return 0;
        }
        T ans = data[firstIndex];
        //firstIndex++;
        firstIndex = (firstIndex + 1) % capacity;
        size--;
        if (size == 0){
            firstIndex = -1;
            nextIndex = 0;
        }
        return ans;
    }

    int getSize(){
        return size;
    }

    bool isEmpty(){
        return (size==0);
    }

};


int main(){
    QueueUsingArray<int> q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    //cout<<q.getSize()<<endl;
    q.enqueue(60);
    
    cout<< q.front() << endl;
    cout<< q.dequeue() << endl;
    cout<< q.front() << endl;
    cout<< q.getSize() << endl;
    
}

