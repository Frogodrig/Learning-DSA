#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<algorithm>
using namespace std;

int main() {

    vector<int> nums;
    nums = {1,1,2,2,2,3};

    unordered_map<int,int> umap;

    for(auto x:nums) {
        umap[x]++;
    }

    sort(nums.begin(),nums.end(), [&](int a,int b) {
        return umap[a]!=umap[b] ? umap[a]<umap[b] : a>b;
    });

    for(auto i: nums) {
        cout<<i<<" ";
    } cout<<"\n";

    return 0;
}