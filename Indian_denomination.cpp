#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {

    int n;cin>>n;

    vector<int> a(n);
    for(auto i:a) {
        cin>>i;
    }

    int x;cin>>x;
    sort(a.begin(),a.end(),greater<int>());
    int ans = 0;

    for(int i=0;i<n;i++) {
        ans += x/a[i];
        x -= x/a[i] * a[i];
    }

    cout<<ans<<"\n";
    return 0;
}