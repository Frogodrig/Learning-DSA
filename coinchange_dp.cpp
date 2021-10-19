#include<iostream>
#include<vector>
using namespace std;

int count(int ind,int sum, int S[],int n,vector<vector<int>>&dp) {

    if(sum==0) {
        return 1;
    }
    if(ind>=n||sum<0) {
        return 0;
    }
    if(dp[ind][sum]!=-1){
        return dp[ind][sum];
    }

    int left = count(ind,sum-S[ind],S,n,dp);
    int right = count(ind+1,sum,S,n,dp);

    return dp[ind][sum] = left+right;
}


int main() {

    int S[] = {1,2};
    int sum = 4;
    int n =2;
    vector<vector<int>> dp(n,vector<int>(sum+1,-1));
    cout<<count(0,sum,S,n,dp);

    return 0;
}