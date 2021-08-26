#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
    string s;
    cin>>s;
    vector<int> a(256,-1);
    int start = -1;
    int maxlen = 0;
    for(int i=0;i<s.size();i++){
        if(a[s[i]]>start){
            start = a[s[i]];
        }
        a[s[i]]=i;
        maxlen = max(maxlen,i-start);
    }
    cout<<maxlen;
    return 0;
}