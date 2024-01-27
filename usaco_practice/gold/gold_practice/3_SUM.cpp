#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
const int nmax=5e3+5, mil=1e6;

int A[nmax]={}, comp[2000005]={};

void solve() {
    int N, Q; cin >> N >> Q;
    vector<int> b;
    for (int i=1; i<=N; i++) {
        cin >> A[i];
        b.push_back(A[i]);
    }
    sort(b.begin(), b.end());
    int num=0;
    for (int x: b) if (comp[x+mil]==0) comp[x+mil]=++num;

    vector<vector<ll>> dp(N+5, vector<ll>(N+5));

    for (int i=N; i>=1; i--) {
        vector<int> pfs(num+1);
        for (int j=i+1; j<=N; j++) {
            int target=-(A[i]+A[j])+mil;
            if (j-i>1 && 0<=target && target<=2*mil && comp[target]>0) dp[i][j]+=pfs[comp[target]];
            pfs[comp[A[j]+mil]]++;
        }
    }

    for (int i=N; i>=1; i--) {
        for (int j=i+2; j<=N; j++) {
            dp[i][j]+=dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1];
        }
    }

    while (Q--) {
        int a, b; cin >> a >> b;
        cout << dp[a][b] << "\n";
    }
}

int main()
{
    freopen("threesum.in", "r", stdin);
    freopen("threesum.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; //cin >> T;
    while (T--) {
        solve();
    }
}
