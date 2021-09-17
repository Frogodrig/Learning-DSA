#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define ff first
#define ss second

int main() {

    int n;cin>>n;
    int k;cin>>k;

    vector<int> a(n);

    for(int i=0;i<n;i++) {
        cin>>a[i];
    }

    map<int,int> freq;

    for(int i=0;i<n;i++) {
        int presentSize = freq.size();
        if(freq[a[i]] == 0 && presentSize == k) {
            break;
        }

        freq[a[i]]++;
    }

    vii ans;
    map<int,int> ::  iterator it;

    for(it=freq.begin();it!=freq.end();it++) {
        if(it->second != 0) {
            pair<int,int> p;
            p.first = it->second;
            p.second = it->first;
            ans.push_back(p);
        }
    }

    sort(ans.begin(), ans.end(), greater<pair<int,int>>());

    vii :: iterator it1;

    for(it1 = ans.begin();it1!=ans.end();it1++) {
        cout<<it1->second << " " << it1->first<<"\n";
    }

    return 0;
}