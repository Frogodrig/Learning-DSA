#include <iostream>

using namespace std;


void Prime(int n)
{
    int prime[100]={0};
    
        for(int i=2;i<=n;i++)
        {
            if(prime[i]==0)
            {
                for(int j=i*i;j<=n;j+=i)
                {
                    prime[j]=1;
                }
            }
        }
        
        cout<<"Prime numbers ranging from 2 to "<<n<<" are : "<<endl;
        for(int i=2;i<=n;i++)
        {
            if(prime[i]==0)
            {
                cout<<i<<" ";
            }
        }cout<<endl;
}

void primefactor(int n)
{
    int spf[100]={0};
    
        for(int i=2;i<=n;i++)
        {
            spf[i]=i;
        }
        
        for(int i=2;i<=n;i++)
        {
            if(spf[i]==i)
            {
                for(int j=i*i;j<=n;j+=i)
                {
                    if(spf[j]==j)
                    {
                        spf[j]=i;
                    }
                }
            }
        }
        
        cout<<"All prime factors of "<<n<<" are : "<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<spf[n]<<" ";
            n=n/spf[n];
        }
}

int main()
{
    int n;
    cin>>n;
    
    Prime(n);
    primefactor(n);
    return 0;
}


