#include <iostream>
#include <vector>
using namespace std;

const int MAX=2e5+5;
int N, Q, dp[MAX][25]={};

int query(int n, int x) {
    int idx=x;
    for (int i=24; i>=0; i--) {
        if (n&(1<<i)) idx=dp[idx][i];
    }
    return idx;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i=1; i<=N; i++) cin >> dp[i][0];

    for (int j=1; j<=24; j++) for (int i=1; i<=N; i++) {
        dp[i][j]=dp[dp[i][j-1]][j-1];
    }

    cin >> Q;
    for (int i=0; i<Q; i++) {
        int n, x; cin >> n >> x;
        cout << query(n, x) << "\n";
    }
}
/*
5
3 3 5 4 3
5
1 1
2 1
11 3
1000 4
5 1
*/
