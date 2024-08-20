#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <iomanip>
#include <bitset>
#include <numeric>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

int D[305][305]={};

void solve() {
    int n; cin >> n;
    for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) cin >> D[i][j];

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            for (int k=1; k<=n; k++) {
                if (D[i][k]+D[k][j]<D[i][j]) {
                    cout << "-1";
                    return;
                }
            }
        }
    }

    set<pair<int, pii>> edges;
    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            edges.insert({D[i][j], {i, j}});
        }
    }
    set<pair<int, pii>> to_erase;
    for (auto e: edges) {
        int i=e.sc.fs, j=e.sc.sc, d=e.fs;
        for (int k=1; k<=n; k++) {
            if (i==k || j==k) continue;
            if (D[i][k]+D[k][j]==d) to_erase.insert({d, {i, j}});
        }
    }
    for (auto e: to_erase) edges.erase(e);

    cout << edges.size() << "\n";
    for (auto e: edges) cout << e.sc.fs << ' ' << e.sc.sc << ' ' << e.fs << "\n";
}
/*
5
0 1 1 3 2
1 0 2 3 3
1 2 0 2 3
3 3 2 0 5
2 3 3 5 0

5
0 1 1 1 1 
1 0 2 2 2
1 2 0 2 2
1 2 2 0 2
1 2 2 2 0

5
0 2 1 1 1 
2 0 1 3 3
1 1 0 2 2
1 3 2 0 2
1 3 2 2 0
*/

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; //cin >> T;
    while (T--) {
        solve();
    }
}
