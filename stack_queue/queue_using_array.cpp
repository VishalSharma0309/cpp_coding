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
        if (firstIndex == nextIndex){
            cout<<"Error: Overflow. Cannot insert"<<endl;
            return;
        }
        else {
            data[nextIndex] = info;
            size++;
            nextIndex = (nextIndex + 1) % capacity;

            if (firstIndex == -1){
                firstIndex = 0;
            }
        }
        
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
    q.enqueue(60);
    
    cout<< q.front() << endl;
    cout<< q.dequeue() << endl;
    cout<< q.getSize() << endl;
    
}

