#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

int dp[2005][2005]={}, sound[2005];

int dist(int a, int b) {
    if (b==0) return 0;
    return abs(sound[a]-sound[b]);
}

int main()
{
    int N; cin >> N;
    for (int i=1; i<=N; i++) cin >> sound[i];

    fill(&dp[0][0], &dp[N+1][N+1], 1e9);
    dp[0][0]=0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            int nx=max(i, j)+1;
            dp[i][nx]=min(dp[i][nx], dp[i][j]+dist(nx, j));
            dp[nx][j]=min(dp[nx][j], dp[i][j]+dist(nx, i));
        }
    }
    
    int ans=1e9;
    for (int i=0; i<N; i++) ans=min(ans, dp[i][N]);
    for (int j=0; j<N; j++) ans=min(ans, dp[N][j]);
    cout << ans;
}
