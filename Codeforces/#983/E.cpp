#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

// m=n/2

// even[i] is 2*i (1<=i<=m) in real, odd[i] is 2*i+1 (0<=i<=m) in real 
ll n, m;
ll decrease2_called_even[nmax]={}, decrease2_called_odd[nmax]={};
ll even[nmax]={}, odd[nmax];

void init(ll n) {
    for (ll i=0; i<=n; i++) {
        decrease2_called_even[i]=0;
        decrease2_called_odd[i]=0;
        even[i]=0;
        odd[i]=0;
    }
}

void decrease1(ll x, ll k) {
    /* 
    decrease position x by k
    ...
    decrease2(x-3, k)
    decrease2(x-1, k)
    decrease2(x, k)
    decrease2(x+2, k)
    decrease2(x+4, k)
    ...
    */
    if (x%2==0) {
        decrease2_called_odd[0]+=k;
        decrease2_called_odd[x/2]-=k; // x+1 == 2*i+1 -> i=x/2
        decrease2_called_even[x/2]+=k; // x == 2*i
        decrease2_called_even[m+1]-=k;
    }
    else {
        decrease2_called_even[1]+=k;
        decrease2_called_even[(x+1)/2]-=k; // x+1 == 2*i
        decrease2_called_odd[(x-1)/2]+=k; // x == 2*i+1
        decrease2_called_odd[m+1]-=k;
    }
}

void decrease2(ll x, ll k) {
    // decrease position x and x+1 by k
    /*if (x==n) {
        even[1]+=k;
        even[m+1]-=k;
    }*/
    if (x%2==0) {
        even[(x+2)/2]+=k; // x+2==2*i
        even[m+1]-=k;
        odd[0]+=k;
        odd[x/2]-=k; // x+1==2*i+1
    }
    else {
        odd[(x+1)/2]+=k; //x+2==2*i+1
        odd[m+1]-=k;
        even[1]+=k;
        even[(x+1)/2]-=k; // 
    }
}

void solve() {
    cin >> n;
    vector<ll> a(n+1);
    for (ll i=1; i<=n; i++) cin >> a[i];

    m=n/2;

    for (ll i=1; i<=n; i++) decrease1(i, a[i]);
    for (ll i=2; i<=m; i++) decrease2_called_even[i]+=decrease2_called_even[i-1];
    for (ll i=1; i<=m; i++) decrease2_called_odd[i]+=decrease2_called_odd[i-1];

    /*for (ll i=1; i<=n; i++) {
        if (i%2==0) cout << decrease2_called_even[i/2] << ' ';
        else cout << decrease2_called_odd[(i-1)/2] << ' ';
    }
    cout << endl;*/

    for (ll i=1; i<=n; i++) {
        if (i%2==0) decrease2(i, decrease2_called_even[i/2]);
        else decrease2(i, decrease2_called_odd[(i-1)/2]);
    }
    for (ll i=2; i<=m; i++) even[i]+=even[i-1];
    for (ll i=1; i<=m; i++) odd[i]+=odd[i-1];

    vector<ll> ans(n+1, 0);
    for (ll i=1; i<=n; i++) {
        if (i%2==0) ans[i]=even[i/2];
        else ans[i]=odd[(i-1)/2];
    }

    for (ll i=1; i<=n; i++) cout << ans[i] << ' ';
    cout << "\n";

    init(n);

    /*vector<ll> b(n+1);
    for (ll i=1; i<=n; i++) b[i]=a[i];

    for (ll i=1; i<=n; i++) {
        b[(i-1>=1 ? i-1 : n)]+=ans[i];
        b[i]+=2*ans[i];
        b[(i+1<=n ? i+1 : 1)]+=ans[i];
    }
    for (ll i=1; i<=n; i++) cout << b[i] << ' ';*/
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll T=1; cin >> T;
    while (T--) {
        solve();
    }
}
