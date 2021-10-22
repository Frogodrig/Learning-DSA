#include<iostream>
#include<vector>
using namespace std;

const int N = 1e3+2;
int dp[N][N];
int n,m;

vector<char>a(N);
vector<char>b(N);

//Time Complexity O(m*n)

int LCS(int i, int j) {

    if(i<=0) {
        return 0;
    }

    if(j<=0) {
        return 0;
    }

    if(dp[i][j]!=-1) {
        return dp[i][j];
    }

    if(a[i] == b[j]) {
        dp[i][j] = 1+LCS(i-1,j-1);
    } else {
        dp[i][j] = max(LCS(i-1,j),LCS(i,j-1));
    }

    return dp[i][j];
}

int main() {

    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            dp[i][j] = -1;
        }
    }

    cin>>n>>m;

    for(int i=0;i<n;i++) {
        cin>>a[i];
    }

    
    for(int i=0;i<m;i++) {
        cin>>b[i];
    }

    cout<<LCS(n,m)<<endl;

    return 0;
}