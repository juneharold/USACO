#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

void solve() {
    int l, r, L, R; cin >> l >> r >> L >> R;
    vector<int> mark1(101, 0), mark2(101, 0);
    for (int i=l; i<=r; i++) mark1[i]++;
    for (int i=L; i<=R; i++) mark2[i]++;
    int ans=0;
    for (int i=1; i<100; i++) {
        if ((mark1[i] && mark2[i+1]) || (mark2[i] && mark1[i+1])) ans++;
    }
    cout << max(ans, 1) << "\n";
    /*
    1 100
    1 99

    4 5
    5 6
    pii A={l, r}, B={L, R};
    if (A>B) swap(A, B);

    if (A.sc<B.fs) cout << "1\n";
    else if (A.fs<=B.fs && B.sc<=A.sc) {
        cout << B.sc-B.fs+2-(A.fs==B.fs)-(A.sc==B.sc) << "\n";
    }
    else {
        cout << A.sc-B.fs+1-(A.fs==B.fs)+(A.sc==B.fs) << "\n";
    }*/
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
