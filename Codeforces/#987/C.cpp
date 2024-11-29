#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

void solve() {
    int n; cin >> n;
    if (n%2==0) {
        for (int i=1; i<=n; i++) cout << (i+1)/2 << ' ';
        cout << "\n";
    }
    else {
        if (n<27) cout << "-1\n";
        else {
            vector<int> ans(n+1, 0);
            ans[1]=1, ans[10]=1, ans[26]=1;
            ans[23]=2, ans[27]=2;
            int cur=3, cnt=0;
            for (int i=1; i<=n; i++) {
                if (ans[i]==0) {
                    cnt++;
                    ans[i]=cur;
                    if (cnt==2) {
                        cur++;
                        cnt=0;
                    }
                }
            }
            for (int i=1; i<=n; i++) cout << ans[i] << ' ';
            cout << "\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
