#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<bool> vis;
int n,m;
vector<vector<int>> adj;
vector<int> components;

int get_comp(int idx) {
    if(vis[idx]) {
        return 0;
    }
    vis[idx] = true;
    int ans = 1;
    for(auto i: adj[idx]) {
        if(!vis[i]) {
            ans += get_comp(i);
            vis[i] = true;
        }
    }
    return ans;
}

int main() {
    cin>>n>>m;
    adj = vector<vector<int>>(n);
    vis = vector<bool>(n);
    
    for(int i=0;i<m;i++) {
        int x,y;cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(auto i: vis) {
        i = false;
    }

    for(int i=0;i<n;i++) {
        if(!vis[i]) {
            components.push_back(get_comp(i));
        }
    }
    for(auto i:components) {
        cout<<i<<" ";
    }cout<<"\n";
    return 0;
}