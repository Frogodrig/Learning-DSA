#include<iostream>
#include<vector>
using namespace std;

vector<int> adj[1e5+2];


int main() {

    int n,m;
    cin>>n>>m;

    vector<vector<int>> adjm(n+1, vector<int>(n+1,0));

    for(int i=0;i<m;i++) {
        int x,y;
        cin>>x>>y;

        adjm[x][y] = 1;
        adjm[y][x] = 1; 
    }

    cout<<"Adjacency matrix of the above graph is given by"<<"\n";

    for(int i=1;i<n+1;i++) {
        for(int j=1;j<n+1;j++) {
            cout<<adjm[i][j]<<" ";
        }cout<<"\n";
    }

    if(adjm[3][7] == 1) {
        cout<<"There is an edge between 3 and 7"<<"\n";
    } else {
        cout<<"No"<<"\n";
    }

    cout<<"\n"<<"\n";

    cin>>n>>m;

    for(int i=0;i<m;i++) {

        int x,y;
        cin>>x>>y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    cout<<"Adjacency list of the above graph is given by: "<<"\n";
    for(int i =1;i<n+1;i++) {
        cout<<i<<" -> ";
        vector<int> :: iterator it;
        for(it = adj[i].begin();it!=adj[i].end();it++) {
            cout<<*it<<" ";
        }cout<<"\n";
    }
    return 0;
}