#include<iostream>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main() {

    vector<string>strs = {"eat","tea","tan","ate","nat","bat"};

    unordered_map<string, vector<string> >umap;
    vector<vector<string>> ans;

    for(auto x: strs) {
        string temp = x;
        sort(x.begin(), x.end());
        umap[x].push_back(temp);
    }

    for(auto x: umap) {
        vector<string>temp = x.second;
        ans.push_back(temp);
    }

    for(auto x: ans) {
        for(auto i: x) {
            cout<<i<<" ";
        }    
    } cout<<"\n";

    return 0;
}