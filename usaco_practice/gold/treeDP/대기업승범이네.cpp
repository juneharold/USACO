#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, dp[200005][2]={}, A[200005]={};
vector<int> child[200005];

void solve(int cur) {
    for (int nx: child[cur]) {
        solve(nx);
        dp[cur][0]+=max(dp[nx][0], dp[nx][1]);
    }
    for (int nx: child[cur]) {
        int temp=dp[cur][0]-max(dp[nx][0], dp[nx][1])+dp[nx][0]+A[nx]*A[cur];
        dp[cur][1]=max(dp[cur][1], temp);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    for (int i=2; i<=N; i++) {
        int sasu; cin >> sasu;
        child[sasu].push_back(i);
    }
    for (int i=1; i<=N; i++) cin >> A[i];

    solve(1);
    cout << max(dp[1][0], dp[1][1]);
}
