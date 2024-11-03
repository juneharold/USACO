#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

ll n;
ll findNext(ll k, vector<ll> &pos) {
    ll lo=1, hi=n;
    while (lo<hi) {
        ll mid=(lo+hi)/2;
        if (pos[mid]>k) hi=mid;
        else lo=mid+1;
    }
    return lo;
}

ll findSum(ll i, ll j, vector<ll> &pfsa, vector<ll> &s) {
    return s[i]-s[j+1]-(pfsa[j]-pfsa[i-1])*(n-j);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    vector<ll> a(n+1);
    for (ll i=1; i<=n; i++) cin >> a[i];

    vector<ll> pfsa(n+5, 0);
    for (ll i=1; i<=n; i++) pfsa[i]=pfsa[i-1]+a[i];
    vector<ll> s(n+5, 0);
    for (ll i=n; i>=0; i--) s[i]=s[i+1]+a[i]*(n-i+1);
    vector<ll> pfs(n+5, 0);
    for (ll i=1; i<=n; i++) pfs[i]=pfs[i-1]+s[i];
    vector<ll> pos(n+5, 0);
    pos[1]=1; // this means s(1, j) starts at 1
    for (ll i=2; i<=n; i++) pos[i]=pos[i-1]+(n-i+2);

    ll q; cin >> q;
    while (q--) {
        ll l, r; cin >> l >> r;
        ll from=findNext(l, pos), to=findNext(r, pos);
        to-=2;
        if (r==n*(n+1)/2) to++;
        //cout << from << ' ' << to << endl;
        if (from>to) {
            ll ans=0;
            if (from==to+2) {
                //cout << findSum(from-1, r-pos[from-1]+from-1, pfsa, s) << ' ' << findSum(from-1, l-pos[from-1], pfsa, s) << endl;
                ans=findSum(from-1, r-pos[from-1]+from-1, pfsa, s);
                ans-=findSum(from-1, l-pos[from-1]+from-2, pfsa, s);
            }
            else {
                //cout << s[from-1]-findSum(from-1, n-(pos[from]-l), pfsa, s) << ' ';
                //cout << findSum(to+1, r-pos[to+1]+to+1, pfsa, s) << endl;
                ans+=s[from-1]-findSum(from-1, n-(pos[from]-l), pfsa, s);
                ans+=findSum(to+1, r-pos[to+1]+to+1, pfsa, s);
            }
            cout << ans << "\n";
            continue;
        }
        ll ans=pfs[to]-pfs[from-1];
        //cout << from << ' ' << to << endl;
        //cout << ans << ' ' << s[from-1]-findSum(from-1, n-(pos[from]-l), pfsa, s) << ' ';
        //cout << findSum(to+1, r-pos[to+1]+to+1, pfsa, s) << endl;
        ans+=s[from-1]-findSum(from-1, n-(pos[from]-l), pfsa, s);
        ans+=findSum(to+1, r-pos[to+1]+to+1, pfsa, s);
        cout << ans << "\n";
    }
}
