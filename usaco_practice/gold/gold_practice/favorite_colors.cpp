#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <iomanip>
#include <bitset>
#include <numeric>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

vector<int> graph[nmax];
int leader[nmax];
queue<int> q;

int Find(int x) {
    if (leader[x]==x) return x;
    return leader[x]=Find(leader[x]);
}
void Union (int a, int b) {
    a=Find(a), b=Find(b);
    if (a==b) return;
    if (graph[a].size()>graph[b].size()) swap(a, b);
    leader[a]=b;
    graph[b].insert(graph[b].end(), graph[a].begin(), graph[a].end());
    graph[a].clear();
    if (graph[b].size()>1) q.push(b);
}

void solve() {
    int N, M; cin >> N >> M;
    for (int i=1; i<=M; i++) {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
    }

    for (int i=1; i<=N; i++) {
        leader[i]=i;
        if (graph[i].size()>1) q.push(i);
    }

    while (!q.empty()) {
        int cur=q.front(); 
        if (graph[cur].size()<2) {
            q.pop();
            continue;
        }
        int a=graph[cur].back(); graph[cur].pop_back();
        if (Find(a)!=Find(graph[cur].back())) Union(a, graph[cur].back());
    }

    int num=0;
    map<int, int> m;
    for (int i=1; i<=N; i++) {
        if (m.find(Find(i))!=m.end()) cout << m[Find(i)] << "\n";
        else {
            cout << ++num << "\n";
            m[Find(i)]=num;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; //cin >> T;
    while (T--) {
        solve();
    }
}
