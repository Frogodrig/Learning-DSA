#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main() {

    vector<char> a1,a2;
    a1 = {'c','b','a'};
    a2 = {'a','b','c','d'};

    map<char, int> mp;

    for(auto i:a2) {
        mp[i]++;
    }

    vector<char> ans;
    for(auto i:a1) {
        if(mp.find(i)!=mp.end()) {
            auto temp = mp.find(i);
            int count = temp->second;
            vector<char> v(count,i);
            ans.insert(ans.end(),v.begin(),v.end());
            mp.erase(i);
        }
    }

    for(auto i:mp) {
        vector<char> v(i.second,i.first);
        ans.insert(ans.end(),v.begin(),v.end());
    }

    for(auto i:ans) {
        cout<<i<<" ";
    } cout<<"\n";

    return 0;
}