#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int firstrepeated(vector<int> &a, int n) {

    unordered_map<int,int> umap;

    for(int i=0;i<n;i++) {
        umap[a[i]]++;
    }

    for( int i=0;i<n;i++) {
        int key = a[i];

        auto temp = umap.find(key);
        if(temp->second > 1) {
            return i+1;
        }
    }

    return -1;
}


int main() {

    int n;cin>>n;
    vector<int> a(n);
    
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }

    cout<<firstrepeated(a,n);
    return 0;
}