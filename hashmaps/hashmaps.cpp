/*
Functions required:
1. insert (k key, v value)
2. getValue (k key)
3. deleteKey (k key)
*/
/*
Implementation:
Using balanced BST (so that height is logn)
Complexity-> each function is O(logn)
*/
/*
In-Built Implementation
1. Map -> BST -> O(logn)
Here, inorder will give sorted result
* map is sorted by default (asc)
* for dsc sorting map<int, string, greater<int>> is required
* if two keys can be same use multimap instead of map

2. Unordered Map -> Hashtable -> O(1)
*/

/*

Hashmaps Iterators:
* Iterators are present in the following ds:
vector, list, map, unordered_map, set, unordered_set
* unordered_map <string, int> :: iterator it;
* Start: it = ourMap.begin()
* End: ourMap.end() -> even the last element is over

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map <string, int> ourMap;
    // insert
    // option 1
    pair <string, int> p ("abc", 1);
    ourMap.insert(p);
    // option 2
    ourMap["def"] = 2;

    // search or access elements
    cout << ourMap["abc"] << endl;
    cout << ourMap.at("abc") << endl;
    // using .at() if key is not found will give error
    // cout << ourmap.at["ghi"] << endl; -> error
    cout << ourMap["ghi"] << endl; // this will insert the default value 0 if the key is not found

    // check if a key is there 
    if (ourMap.count("ghi")> 0){  // returns 0 if not there

    }

    // size function
    cout << ourMap.size() << endl;

    // erase an element
    cout << ourMap.erase("ghi") << endl;

    // using the iterator
    unordered_map <string, int> :: iterator it = ourMap.begin();
    while (it!= ourMap.end()) {
        cout << "key" << it->first << " Value: " << it->second << endl;
        it++;
    }    

    // .find() will return an iterator
    unordered_map <string, int> :: iterator it2 = ourMap.begin();
    it2 = ourMap.find("abc");

}

