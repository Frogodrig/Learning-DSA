#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Node {

    public:
        Node* next[26];
        bool end;
        int prefixcount;

        Node() {
            for(int i = 0;i<25;i++) {
                next[i] = NULL;
            }
            end = false;
            prefixcount = 0;
        }
};

class Trie {

    private:
        Node* root;

    public: 
        Trie() {
            root = new Node();
        }

        void insert(string &s) {

            Node* it = root;

            for(auto c: s) {
                if(!it->next[c-'a']) {
                    it->next[c-'a'] = new Node();
                }
                it->next[c-'a']->prefixcount += 1;
                it = it->next[c-'a'];
            }
            it->end = true;
        }

        int prefix(string &s) {

            Node* it = root;

            for(auto c : s) {

                if(!it->next[c -'a']) {
                    cout<<"No words found \n";
                    return 0;
                } 
                it = it->next[c-'a'];
            }

            cout<<"Words found starting with "<<s<<" : ";
            return it->prefixcount;
            
        }

};


int main() {

    Trie t;
    int n;cin>>n;
    vector<string> a(n);
    for(auto &i : a) {
        cin>>i;
        t.insert(i);
    }
    int q;cin>>q;
    while(q--) {
        string s;cin>>s;
        cout<<t.prefix(s)<<"\n";
    }
    return 0;

}