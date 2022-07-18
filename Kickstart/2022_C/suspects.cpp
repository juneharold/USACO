#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
using namespace std;
#define ll long long
#define f first
#define s second
#define pii pair<ll, ll>

int N, M, K, possible[100005]={}, cnt[100005]={};
vector<int> graph[100005];
set<int> dp[100005]={};

set<int> dfs(int cur) {
    if (dp[cur].size()!=0 && possible[cur]!=-1) return dp[cur];
    dp[cur].insert(cur); //본인 포함
    possible[cur]=0;

    bool poss=true;
    for (int nx: graph[cur]) {
        set<int> s=dfs(nx);
        if (possible[nx]==0) poss=false;
        if (s.size()<=K && dp[cur].size()<=K) {
            for (int x: s) dp[cur].insert(x);
        }
        else poss=false;
        if (dp[cur].size()>K) poss=false;
    }

    if (poss) {
        possible[cur]=1;
        for (int x: dp[cur]) {
            cnt[x]++;
        }
    }

    return dp[cur];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    for (int t=1; t<=T; t++) {
        cin >> N >> M >> K;
        for (int i=1; i<=M; i++) {
            int a, b; cin >> a >> b;
            graph[b].push_back(a);
        }

        fill(&possible[0], &possible[N+1], -1);

        for (int i=1; i<=N; i++) {
            if (dp[i].size()==0 || possible[i]==-1) dfs(i);
        }

        int ans=N;
        for (int i=1; i<=N; i++) if (cnt[i]!=0) ans--;
        cout << "Case #" << t << ": " << ans << "\n";

        for (int i=1; i<=100000; i++) {
            graph[i].clear();
            dp[i].clear();
            cnt[i]=0;
            possible[i]=0;
        }
    }
}

/*
1
20 18 5
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
13 19
19 13
1 20
5 4
9 4
9 6
8 16
16 17
18 19
19 16
*/
