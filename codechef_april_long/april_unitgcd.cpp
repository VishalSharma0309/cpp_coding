#include <bits/stdc++.h>
#include<sys/time.h>

using namespace std;
#define lli long long int


lli getTimeinMicroSeconds(){
    struct timeval start;
    gettimeofday(&start, NULL);
    return start.tv_sec*1000000 + start.tv_usec;
}

void unitgcd(lli N){
    if (N==1){
        cout<<"1"<<endl;
        cout<<"1"<<" "<<"1"<<endl;
    }
    
    else{
    
        cout<<N/2<<endl;

        if (N%2==0){
            for (lli i=1 ; i<N ; i=i+2){
                cout<<'2'<<" "<<i<<" "<<i+1<<endl;
            }
        }
        else {
            cout<<'3'<<" 1 2 3"<<endl;
            for (lli i=4 ; i<N ; i=i+2){
                cout<<'2'<<" "<<i<<" "<<i+1<<endl;
                }
        }
    }
}

int main(){
    lli t1 = getTimeinMicroSeconds();
    lli T=10;
    //cin>>T;

    for (lli i=0 ; i<T ; ++i){
        lli N=1000000;
        
        //cin>>N;

        unitgcd(N);
    }
    lli t2 = getTimeinMicroSeconds();
    cout<<t2-t1<<endl;

    return 0;
}