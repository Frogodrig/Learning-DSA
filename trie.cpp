#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Trie {
    public: 
        class Node {
            public:    
                char data;
                bool end;
                Node *next[26];
                Node() {
                    end = false;
                    for(int i=0;i<26;i++) {
                        next[i] = NULL;
                    }
                }
        };
    Node* trie;
    Trie() {
        trie = new Node();
    }    

    void insert(string word) {
        int i = 0;
        Node* it = trie;
        while(i < word.size()) {
            if(it->next[word[i]-'a'] == NULL) {
                it->next[word[i]-'a'] = new Node();
            }
            it = it->next[word[i]-'a'];
            i++;
        }
        it->end = true;
    }

    bool search(string word) {
        int i =0;
        Node* it = trie;
        while(i<word.size()) {
            if(it->next[word[i]-'a'] == NULL) {
                return false;
            }
            it = it->next[word[i]-'a'];
            i++;
        }
        return it->end;
    }
        
};

int main() {

    Trie *myTrie = new Trie();
    vector<string> words = {"Hello", "world"};
    for(auto w: words) {
        myTrie->insert(w);
    }
    if(myTrie->search("cyber")) {
        cout<<"cyber found \n";
    } else {
        cout<<"cyber doesn't exist \n";
    }
    return 0;
}