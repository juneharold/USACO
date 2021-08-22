#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define f first
#define s second
const int MAX_N=1e4+5, mod=10;
int N, A[MAX_N], B[MAX_N], dp[MAX_N][11]={};
pair<int, int> bef[MAX_N][11], path[MAX_N];

void track (int i, int j) {
    if (i==0) return;

    int x=bef[i][j].f, y=bef[i][j].s;
    if (y==j) {
        path[i]={1, -(dp[i][j]-dp[x][y])};
    }
    else {
        path[i]={2, dp[i][j]-dp[x][y]};
    }
    track(x, y);
}

int main()
{
    cin >> N;
    for (int i=1; i<=N; i++) {
        char a; cin >> a;
        A[i]=a-48;
    }
    for (int i=1; i<=N; i++) {
        char b; cin >> b;
        B[i]=b-48;
    }

    fill(&dp[0][0], &dp[MAX_N-1][11], 1e9);
    for (int j=0; j<=9; j++) dp[0][j]=j;

    for (int i=1; i<=N; i++) {
        for (int j=0; j<=9; j++) {
            int lcnt=(B[i]-j-A[i]+20)%10;
    		int rcnt=10-lcnt;
            if (dp[i-1][j]+rcnt<dp[i][j]) {
                dp[i][j]=dp[i-1][j]+rcnt;
                bef[i][j]={i-1, j};
            }
            if (dp[i-1][j]+lcnt<dp[i][(j+lcnt)%10]) {
                dp[i][(j+lcnt)%10]=dp[i-1][j]+lcnt;
                bef[i][(j+lcnt)%10]={i-1, j};
            }
        }
    }

    int ans=1e9, minPos;
    for (int j=0; j<=9; j++) if (dp[N][j]<ans){
        ans=dp[N][j];
        minPos=j;
    }
    cout << ans << "\n";

    track(N, minPos);

    for (int i=1; i<=N; i++) {
        if (path[i].s==0) continue;
        cout << i << " " << path[i].s << "\n";
    }
}
