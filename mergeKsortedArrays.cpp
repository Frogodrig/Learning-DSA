#include<iostream>
#include<queue>
#include<vector>
using namespace std;

#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define ff first
#define ss second

int main() {

    int k;cin>>k;

    vector<vector<int>> a(k);

    for(int i=0;i<k;i++) {
        int size;cin>>size;

        a[i] = vector<int>(size);
        for(int j=0;j<size;j++) {
            cin>>a[i][j];
        }
    }

    vector<int> idx(k,0);

    priority_queue<pii, vector<pii>, greater<pii> > pq;

    for(int i=0;i<k;i++) {

        pii p;
        p.ff = a[i][0];
        p.ss = i;
        pq.push(p);
    }

    vi ans;

    while(!pq.empty()) {

        pii x = pq.top();
        pq.pop();

        ans.push_back(x.ff);
        if(idx[x.ss]+1 < a[x.ss].size()) {

            pii p;
            p.ff = a[x.ss][idx[x.ss]+1];
            p.ss = x.ss;
            pq.push(p);
        }

        idx[x.ss] += 1;
    }

    for(int i=0;i<ans.size();i++) {
        cout<< ans[i] <<" ";
    } cout<<"\n";

    return 0;
}