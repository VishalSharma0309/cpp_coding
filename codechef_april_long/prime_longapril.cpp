#include <bits/stdc++.h>
using namespace std;

#define lli long long int


lli primeFactors(lli n){  
    lli ans=1;
    // Print the number of 2s that divide n  
    
    lli temp = 0;
    while (n % 2 == 0)  
    {  
       temp++;
        //cout << 2 << " ";  
        n = n/2;  
    }  
    
    ans = ans * (temp+1);
  
    // n must be odd at this point. So we can skip  
    // one element (Note i = i +2)  
    for (int i = 3; i <= sqrt(n); i = i + 2)  
    {  
        int f=0;
        // While i divides n, print i and divide n  
        while (n % i == 0)  
        {  
            f++;
            //cout << i << " ";  
            n = n/i;  
        }  
        
        ans = ans*(f+1);
    }  
  
    // This condition is to handle the case when n  
    // is a prime number greater than 2  
    if (n > 2)  
        ans = ans*(1+1);
        //cout << n << " ";  
        
    return ans;
}  



void res(lli a[]){
    
    lli k = primeFactors(a[0]);
    
    if (k<a[1]){
        cout<<'0'<<endl;
    }
    
    else{
        cout<<'1'<<endl;
    }
    
}

int main() {
	// your code goes here
	int T=0; 
    cin>>T;
	for (int i=0 ; i<T ; ++i){
	    lli a[2];
	    
	    for (int j=0 ; j<2 ; ++j){
	        cin>>a[j];
	    }
	    
	    res(a);
	    
	}
	
	return 0;
}
