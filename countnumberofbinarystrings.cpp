// Given a positive integer N, count all possible distince binary strings of length N such that there are no consecutive ones

#include<iostream>
#include<vector>
using namespace std;

int main() {

    int n;cin>>n;
    vector<int> fib(n+2, 0);
    fib[0] = 1;
    fib[1] = 1;
    
    for(int i=2;i<=n;i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    cout<<fib[n+1];
    return 0;
}