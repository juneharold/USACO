#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long
const int MAX_N=1e6+5;
ll N, dp[MAX_N]={}, K;
vector<int> graph[MAX_N], factors;

ll dfs (int cur, int p) {
    if (dp[cur]!=-1) return dp[cur];
    ll ret=1;

    for (int i=0; i<graph[cur].size(); i++) {
        int nx=graph[cur][i];
        if (nx==p) continue;
        ll t=dfs(nx, cur);
        if (t==-1) return -1;

        ret+=t;
    }
    if (ret>K) return -1;
    return dp[cur]=ret%K;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i=1; i<=N-1; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i=2; i<=N; i++) {
        if (N%i==0) factors.push_back(i);
    }


    for (int i=2; i<=N; i++) {
        if (N%i==0) {
            for (int j=0; j<=N; j++) dp[j]=-1;
            K=i;
            if (dfs(1, 0)==0) cout << i-1 << " ";
        }
    }

}
