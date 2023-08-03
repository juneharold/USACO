#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

struct Trie {
    map<string, Trie*> m;
    bool end;
    void insert(vector<string> &v, int idx) {
        if (v.size()==idx) return;
        if (m.find(v[idx])==m.end()) {
            Trie* trie = new Trie;
            m.insert({v[idx], trie});
        }
        m[v[idx]]->insert(v, idx+1);
    }
    void dfs(int d) {
        for (auto &x: m) {
            for (int j=0; j<d; j++) cout << ' ';
            cout << x.first << "\n";
            x.second->dfs(d+1);
        }
    }
};

int main()
{
    Trie* root=new Trie;
    int n; cin >> n;
    for (int i=0; i<n; i++) {
        string s; cin >> s;
        string temp="";
        vector<string> v;
        for (char c: s) {
            if (c==92) {
                v.push_back(temp);
                temp="";
            }
            else temp+=c;
        }
        v.push_back(temp);
        root->insert(v, 0);
    }
    root->dfs(0);
}
