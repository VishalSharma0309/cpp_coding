#include <bits/stdc++.h>

using namespace std;

int main(){
    int size, max = 0;
    cin>>size;
    int arr[size];
    int count = 0;
    for (int i=0 ; i<size ; ++i){
        cin>>arr[i];
        if (arr[i]>max){
            max = arr[i];
        }
    }
    for (int j=0 ; j<size ; ++j){
        if (arr[j]==max)
        ++count;
    }
    cout<<count;
}