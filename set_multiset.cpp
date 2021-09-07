#include<iostream>
#include<set>
using namespace std;


int main(){

    // set<int, greater<int>> s;
    // s.insert(1);
    // s.insert(2);
    // s.insert(2);
    // s.insert(3);

    // for(auto i: s){
    //     cout<<i<<" ";
    // }cout<<"\n";

    // cout<<s.size()<<"\n";

    // set<int> s1;
    // s1.insert(1);
    // s1.insert(2);
    // s1.insert(2);
    // s1.insert(3);

    // for(auto i = s1.begin();i!=s1.end();i++){
    //     cout<<*i<<" ";
    // }cout<<"\n";

    set<int> s2;
    s2.insert(1);
    s2.insert(3);
    s2.insert(5);

    cout<< *s2.lower_bound(2) <<"\n";
    cout<< *s2.lower_bound(3) <<"\n";
    cout<< *s2.upper_bound(3) <<"\n";
    cout<< (s2.upper_bound(5) == s2.end())<<"\n";

    // s.erase(1);
    // s.erase(s.begin());
    // for(auto i : s){
    //     cout<<i<<" ";
    // }
    return 0;
}