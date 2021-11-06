#include<iostream>
#include<vector>
#include<string>
#include<cstring>
using namespace std;

const int N = 1e3+7;

bool dp[N][N];


//Time Complexity: O(n^2)
//Space Complexity: O(n^2)

void printSubstr(int start, int end, string str) {

    for (int i = start; i <= end; i++) {
        cout << str[i];
    }
}

int longestPalSubstr(string str) {

    int n = str.size();

    int maxLength = 1;
 
    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
    }

    int start = 0;
    for(int i = 0;i<n-1;i++) {
        if(str[i] == str[i+1]) {
            dp[i][i+1] = true;
            start = i;
            maxLength = 2;
        }
    }

    for(int k = 3;k<=n;k++) {
        for(int i = 0;i<n-k+1;i++) {

            int j = i+k-1;

            if(str[i] == str[j] && dp[i+1][j-1]) {
                dp[i][j] = true;

                if(k>maxLength) {
                    start = i;
                    maxLength = k;
                }

            }
        }
    }

    cout<<"\nLongest palindrome substring is: ";
    printSubstr(start, start + maxLength - 1, str);
    cout<<"\n";
 
    return maxLength;       
}


int main() {

    memset(dp,false,sizeof(dp));

    string str = "aaaabbaa";
    cout<<"\nLength of Longest Pallindromic Subarray is : "<<longestPalSubstr(str);

    return 0;
}