#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

void solve() {
    int n; cin >> n;
    vector<int> a(n+1);
    for (int i=1; i<=n; i++) cin >> a[i];

    vector<int> mark(n+5, 0);
    int mn0=-1, mx0=-1;
    for (int i=1; i<=n; i++) {
        if (a[i]==0) {
            if (mn0==-1) mn0=i;
            mx0=i;
        }
        else {
            int start=min(a[i], i), end=max(a[i], i);
            if (start!=end) {
                mark[start]++;
                mark[end+1]--;
            }
        }
    }
    if (mn0!=mx0) {
        mark[mn0]++;
        mark[mx0+1]--;
    }

    int sum=0, left=-1, right=-1;
    for (int i=1; i<=n; i++) {
        sum+=mark[i];
        if (sum>0) {
            if (left==-1) left=i;
            right=i;
        }
    }
    if (left==-1) cout << "0\n";
    else cout << right-left+1 << "\n";

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
