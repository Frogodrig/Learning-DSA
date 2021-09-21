#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
using namespace std;

int main() {

    vector<string> votes = {'john','johnny','jackie','johnny','john','jackie','jamie','jamie','john','johnny','jamie','johnny','john'};

    unordered_map<string, int> umap;
    for(int i=0;i<votes.size();i++) {
        umap[votes[i]]++;
    }

    unordered_map<string,int> :: iterator it;

    string name = "";
    int max_vote = 0;
    for(it=umap.begin();it!=umap.end();it++) {
        string key = it->first;
        int val = it->second;

        if(val > max_vote) {
            max_vote = val;
            name = key;
        }

        else if(val == max_vote) {
            if(key<name) {
                name = key;
            }
        }
    }

    cout<<name<<" "<<max_vote<<"\n";

    return 0;
}
