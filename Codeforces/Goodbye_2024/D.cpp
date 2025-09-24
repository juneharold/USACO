#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=998244353, INF=1e18;

ll fastpow (ll x, ll y) {
    ll ret=1;
    while (y) {
        if (y%2) {
            ret*=x;
            ret%=MOD;
        }
        x*=x;
        x%=MOD;
        y/=2;
    }
    return ret;
}

ll findPos(ll n, vector<pii> &v, ll x) {
    //for (ll i=1; i<=n; i++) cout << v[i].fs << endl;
    ll lo=1, hi=n;
    while (lo<hi) {
        ll mid=(lo+hi+1)/2;
        //cout << lo << ' ' << hi << ' ' << v[mid].fs << endl;
        if (v[mid].fs<=x) lo=mid;
        else hi=mid-1;
    }
    return lo;
}

void solve() {
    ll n, q; cin >> n >> q;
    vector<ll> a(n+1), b(n+1);
    for (ll i=1; i<=n; i++) cin >> a[i];
    for (ll i=1; i<=n; i++) cin >> b[i];

    vector<ll> posA(n+1), posB(n+1); // position of original index when sorted. 
    vector<pii> A(n+1), B(n+1);
    for (ll i=1; i<=n; i++) A[i]={a[i], i};
    sort(&A[1], &A[n+1]);
    for (ll i=1; i<=n; i++) posA[A[i].sc]=i;
    for (ll i=1; i<=n; i++) B[i]={b[i], i};
    sort(&B[1], &B[n+1]);
    for (ll i=1; i<=n; i++) posB[B[i].sc]=i;

    ll ans=1;
    for (ll i=1; i<=n; i++) ans=ans*min(A[i].fs, B[i].fs)%MOD;
    vector<ll> answers;
    answers.push_back(ans);
    while (q--) {
        ll o, x; cin >> o >> x;
        if (o==1) {
            ll i=posA[x];
            // A[i].fs가 1 증가. 
            //cout << A[i].fs << endl;
            ll j=findPos(n, A, A[i].fs);
            //cout << i << ' ' << j << endl;
            // dividing previous
            ans=ans*fastpow(min(A[i].fs, B[i].fs), MOD-2)%MOD;
            if (i!=j) ans=ans*fastpow(min(A[j].fs, B[j].fs), MOD-2)%MOD;
            // swapping. 
            posA[x]=j;
            posA[A[j].sc]=i;
            swap(A[i].sc, A[j].sc);
            A[j].fs++; //because it is A[i].fs+1
            // multiplying current
            ans=ans*min(A[i].fs, B[i].fs)%MOD;
            if (i!=j) ans=ans*min(A[j].fs, B[j].fs)%MOD;
        }
        else {
            ll i=posB[x];
            // A[i].fs가 1 증가. 
            ll j=findPos(n, B, B[i].fs);
            // dividing previous
            ans=ans*fastpow(min(A[i].fs, B[i].fs), MOD-2)%MOD;
            if (i!=j) ans=ans*fastpow(min(A[j].fs, B[j].fs), MOD-2)%MOD;

            // swapping. 
            posB[x]=j;
            posB[B[j].sc]=i;
            swap(B[i].sc, B[j].sc);
            B[j].fs++; //because it is A[i].fs+1
            // multiplying current
            ans=ans*min(A[i].fs, B[i].fs)%MOD;
            if (i!=j) ans=ans*min(A[j].fs, B[j].fs)%MOD;
        }
        answers.push_back(ans);
    }
    for (ll aa: answers) cout << aa << ' ';
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
