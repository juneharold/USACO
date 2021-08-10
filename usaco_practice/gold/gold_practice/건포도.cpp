#include <iostream>
#include <algorithm>
using namespace std;

const int MAX=60;
int N, M, r[MAX][MAX], dp[MAX][MAX][MAX][MAX]={}, pfs[MAX][MAX]={};

int solve(int x1, int y1, int x2, int y2) {
    if (dp[x1][y1][x2][y2]!=1e9) return dp[x1][y1][x2][y2];
    if (x1==x2 && y1==y2) return r[x1][y1];

    int cost=pfs[x2][y2]-pfs[x1-1][y2]-pfs[x2][y1-1]+pfs[x1-1][y1-1];
    for (int row=x1; row<x2; row++) {
        dp[x1][y1][x2][y2]=min(dp[x1][y1][x2][y2], solve(x1, y1, row, y2)+solve(row+1, y1, x2, y2)+cost);
    }

    for (int col=y1; col<y2; col++) {
        dp[x1][y1][x2][y2]=min(dp[x1][y1][x2][y2], solve(x1, y1, x2, col)+solve(x1, col+1, x2, y2)+cost);
    }

    return dp[x1][y1][x2][y2];
}

int main()
{
    cin >> N >> M;
    for (int i=1; i<=N; i++) for (int j=1; j<=M; j++) {
        cin >> r[i][j];
        pfs[i][j]=pfs[i-1][j]+pfs[i][j-1]-pfs[i-1][j-1]+r[i][j];
    }

    for (int i=0; i<=55; i++) for (int j=0; j<=55; j++) for (int k=0; k<=55; k++) for (int l=0; l<=55; l++) {
        dp[i][j][k][l]=1e9;
    }

    cout << solve(1, 1, N, M)-pfs[N][M];
}
