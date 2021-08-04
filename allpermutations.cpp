#include<iostream>
using namespace std;
int ans[]={};   
void permutations(int a[],int idx)
{
    if(idx==a.size())
    {
        ans[int i]=a;
        i++
        return;
    }
    for(int i=0;i<a.size();i++)
    {
        swap(a[i],a[idx]);
        permutations(a,idx+1);
        swap(a[i],a[idx]);
    }
    return;
}

int main()
{
    int n;cin>>n;
    int a[n];
    for(auto &i : a)
        cin>>i; 
    permutations(a,0);    
    for(auto v : ans){
        for(auto i : a)
            cout<<i<<" ";
        cout<<"\n";
    }
    return 0;
}