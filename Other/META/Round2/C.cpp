#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

void solve() {
    ll R, C, K; cin >> R >> C >> K;
    vector<vector<pii>> loc(R*C+1, vector<pii>());
    for (int i=1; i<=R; i++) {
        for (int j=1; j<=C; j++) {
            int B; cin >> B;
            loc[B].push_back({i, j});
        }
    }

    vector<int> score;
    for (int i=1; i<=R*C; i++) {
        for (int j=1; j<=R*C; j++) {
            if (i==j) continue;
            for (pii x: loc[i]) {
                for (pii y: loc[j]) {
                    score.push_back(max(abs(x.fs-y.fs), abs(x.sc-y.sc)));
                }
            }
        }
    }
    sort(score.begin(), score.end());
    //for (int x: score) cout << x<< endl;
    cout << score[K-1] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen("bunny_hopscotch_validation_input.txt", "r", stdin);
    freopen("Cout.txt", "w", stdout);
    int T=1; cin >> T;
    for (int t=1; t<=T; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
}
