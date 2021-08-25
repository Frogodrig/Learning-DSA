#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr;
    
    int n;
    cout<<"Enter array size : "<<endl;
    cin>>n;
    
    cout<<"Enter elements : "<<endl;
    for (int i = 0; i < n; i++){
        int a;
        cin>>a;
        arr.push_back(a);
    }    
    
    unordered_set<int> s;
    
        for (int i = 0; i < n; i++) {
 
        if (s.find(arr[i]) == s.end()){ // if there is no duplicate element
            s.insert(arr[i]);
        }    
 
        else { //for duplicates

            for (int j = arr[i] + 1; j < INT_MAX; j++) { // j here is acting like the next greater element that will replace duplicate.
                if (s.find(j) == s.end()) { // if there is no duplicate element same as the value of j
                    arr[i] = j;
                    s.insert(j); // inserting into set to compute in the next iteration
                    break;
                }
            }
        }
    }
    
    for(auto i : arr){
        cout<<i<<" ";
    }cout<<endl;
}