#include <iostream>
#include <algorithm>
using namespace std;

int N, dp[(1<<20)]={}, cost[20][20]={}, cnt=0;

void solve(int person, int cur) {
    if (person==N) return;

    for (int i=0; i<N; i++) {
        if (cur&(1<<i)) continue;
        int nx=cur|(1<<i), w=dp[cur]+cost[person][i];
        if (w<dp[nx]) {
            dp[nx]=w;
            solve(person+1, nx);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> N;
    for (int i=0; i<N; i++) for (int j=0; j<N; j++) cin >> cost[i][j];

    fill(&dp[1], &dp[(1<<N)], 2e9);
    solve(0, 0);
    cout << dp[(1<<N)-1];
}

/*
4
2 3 3 4
3 2 3 4
3 3 2 4
3 3 2 4
18번

20
2 3 3 4 5 5 5 5 5 5 2 3 3 4 5 5 5 5 5 5
2 3 3 4 5 5 5 5 5 5 2 3 3 4 5 5 5 5 5 5
2 3 3 4 5 5 5 5 5 5 2 3 3 4 5 5 5 5 5 5
2 3 3 4 5 5 5 5 5 5 2 3 3 4 5 5 5 5 5 5
2 3 3 4 5 5 5 5 5 5 2 3 3 4 5 5 5 5 5 5
2 3 3 4 5 5 5 5 5 5 2 3 3 4 5 5 5 5 5 5
2 3 3 4 5 5 5 5 5 5 2 3 3 4 5 5 5 5 5 5
2 3 3 4 5 5 5 5 5 5 2 3 3 4 5 5 5 5 5 5
2 3 3 4 5 5 5 5 5 5 2 3 3 4 5 5 5 5 5 5
2 3 3 4 5 5 5 5 5 5 2 3 3 4 5 5 5 5 5 5
2 3 3 4 5 5 5 5 5 5 2 3 3 4 5 5 5 5 5 5
2 3 3 4 5 5 5 5 5 5 2 3 3 4 5 5 5 5 5 5
2 3 3 4 5 5 5 5 5 5 2 3 3 4 5 5 5 5 5 5
2 3 3 4 5 5 5 5 5 5 2 3 3 4 5 5 5 5 5 5
2 3 3 4 5 5 5 5 5 5 2 3 3 4 5 5 5 5 5 5
2 3 3 4 5 5 5 5 5 5 2 3 3 4 5 5 5 5 5 5
2 3 3 4 5 5 5 5 5 5 2 3 3 4 5 5 5 5 5 5
2 3 3 4 5 5 5 5 5 5 2 3 3 4 5 5 5 5 5 5
2 3 3 4 5 5 5 5 5 5 2 3 3 4 5 5 5 5 5 5
2 3 3 4 5 5 5 5 5 5 2 3 3 4 5 5 5 5 5 5
*/
