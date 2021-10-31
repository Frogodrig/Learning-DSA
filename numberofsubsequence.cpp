#include<iostream>
#include<vector>
#include<string>
using namespace std;


int main() {

    int n;cin>>n;

    string s;cin>>s;

    int e = 1, a =0, ab = 0, abc = 0;

    for(int i=0;i<n;i++) {

        if(s[i] == 'a') {

            a = a + e;
        }
        if(s[i] == 'b') {

            ab = ab + a;
        }
        if(s[i] == 'c') {

            abc = abc + ab;
        }
        if(s[i] == '?') {

            abc = 3*abc + ab;
            ab = 3*ab + a;
            a = 3*a + e;
        }
    }

    cout<<abc<<endl;

    return 0;
}