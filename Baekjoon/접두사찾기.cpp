#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct Trie {
    Trie *ch[26];
    bool end;
    Trie() {
        end=false;
        for (int i=0; i<26; i++) ch[i]=NULL;
    }
    ~Trie() {
        for (int i=0; i<26; i++) if (ch[i]) delete ch[i];
    }
    void insert(const char *s) {
        if (!*s) {
            end=true;
            return;
        }
        int now=*s-'a';
        if (!ch[now]) ch[now]=new Trie;
        ch[now]->insert(s+1);
    }
    bool find(const char *s) {
        if (!*s) return true;
        if (end) return false;
        int now=*s-'a';
        if (!ch[now]) return false;
        return ch[now]->find(s+1);
    }
};

int main()
{
    Trie *root=new Trie;
    int n, m; cin >> n >> m;
    for (int i=0; i<n; i++) {
        string s; cin >> s;
        root->insert(&s[0]);
    }
    
    int ans=0;
    for (int i=0; i<m; i++) {
        string s; cin >> s;
        if (root->find(&s[0])) ans++;
    }
    cout << ans;
    delete root;
}