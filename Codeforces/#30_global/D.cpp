#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

void solve() {
    int n, k; cin >> n >> k;
    string a, b; cin >> a >> b;

    if (a==b) {
        cout << "0\n";
        return;
    }
    
    vector<string> ans;

    for (int kk=1; kk<=k; kk++) {
        int idx=n-1;

        vector<int> move(n+1, -1);
        for (int i=n-1; i>=0; i--) {
            idx=min(idx, i);
            while (idx>=0 && a[idx]!=b[i]) {
                idx--;
            }
            if (idx<0) {
                cout << "-1\n";
                return;
            }
            //cout << i << ' ' << idx << endl;
            move[idx]=max(move[idx], i);
        }
        string na=a;
        for (int i=0; i<n; i++) {
            //cout << i << ' ' << move[i] << endl;
            if (i<move[i]) na[i+1]=a[i];
        }
        ans.push_back(na);
        a=na;
        //cout << a << endl;

        if (a==b) {
            cout << ans.size() << "\n";
            for (string s: ans) cout << s << "\n";
            return;
        }
    }
    cout << "-1\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
