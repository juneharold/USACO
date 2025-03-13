#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

void solve() {
    ll n; cin >> n;
    vector<ll> b(2*n+1);

    map<ll, ll> m;
    for (ll i=1; i<=2*n; i++) {
        cin >> b[i];
        m[b[i]]++;
    }
    sort(&b[1], &b[2*n+1]);

    ll sum1=0, sum2=0;
    for (ll i=1; i<=n; i++) sum1+=b[i];
    for (ll i=n+1; i<=2*n; i++) sum2+=b[i];

    ll res=sum2-sum1, idx1=n, idx2=n+1;
    while (true) {
        m[res]++;
        if (m[res]==1) break;

        ll until=idx2-n;
        if (until<=idx1) {
            sum1+=b[idx2]-b[idx1];
            sum2+=b[idx1]-b[idx2];
            swap(b[idx1], b[idx2]);
            idx1--;
        }
        if (idx1<until) {
            idx1=n;
            idx2++;
        }
        res=sum2-sum1;
    }
    //cout << res << endl;
    if (res<=0) {
        sort(&b[1], &b[2*n+1]);
        sum1=0, sum2=0;
        for (ll i=1; i<=n; i++) sum1+=b[i];
        for (ll i=n+1; i<=2*n; i++) sum2+=b[i];
        res=sum2-sum1+b[1]*2;
        vector<ll> a(2*n+5);
        //cout << res << endl;
        a[2]=res;
        a[1]=b[1];
        ll idx=2;
        for (ll i=4; i<=2*n+1; i+=2) {
            a[i]=b[idx]; 
            idx++;
        }
        idx=2*n;
        for (ll i=3; i<=2*n+1; i+=2) {
            a[i]=b[idx]; 
            idx--;
        }
        for (ll i=1; i<=2*n+1; i++) cout << a[i] << ' ';
        cout << "\n";
    }
    else {
        vector<ll> a(2*n+5);
        a[1]=res;
        ll idx=2*n;
        for (ll i=2; i<=2*n+1; i+=2) {
            a[i]=b[idx]; 
            idx--;
        }
        idx=1;
        for (ll i=3; i<=2*n+1; i+=2) {
            a[i]=b[idx]; 
            idx++;
        }
        for (ll i=1; i<=2*n+1; i++) cout << a[i] << ' ';
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll T=1; cin >> T;
    while (T--) {
        solve();
    }
}
