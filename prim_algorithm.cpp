#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int n,m;
const int N = 1e5+6;
vector<vector<int>> g[N];
int cost = 0;
vector<int> dist(N),parent(N);
const int INF = 1e9;
vector<bool> vis(N);

void primsMST(int source) {
    for(int i=0;i<n;i++) {
        dist[i] = INF;
    }
    set<vector<int>> s;
    dist[source] = 0;
    s.insert({0,source}); //{weight,vertex}
    while(!s.empty()) {
        auto x = *(s.begin());
        x.erase();
        vis[x[1]] = true;
        int u = x[1];
        int v = parent[x[1]];
        int w = x[0];
        cout<<u<<" "<<v<<" "<<w<<"\n";
        cost += w;
        for(auto it: g[x[1]]) {
            if(vis[it[0]]) {
                continue;
            }
            if(dist[it[0]] > it[1]) {
                s.erase({dist[it[0]],it[0]});
                dist[it[0]] = it[1];
                s.insert({dist[it[0]],it[0]});
                parent[it[0]] = x[1];
            }
        }
    }
}

int main() {

    cin>>n>>m;
    for(int i = 0;i<m;i++) {
        int x,y;cin>>x>>y;
        g[x].push_back({y,w}); // {Destination,weight}
        g[y].push_back({x,w}); // {Destination,weight}
    }
    primsMST(0);
    cout<<cost;
}