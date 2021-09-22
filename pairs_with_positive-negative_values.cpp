#include<iostream>
#include<unordered_map>
#include<map>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;

int main() {

    vector<int> a,v,ans;

    a = {11,-4,4,-3,-9,4,-4,-2,1,2,-4,2};

    map<int,int> mp;
    for(int i=0;i<a.size();i++) {
        if(a[i]<0) {
            v.push_back(a[i]);
        } else {
            mp[a[i]]++;
        }
    }

    sort(v.begin(),v.end());

    for(int i=v.size();i>0;i--) {
        if(mp[abs(v[i])] > 0) {
            ans.push_back(v[i]);
            ans.push_back(abs(v[i]));
            mp[abs(v[i])]--;
        }
    }

    for(int i=0;i<ans.size();i++) {
        cout<<ans[i]<<" ";
    } cout<<"\n";

    return 0;
}