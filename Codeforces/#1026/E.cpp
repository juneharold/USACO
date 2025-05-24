#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=4e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

vector<pii> graph[nmax];
int v[nmax]={}, p[nmax]={}, idx[nmax]={}, used[nmax]={};
map<int, int> mv, mp;

vector<int> circuit;
stack<int> st;
void dfs(int cur) {
    st.push(cur);
    while (true) {
        while (idx[cur]<graph[cur].size() && used[graph[cur][idx[cur]].sc]) {
            idx[cur]++;
        }
        if (idx[cur]==graph[cur].size()) break;
        auto [u, id]=graph[cur][idx[cur]++];
        used[id]=1;
        dfs(u);
    }
    circuit.push_back(st.top());
    st.pop();
}

void solve() {
    int n; cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> v[i] >> p[i];
        mv[v[i]]=1;
        mp[p[i]]=1;
    }
    int new_idx=0;
    for (auto x: mv) {
        mv[x.fs]=++new_idx;
    }
    for (auto x: mp) {
        mp[x.fs]=++new_idx;
    }
    map<pii, int> find_edge;
    int id=1;
    for (int i=1; i<=n; i++) {
        v[i]=mv[v[i]];
        p[i]=mp[p[i]];
        graph[v[i]].push_back({p[i], id});
        graph[p[i]].push_back({v[i], id});
        id++;
        find_edge[make_pair(v[i], p[i])]=i;
        find_edge[make_pair(p[i], v[i])]=i;
    }

    vector<int> odd_degree;
    for (int i=1; i<=new_idx; i++) {
        if (graph[i].size()%2==1) odd_degree.push_back(i);
    }

    if (odd_degree.size()==2) { // euler path
        int u=*odd_degree.begin();
        dfs(u);
        vector<int> ans;
        for (int i=1; i<circuit.size(); i++) {
            pii pr=make_pair(circuit[i], circuit[i-1]);
            ans.push_back(find_edge[pr]);
        }
        if (ans.size()==n) {
            cout << "YES\n";
            for (int x: ans) cout << x << ' ';
            cout << "\n";
        }
        else cout << "NO\n";
    }
    else if (odd_degree.size()==0) { // euler circuit
        dfs(1);
        vector<int> ans;
        for (int i=1; i<circuit.size(); i++) {
            pii pr=make_pair(circuit[i], circuit[i-1]);
            ans.push_back(find_edge[pr]);
        }
        if (ans.size()==n) {
            cout << "YES\n";
            for (int x: ans) cout << x << ' ';
            cout << "\n";
        }
        else cout << "NO\n";
    }
    else cout << "NO\n";

    for (int i=1; i<=2*n; i++) {
        graph[i].clear();
        v[i]=0;
        p[i]=0;
        idx[i]=0;
        used[i]=0;
    }
    mv.clear();
    mp.clear();
    circuit.clear();
    while (!st.empty()) {
        st.pop();
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
