#include<iostream>
using namespace std;

int friendspairing(int n)
{
    if(n==0 || n==1 || n==2)
    {
        return n;
    }

    return friendspairing(n-1) + friendspairing(n-2)*(n-1);
}

int main()
{
    cout<<friendspairing(4);
    return 0;
}


//  1  2  3  4
//  1 decides to stay single -->  f(n-1) --> recursion for rest of the people
//  1 decides to pair up with someone --> f(n-2) --> recursion for the rest of the people, but there are also (n-1) ways to pair 1 with anyone
//  hence (n-2)*(n-1)