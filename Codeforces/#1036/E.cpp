#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

void solve() {
    ll n; cin >> n;
    vector<ll> a(n+1);
    for (ll i=1; i<=n; i++) cin >> a[i];

    ll sum=0, mx=0;
    for (ll i=1; i<=n; i++) {
        sum+=a[i];
        mx=max(mx, a[i]);
    }

    if (sum%2 || mx>sum-mx) {
        cout << "-1\n";
        return;
    }

    ll k=-1, pfs=0;
    for (ll i=1; i<=n; i++) {
        pfs+=a[i];
        if (pfs==sum/2) {
            cout << "1\n";
            for (ll j=1; j<=n; j++) cout << a[j] << ' ';
            cout << "\n";
            return;
        }
    }

    pfs=0;
    for (ll i=1; i<=n; i++) {
        pfs+=a[i];
        if (pfs>sum/2) {
            k=i;
            break;
        }
    }


    ll sum_left=pfs-a[k], sum_right=sum-pfs;
    if (sum_left>sum_right) {
        ll diff=sum_left-sum_right;
        ll x=(diff+a[k])/2;
        vector<ll> b(n+1);
        b[k]=x;
        for (ll i=1; i<k; i++) {
            if (x>0 && x>a[i])  {
                b[i]=a[i];
                x-=a[i];
            }
            else if (x>0 && a[i]>=x) {
                b[i]=x;
                x=0;
            }
        }

        for (ll i=1; i<=n; i++) {
            a[i]-=b[i];
            if (a[i]<0) {
                cout << "-1\n";
                return;
            }
        }   

        cout << "2\n";
        for (ll i=1; i<=n; i++) cout << b[i] << ' ';
        cout << "\n";
    }
    else {
        ll diff=sum_right-sum_left;
        ll x=(diff+a[k])/2;
        vector<ll> b(n+1);
        b[k]=x;
        for (ll i=n; i>k; i--) {
            if (x>0 && x>a[i])  {
                b[i]=a[i];
                x-=a[i];
            }
            else if (x>0 && a[i]>=x) {
                b[i]=x;
                x=0;
            }
        }

        for (ll i=1; i<=n; i++) {
            a[i]-=b[i];
            if (a[i]<0) {
                cout << "-1\n";
                return;
            }
        }

        cout << "2\n";
        for (ll i=1; i<=n; i++) cout << b[i] << ' ';
        cout << "\n";
    }
    for (ll i=1; i<=n; i++) cout << a[i] << ' ';
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll T=1; cin >> T;
    while (T--) {
        solve();
    }
}
