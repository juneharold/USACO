#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

bool is_palindrome(vector<int> v) {
    int n=v.size();
    for (int i=0; i<n; i++) {
        if (v[i]!=v[n-1-i]) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n+1);
    for (int i=1; i<=n; i++) cin >> a[i];

    vector<int> a_sorted(n+1);
    for (int i=1; i<=n; i++) a_sorted[i]=a[i];
    sort(&a_sorted[1], &a_sorted[n+1]);

    int x=a_sorted[k-1];
    vector<int> res;
    vector<pii> b;
    for (int i=1; i<=n; i++) {
        if (a[i]<x) res.push_back(a[i]);
        if (a[i]<=x) b.push_back({a[i], i});
    }

    if (!is_palindrome(res)) {
        cout << "No\n";
        return;
    }

    int l=0, r=b.size()-1, cnt=0;
    while (l<=r) {
        if (b[r].fs==b[l].fs) {
            if (l!=r) cnt+=2;
            else if (l==r) cnt++;
            l++;
            r--;
        }
        else {
            while (b[r].fs==x) { // only one while loop will run.
                r--;
            }
            while (b[l].fs==x) {
                l++;
            }
        }
    }
    if (cnt>=k-1) cout << "Yes\n";
    else cout << "No\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
