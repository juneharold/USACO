#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define f first
#define s second

vector<pair<int, int>> tree[100005];
int p[100005]={}, depth[100005]={}, dp[100005][20]={};
int mn[100005][20]={}, mx[100005][20]={};

void find_parent (int cur, int level) {
    depth[cur]=level;
    for (auto nx: tree[cur]) {
        if (depth[nx.f]==0) {
            dp[nx.f][0]=cur;
            mn[nx.f][0]=nx.s;
            mx[nx.f][0]=nx.s;
            find_parent(nx.f, level+1);
        }
    }
}

int LCA(int a, int b) {
    if (depth[a]<depth[b]) swap(a, b); //a가 더 깊음
    for (int i=17; i>=0; i--) {
        int nx=dp[a][i];
        if (depth[nx]>=depth[b]) a=nx;
    }
    if (a==b) return a;
    for (int i=17; i>=0; i--) {
        if (dp[a][i]!=dp[b][i]) {
            a=dp[a][i];
            b=dp[b][i];
        }
    }
    return dp[a][0];
}

void solve(int a, int b) {
    int mom=LCA(a, b), min1=1e9, min2=1e9, max1=0, max2=0;
    for (int i=17; i>=0; i--) {
        int nxa=dp[a][i], nxb=dp[b][i];
        if (depth[dp[a][i]]>=depth[mom]) {
            min1=min(min1, mn[a][i]);
            max1=max(max1, mx[a][i]);
            a=nxa;
        }
        if (depth[dp[b][i]]>=depth[mom]) {
            min2=min(min2, mn[b][i]);
            max2=max(max2, mx[b][i]);
            b=nxb;
        }
    }
    cout << min(min1, min2) << " " << max(max1, max2) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    for (int i=0; i<N-1; i++) {
        int a, b, c; cin >> a >> b >> c;
        tree[a].push_back({b, c});
        tree[b].push_back({a, c});
    }

    find_parent(1, 1);
    for (int j=1; j<=17; j++) {
        for (int i=1; i<=N; i++) {
            dp[i][j]=dp[dp[i][j-1]][j-1];
            mn[i][j]=min(mn[i][j-1], mn[dp[i][j-1]][j-1]);
            mx[i][j]=max(mx[i][j-1], mx[dp[i][j-1]][j-1]);
        }
    }

    int K; cin >> K;
    for (int i=0; i<K; i++) {
        int a, b; cin >> a >> b;
        solve(a, b);
    }
}
