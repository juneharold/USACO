#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define f first
#define s second
#define pii pair<int, int>

int dp[300005]={}, flies[300005]={}, from[300005]={}, xmax[100005]={}, ymax[100005]={};
pair<pii, int> leaf[300005];
bool cmp(pair<pii, int> a, pair<pii, int> b) {
    return a.s<b.s;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N, K; cin >> N >> K;
    for (int i=1; i<=N; i++) {
        cin >> leaf[i].f.f >> leaf[i].f.s >> flies[i];
        leaf[i].s=i;
    }

    sort(&leaf[1], &leaf[N+1]);
    fill(&dp[1], &dp[N+1], -1e9);
    dp[1]=flies[1];
    for (int i=1; i<=N; i++) {
        int x=leaf[i].f.f, y=leaf[i].f.s, cur=leaf[i].s;
        if (dp[xmax[x]]>=K && dp[xmax[x]]-K+flies[cur]>dp[cur]) {
            dp[cur]=dp[xmax[x]]-K+flies[cur];
            from[cur]=xmax[x];
        }
        if (dp[ymax[y]]>=K && dp[ymax[y]]-K+flies[cur]>dp[cur]) {
            dp[cur]=dp[ymax[y]]-K+flies[cur];
            from[cur]=ymax[y];
        }
        if (dp[cur]>dp[xmax[x]]) xmax[x]=cur;
        if (dp[cur]>dp[ymax[y]]) ymax[y]=cur;
    }

    sort(&leaf[1], &leaf[N+1], cmp);
    vector<pii> path;
    int cur=N;
    while (cur!=0) {
        path.push_back(leaf[cur].f);
        cur=from[cur];
    }
    cout << dp[N] << "\n" << path.size() << "\n";
    for (int i=path.size()-1; i>=0; i--) cout << path[i].f << ' ' << path[i].s << "\n";
}

/*
5 5
3 4 5
3 5 5
3 2 2
5 4 6
5 5 10
*/
