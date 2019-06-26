#include <bits/stdc++.h>

using namespace std;

int main(){
    char arr[10];
    char res[8];
    for (int i=0 ; i<10 ; ++i){
        cin>>res[i];
    }
    if (arr[9]=='P'){
        (res[0]) = int(arr[0])+1;
        (res[1]) = int(arr[1])+2;
    }
    for (int j=2 ; j<8 ; ++j){
        res[j] = arr[j];
    
    }
    for (int k=0 ; k<8 ; ++k){
        cout<<res[k];
    }
}