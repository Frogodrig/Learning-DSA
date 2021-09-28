#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<vector<int>> adj;
vector<bool> vis;
vector<int> col;
bool bipart;

void color(int node, int curr) {
    if(col[node] != -1 and col[node] != curr) {
        bipart = false;
        return;
    }
    col[node] = curr;
    if(vis[node]) {
        return;
    }
    vis[node] = true;
    for(auto i: adj[node]) {
        color(i, curr xor 1); // (0 xor 1 = 1)  (1 xor 1 = 0) 
    }
}

int main() {

    bipart = true;
    int n,m;cin>>n>>m;
    adj = vector<vector<int>>(n);
    vis = vector<bool>(n,false);
    col = vector<int>(n,-1);

    for (int i = 0; i < m; i++)
    {
        int x,y;cin>>x>>y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i = 0; i < n; i++)
    {
        if(!vis[i]){
            color(i,0);
        }
        if(bipart) {
            cout<<"Graph is Bipartite"<<"\n";
        } else {
            cout<<"Graph is not Bipartite"<<"\n";
        }
    }
    

    return 0;
}