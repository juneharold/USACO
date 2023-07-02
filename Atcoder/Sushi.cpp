#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int cnt[4]={};
double n, dp[301][301][301]={};

double solve(int i, int j, int k) {
    if (i<0 || j<0 || k<0) return 0;
    if (i==0 && j==0 && k==0) return 0;
    if (dp[i][j][k]>0) return dp[i][j][k];
    dp[i][j][k]=0;
    dp[i][j][k]+=i*(1+solve(i-1, j, k));
    dp[i][j][k]+=j*(1+solve(i+1, j-1, k));
    dp[i][j][k]+=k*(1+solve(i, j+1, k-1));
    dp[i][j][k]+=n-(i+j+k);
    double div=i+j+k;
    dp[i][j][k]/=div;
    return dp[i][j][k];
}

int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x; cin >> x;
        cnt[x]++;
    }
    fill(&dp[0][0][0], &dp[cnt[1]][cnt[2]][cnt[3]+1], -1.0);
    cout << fixed << setprecision(10) << solve(cnt[1], cnt[2], cnt[3]);
}
