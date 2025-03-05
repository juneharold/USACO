#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

ll n, a[nmax]={}, A[nmax]={};

ll find(ll x) {
    if (x<=n) return a[x];

    ll nx=x/2;
    if (nx<=n) return A[nx];

    if (nx/2==(nx-1)/2) {
        if (nx%2==n%2) return A[n];
        else {
            if (nx<=n) return A[nx/2];
            else return find(n+1)^A[n];
        }
    }
    else {
        if ((nx-1)%2==n%2) return A[n]^find(nx);
        else {
            if (nx<=n) return A[nx/2]^find(nx);
            else return find(n+1)^A[n]^find(nx);
        }
    }
}

void solve() {
    ll l, r; cin >> n >> l >> r;
    for (int i=1; i<=n; i++) cin >> a[i];

    for (int i=1; i<=n; i++) A[i]=A[i-1]^a[i];
    cout << find(l) << "\n";

    /*for (int i=n+1; i<=30; i++) {
        for (int j=1; j<=i/2; j++) a[i]^=a[j];
    }
    for (int i=1; i<=30; i++) cout << "i: " << i << ' ' << a[i] << ' ' << find(i) << endl;*/
    

    for (int i=1; i<=n+5; i++) {
        a[i]=0;
        A[i]=0;
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
