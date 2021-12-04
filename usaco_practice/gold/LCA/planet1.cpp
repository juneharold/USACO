#include <iostream>
#include <vector>
using namespace std;

const int MAX=2e5+5;
int N, Q, dp[MAX][32]={};

int solve (int x, int k) {
    for (int i=30; i>=0; i--) {
        int nx=dp[x][i];
        if (k&(1<<i)) x=nx;
    }
    return x;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> Q;
    for (int i=1; i<=N; i++) {
        int p; cin >> p;
        dp[i][0]=p;
    }

    for (int j=1; j<=30; j++) for (int i=1; i<=N; i++) {
        dp[i][j]=dp[dp[i][j-1]][j-1];
    }

    for (int i=1; i<=Q; i++) {
        int a, b; cin >> a >> b;
        cout << solve(a, b) << "\n";
    }
}

/*
tc
10 10
2 3 4 5 6 7 8 9 10 1
2 10
6 5
6 6
3 7
3 1
9 6
9 8
7 9
1 10
6 6

ans
2
1
2
10
4
5
7
6
1
2
*/
