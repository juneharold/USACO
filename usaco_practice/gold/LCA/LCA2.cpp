#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dp[100001][21]={}, p[100001]={}, depth[100001];
vector<int> tree[100001];

void find_parent(int cur, int parent, int d) {
    depth[cur]=d;
    for (int nx: tree[cur]) {
        if (nx==parent) continue;
        p[nx]=cur;
        find_parent(nx, cur, d+1);
    }
}

int LCA(int a, int b) {
    if (depth[b]>depth[a]) swap(a, b);
    for (int i=20; i>=0; i--) {
        int nx=dp[a][i];
        if (depth[nx]>=depth[b]) a=nx;
    }
    if (a==b) return a;

    for (int i=20; i>=0; i--) {
        if (dp[a][i]==0 || dp[b][i]==0) continue;
        if (dp[a][i]!=dp[b][i]) {
            a=dp[a][i];
            b=dp[b][i];
        }
    }
    return dp[a][0];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    for (int i=0; i<N-1; i++) {
        int a, b; cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    find_parent(1, 0, 1);

    for (int i=1; i<=N; i++) dp[i][0]=p[i];
    for (int j=1; j<=20; j++) {
        for (int i=1; i<=N; i++) dp[i][j]=dp[dp[i][j-1]][j-1];
    }

    int M; cin >> M;
    for (int i=0; i<M; i++) {
        int a, b; cin >> a >> b;
        cout << LCA(a, b) << "\n";
    }
}
