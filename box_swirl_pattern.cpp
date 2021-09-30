#include<iostream>
using namespace std;

int main() 
{

    int n;
    cin>>n;
  	int len=2*n-1;
    for(int i=0;i<len;i++)
    {
        for(int j=0;j<len;j++)
        {
           int min1 = i<j ? i:j;
           int min2 = len-i<len-j ? len-i-1:len-j-1;  
           int min = min1<min2 ? min1:min2;
           cout<<(n-min);
        }
        cout<<"\n";
    }
    return 0;
}
