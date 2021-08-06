#include<iostream>
using namespace std;

bool issafe(int** arr,int x, int y, int n)
{
    if(x<n && y<n && arr[x][y]==1)
    {
        return true;
    }
    return false;
}

bool ratinmaze(int** arr,int x,int y,int n,int** ans)
{
    if(x==n-1 && y==n-1)
    {
        ans[x][y]=1;
        return true;
    }

    if(issafe(arr,x,y,n))
    {
        ans[x][y]=1;
        if(ratinmaze(arr,x+1,y,n,ans))
        {
            return true;
        }
        if(ratinmaze(arr,x,y+1,n,ans))
        {
            return true;
        }
        ans[x][y]=0;
        return false;
    }
    return false;
}

int main()
{
    int n;
    cin>>n;

    int** arr=new int*[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=new int[n];
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }

    int** ans=new int*[n];
    for(int i=0;i<n;i++)
    {
        ans[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            ans[i][j]=0;
        }
    }

    if(ratinmaze(arr,0,0,n,ans))
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}