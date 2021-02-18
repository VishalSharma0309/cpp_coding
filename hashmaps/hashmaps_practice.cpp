#include <bits/stdc++.h>
using namespace std;

/*
QUES 1: Remove Duplicates
*/

vector <int> removeDuplicates (vector <int> arr){
    vector <int> output;
    unordered_map <int, bool> seen;

    for (int i=0 ; i<arr.size() ; ++i){
        if (seen.count(arr[i])>0){
            continue;
        }
        seen[arr[i]] = true;
        output.push_back(arr[i]);
    }
    return output;
}

/*
QUES 2: Fair Candy Swap
Alice and Bob have candy bars of different sizes: A[i] is the size of the i-th bar of candy that Alice has, and B[j] is the size of the j-th bar of candy that Bob has.

Since they are friends, they would like to exchange one candy bar each so that after the exchange, they both have the same total amount of candy.  (The total amount of candy a person has is the sum of the sizes of candy bars they have.)

Return an integer array ans where ans[0] is the size of the candy bar that Alice must exchange, and ans[1] is the size of the candy bar that Bob must exchange.

If there are multiple answers, you may return any one of them.  It is guaranteed an answer exists.

*/

vector <int> fairSwap (vector <int> A, vector <int> B){

    vector <int> sol;
    int sumA = accumulate(A.begin() , A.end() , 0);
    int sumB = accumulate(B.begin() , B.end() , 0);

    int diff = (sumA - sumB)/2;

    unordered_map <int, bool> mp;

    for (int i=0 ; i<A.size() ; ++i){
        mp[A[i]] = true;
    }

    for (int j=0 ; j<B.size() ; ++j){
        if (mp[B[j]+diff]){
            sol.push_back(B[j]+diff);
            sol.push_back(B[j]);
            return sol;
        }
    }
}

/*
347. Top K Frequent Elements
*/
vector <int> topKFrequent(vector <int> & nums, int k){
    map <int, int> x;
    vector <int> ans;

    for (int i=0 ; i<nums.size() ; ++i){
        x[nums[i]]++;
    }
    
    multimap <int, int> y;
    map <int, int> :: iterator it = x.begin();
    
    while (it!=x.end()){
        y.insert(make_pair(it->second, it->first));
    }

    multimap <int, int> :: iterator it1 = y.begin();
    
    for (int i=0 ; i<k ; ++i) {
        ans.push_back(it1->second);
    }
    return ans;
}

/*
451. Sort Characters By Frequency
Input: "tree"
Output: "eert"

*/
string frequencySort(string s){
    unordered_map <char, int> x;
    string sol;

    for (int i=0 ; i<s.size() ; ++i){
        if (x.count(s[i])>0){
            x[s[i]]++;
        }
        else{
            x[s[i]] = 1;
        }
    }

    unordered_map <char, int> :: iterator it_x = x.begin();

    multimap <int, char, greater<int>> y;
    

    while (it_x!=x.end()){
        y.insert (make_pair(it_x->second , it_x->first));
        //cout << "insert : " << it_x->second << " " << it_x->first << " ";
        it_x++;
    }
        //cout << endl;

        multimap <int, char, greater<int>> :: iterator it_y = y.begin();
    while (it_y!=y.end()){
        //cout << "push back : " << it_y->second << " " << it_y->first << endl;
        for (int i=0 ; i<it_y->first ; ++i){
            sol.push_back(it_y->second);
            //cout << sol << endl;
        }
        
        it_y++;
    }
    return sol;

}

int main() {
    vector <int> in = {0,0,1,1,2,3,2,3,4,4,5,0};
    vector <int> out = removeDuplicates(in);

    for (int i=0 ; i<out.size() ; ++i){
        cout << out[i] << " ";
    }
    return 0;
}
