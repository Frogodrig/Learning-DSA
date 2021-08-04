#include<iostream>
using namespace std;

void replacePi(string a)
{
    if(a.length()==0)
    {
        return;
    }

    if(a[0]=='p' && a[1]=='i')
    {
        cout<<"3.14";
        replacePi(a.substr(2));
    }

    else
    {
        cout<<a[0];
        replacePi(a.substr(1));
    }

}

int main()
{
    replacePi("pixxbsbcapiasdbpizxcapi");
    return 0;
}