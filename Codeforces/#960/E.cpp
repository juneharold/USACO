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
const ll nmax=5e3+5, sqrmax=635, MOD=1e9+7, INF=1e18;

vector<int> graph[nmax], path;
int p[nmax]={}, del[nmax]={}, maxdepth[nmax]={}, depth[nmax]={}, leaf=-1;
bool deleteNode;

void dfs(int cur, int parent) {
    p[cur]=parent;
    for (int nx: graph[cur]) {
        if (nx==parent || del[nx]) continue;
        depth[nx]=depth[cur]+1;
        maxdepth[nx]=depth[cur]+1;
        dfs(nx, cur);
        maxdepth[cur]=max(maxdepth[cur], maxdepth[nx]);
    }
    if (deleteNode) del[cur]=1;
    if (graph[cur].size()==1 && graph[cur][0]==p[cur] && leaf==-1) leaf=cur;
}

bool found=false;
void find_path(int cur, int parent, int target) {
    path.push_back(cur);
    if (cur==target) {
        found=true;
        return;
    }
    for (int nx: graph[cur]) {
        if (nx==parent || del[nx]) continue;
        find_path(nx, cur, target);
        if (found) return;
    }
    path.pop_back();
}

void init(int n) {
    fill(&p[0], &p[n+1], 0);
    fill(&maxdepth[0], &maxdepth[n+1], 0);
    fill(&depth[0], &depth[n+1], 0);
}

void init2(int n) {
    init(n);
    for (int i=1; i<=n; i++) graph[i].clear();
    fill(&del[0], &del[n+1], 0);
    deleteNode=false;
    leaf=-1;
}

int res;
void query(int x) {
    cout << "? " << x << "\n"; cout.flush();
    cin >> res;
}

int t=0;

void solve() {
    t++;
    int n, u, v; cin >> n;
    for (int i=1; i<=n-1; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i=1; i<=100; i++) {
        init(n);
        dfs(1, 0);
        u=-1;
        for (int j=1; j<=n; j++) {
            if (del[j]) continue;
            if (maxdepth[j]-depth[j]+1<=50 && (u==-1 || maxdepth[j]-depth[j]>=maxdepth[u]-depth[u])) u=j;
        }
        if (u!=-1) {
            query(u);
            if (res==1) {
                for (int j=1; j<=maxdepth[u]-depth[u]; j++) {
                    query(leaf);
                    if (res==1) {
                        cout << "! " << leaf << "\n"; cout.flush();
                        init2(n);
                        return;
                    }
                }
                path.clear();
                found=false;
                find_path(1, 0, u);
                int lo=0, hi=(int)path.size()-1;
                while (lo<hi) {
                    int mid=(lo+hi+1)/2;
                    query(path[mid]);
                    if (res==1) lo=mid;
                    else hi=max(0, mid-2), lo=max(0, lo-1);
                }
                cout << "! " << path[lo] << "\n"; cout.flush();
                init2(n);
                return;
            }
            else {
                deleteNode=true;
                dfs(u, p[u]);
                deleteNode=false;
            }
        }
    }
    cout << "! 1\n"; cout.flush();
    init2(n);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
