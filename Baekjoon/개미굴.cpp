#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct Trie {
    map<string, Trie*> m;
    void insert(vector<string> &v, int idx) {
        if (idx==v.size()) return;
        if (m.find(v[idx])==m.end()) {
            Trie *trie = new Trie;
            m.insert({v[idx], trie});
        }
        m[v[idx]]->insert(v, idx+1);
    }
    void dfs(int d) {
        for (auto &i: m) {
            for (int j=0; j<d; j++) cout << "--";
            cout << i.first << "\n";
            i.second->dfs(d+1);
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    Trie *root = new Trie;
    for (int i=0; i<n; i++) {
        int k; cin >> k;
        vector<string> v(k);
        for (int j=0; j<k; j++) cin >> v[j];
        root->insert(v, 0);
    }
    root->dfs(0);
    return 0;
}
