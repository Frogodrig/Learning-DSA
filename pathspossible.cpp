#include<iostream>
using namespace std;


int pathspossible(int s,int e)
{
    if(s==e)
    {
        return 1;
    }

    if(s>e)
    {
        return 0;
    }
    int count=0;
    for(int i=1;i<=6;i++)
    {
        count+=pathspossible(s+i,e);
    }

    return count;
}

int main()
{
    cout<<pathspossible(0,3);
    return 0;
}