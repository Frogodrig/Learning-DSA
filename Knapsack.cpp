#include<iostream>
using namespace std;

int knapsack(int v[],int w[], int n, int W)
{
    if(n==0 || W==0)
    {
        return 0;
    }
    if(w[n-1]>W)
    {
        return knapsack(v,w,n-1,W);
    }
    return max(knapsack(v,w,n-1,W-w[n-1])+v[n-1],knapsack(v,w,n-1,W));
}

int main()
{
    int wt[]={10,20,30};
    int value[]={100,50,150};
    int W=50;
    cout<<knapsack(value,wt,3,W);
    return 0;
}