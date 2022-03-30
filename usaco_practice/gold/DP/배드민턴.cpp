#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define f first
#define s second

long long N, dp[100005][4]={};
pair<long long, long long> skill[100005]={}, path[100005][4]={};
vector<long long> ans;

void find_path(long long cur, long long state) {
    long long bef=path[cur][state].f, ns=path[cur][state].s;
    if (ns<state) ans.push_back(skill[cur].s);
    if (bef==0) return;
    find_path(bef, ns);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    for (long long i=1; i<=N; i++) {
        cin >> skill[i].f;
        skill[i].s=i-1;
    }
    sort(&skill[1], &skill[N+1]);

    for (long long i=4; i<=N; i++) {
        dp[i][0]=dp[i-4][0]+skill[i].f-skill[i-3].f;
        path[i][0]={i-4, 0};

        for (long long j=1; j<4; j++) {
            dp[i][j]=dp[i-4][j]+skill[i].f-skill[i-3].f;
            path[i][j]={i-4, j};
            if (dp[i-1][j-1]<=dp[i][j]) {
                dp[i][j]=dp[i-1][j-1];
                path[i][j]={i-1, j-1};
            }
        }
    }
    find_path(N, N%4);
    cout << dp[N][N%4] << "\n";
    sort(ans.begin(), ans.end());
    for (long long x: ans) cout << x << "\n";
}
