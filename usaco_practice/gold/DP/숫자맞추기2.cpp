#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define f first
#define s second
const int MAX_N=1e4+5, mod=10;
int N, A[MAX_N], B[MAX_N], dp[MAX_N][11]={};
pair<int, int> path[MAX_N];

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
    		dp[i][j]=min(dp[i][j], dp[i-1][j]+rcnt);
    		dp[i][(j+lcnt)%10] = min(dp[i][(j+lcnt)%10], dp[i-1][j]+lcnt);
        }
    }

    int ans=1e9;
    for (int j=0; j<=9; j++) ans=min(ans, dp[N][j]);
    cout << ans << "\n";

    for (int i=1; i<=N; i++) {
        if (path[i].s==0) continue;
        cout << i << " ";
        if (path[i].f==1) cout << -1*path[i].s << "\n";
        else cout << path[i].s << "\n";
    }
}
/*
3
326
446

3
112
113
*/
