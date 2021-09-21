#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;


int main() {

    int n,m;
    cin>>n;cin>>m;

    vector<int> a(n);
    vector<int> b(n);
    
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    for(int i=0;i<n;i++) {
        cin>>b[i];
    }

    unordered_set<int> s;
    for(int i=0;i<n;i++) {
        s.insert(a[i]);
    }

    int count = 0;
    for(int i=0;i<m;i++) {
        int key = b[i];
        if(s.find(key)!=s.end()) {
            count++;
            s.erase(key);
        }
        return count;
    }

    return 0;
}
