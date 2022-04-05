#include <iostream>
#include <algorithm>
using namespace std;

int N, dp[35][15005]={}, w[2005];

void solve(int i, int wt) {
    if (i>N || wt>15000 || dp[i][wt]) return;
    dp[i][wt]=1;
    solve(i+1, wt+w[i]);
    solve(i+1, abs(wt-w[i]));
    solve(i+1, wt);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    for (int i=0; i<N; i++) cin >> w[i];

    solve(0, 0);

    int Q; cin >> Q;
    for (int i=0; i<Q; i++) {
        int x; cin >> x;
        if (dp[N][x]) cout << "Y ";
        else cout << "N ";
    }
}
