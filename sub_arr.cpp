#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> &A){
    int count_neg = 0;
    for (int i=0 ; i<A.size() ; ++i){
        if (A[i] < 0)
        ++count_neg;
    }
    cout<<"No. of Negative members: "<<count_neg<<endl;
    
    int index_neg[count_neg];
    int l=0;
    for (int j=0 ; j<A.size() ; ++j){
        if (A[j] < 0){
            index_neg[l] = j;
            l++;
        }
    }
  
    cout<<"index_neg: ";
    for (int qw=0 ; qw<count_neg ; qw++){
        cout<<index_neg[qw];
    }

    /* int sub_arr[count_neg+1][A.size()] ;
    for (int m=0 ; m<count_neg ; ++m){
        for (int no=0 ; no < index_neg[0] ; ++no){
            sub_arr[0][no] = A[no];
        }
        for (int n=index_neg[m]+1 ; n < index_neg[m+1] && n != 0; ++n)
        sub_arr[m][n] = A[n]; 
    }

    cout<<endl<<"Sub_array: "<<endl;
    for (int x=0 ; x<count_neg+1 ; ++x){
        for (int y=0 ; y<sizeof(sub_arr[x]) ; ++y)
        cout<<sub_arr[x][y]<<" ";
        cout<<endl;
    }*/
    
    int sum_arr[count_neg+1];
    for (int q=0 ; q < count_neg ; ++q){
        for (int jo=0 ; jo<index_neg[0] ; ++jo){
            sum_arr[0] += A[jo];
        }
        
        for (int w=index_neg[q]+1 ; w < index_neg[q+1] && q!=0 ; ++w){
            sum_arr[q] += A[w];
        }
    }
    
    cout<<"sum_arr: ";
    for (int to=0; to < count_neg+1 ; ++to){
        cout<<sum_arr[to];
    }
    return A;
}



int main(){
    vector<int> arr = {1, -8, 2, -115, 56, 69, -89, 2};
    solution(arr);
    return 0;
}