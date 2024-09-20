#include <bits/stdc++.h>
using namespace std;





struct TRIE_NODE {
    TRIE_NODE* next[26];
    bool is_word;

    TRIE_NODE() { memset(next,nullptr,sizeof(next)); }
};

struct TRIE {
    TRIE_NODE* root;
    
    TRIE() : root(new TRIE_NODE()) {}

    void insert(const string& s) {
        TRIE_NODE* cur = root;
        each(c,s) {
            if(!cur->next[c-'a']) cur->next[c-'a'] = new TRIE_NODE();
            cur = cur->next[c-'a'];
        }
        cur->is_word = 1;
    }

    bool present(const string& s) {
        TRIE_NODE* cur = root;
        each(c,s) {
            if(!cur->next[c-'a']) return 0;
            cur = cur->next[c-'a'];
        }
        return cur->is_word;
    }
};