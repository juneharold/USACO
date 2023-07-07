#include <iostream>
#include <algorithm>
using namespace std;

int H, W, N, a[1005][1005]={}, dp[1005][1005][2]={};
int b[1005][1005]={};

int solve(int i, int j, int dir) {
    if (dp[i][j][dir]!=-1) return dp[i][j][dir];
    int k=0;
    if (0<i-1) k+=solve(i-1, j, 1);
    if (0<j-1) k+=solve(i, j-1, 0);

    if (k%2==0) dp[i][j][dir]=k/2;
    else {
        dp[i][j][dir]=k/2;
        if (a[i][j]==1 && dir==0) dp[i][j][dir]++;
        if (a[i][j]==0 && dir==1) dp[i][j][dir]++;
    }
    return dp[i][j][dir];
}

int main() 
{
    cin >> H >> W >> N;
    for (int i=1; i<=H; i++) for (int j=1; j<=W; j++) cin >> a[i][j];
    
    fill(&dp[0][0][0], &dp[H][W][2], -1);
    dp[1][1][0]=N/2, dp[1][1][1]=N/2;
    if (N%2 && a[1][1]) dp[1][1][0]++;
    if (N%2 && !a[1][1]) dp[1][1][1]++;
    for (int i=1; i<=H; i++) for (int j=1; j<=W; j++) {
        int cnt=solve(i, j, 0)+solve(i, j, 1);
        if (cnt%2) b[i][j]=a[i][j];
        else b[i][j]=(a[i][j]+1)%2;
    }

    int x=1, y=1; 
    while (x<=H && y<=W) {
        if (b[x][y]) y++;
        else x++;
    }
    cout << x << ' ' << y;
}