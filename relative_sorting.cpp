#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main() {

    vector<int> arr1,arr2,ans;
    map<int,int> mp;

    arr1 = {2,3,1,3,2,4,6,7,9,2,19};
    arr2 = {2,1,4,3,9,6};

    for(auto i:arr1) {
        mp[i]++;
    }

    for(auto i:arr2) {
        if(mp.find(i)!=mp.end()) {
            auto x = mp.find(i);
            int count = x->second;
            vector<int> v(count, i);
            ans.insert(ans.end(), v.begin(), v.end());
            mp.erase(i);
        }
    }

    for(auto i:mp) {
        int element = i.first;
        int count = i.second;
        vector<int>v(count,element);
        ans.insert(ans.end(), v.begin(), v.end());
    }

    for(auto i:ans) {
        cout<<i<<" ";
    } cout<<"\n";

    return 0;
}