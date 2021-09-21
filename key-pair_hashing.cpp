#include<iostream>
#include<unordered_map>
#include<vector>
#include<unordered_set>
using namespace std;

int main() {

    int n;cin>>n;
    int sum;cin>>sum;
    vector<int> a(n);

    for(int i=0;i<n;i++) {
        cin>>a[i];
    }

    unordered_map<int,int> umap;

    for(int i=0;i<n;i++) {
        umap[a[i]]++;
    }

    unordered_map<int,int> :: iterator it;

    for(it=umap.begin();it!=umap.end();it++) {

        int f = it->first;
        int val = it->second;
        int s = sum - f;
        if(s == f) {
            if(val>1){
                return true;
            }
        }

        else {
            if(umap.find(s)!=umap.end()) {
                return true;
            }
        }
    }
    return -1;
}



/* This code does not cover the corner case for arr[] = {1,4,45,10,5} and sum = 8
int main() {

    int n;cin>>n;
    int sum;cin>>sum;
    vector<int> a(n);

    for(int i=0;i<n;i++) {
        cin>>a[i];
    }

    unordered_set<int> set;

    for(int i=0;i<n;i++) {
        s.insert(a[i]);
    }

    unordered_set<int> :: iterator it;

    for(it=set.begin();it!=set.end();it++) {

        int first = it;
        int s = sum - first;
        if(set.find(s)!=set.end() && s>0) {
            cout<<first<<" + "<<s<<" = "<<sum;
        }

        else {
            cout<<"There is no such pair";
        }
    }
    return 0;
}

*/