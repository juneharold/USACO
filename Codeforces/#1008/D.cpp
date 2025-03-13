#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;



void solve() {
    ll n; cin >> n;
    vector<char> c1(n+1), c2(n+1);
    vector<ll> x(n+1), y(n+1);
    for (ll i=1; i<=n; i++) cin >> c1[i] >> x[i] >> c2[i] >> y[i];

    ll ans1=1, ans2=1, cnt=x[1]+y[1];
    if (c1[1]=='x') cnt--;
    if (c2[1]=='x') cnt--;
    for (ll i=2; i<=n; i++) {
        //cout << ans1 << ' ' << ans2 << ' ' << cnt << endl;
        if ((c1[i]=='x' && c2[i]=='x') || (c1[i]=='+' && c2[i]=='+')) {
            ll x_prod=1, y_prod=1;
            for (int j=i; j<=n; j++) {
                if (c1[j]=='x') x_prod*=x[j];
                if (c2[j]=='x') y_prod*=y[j];

                if (x_prod>y_prod) {
                    ans1+=cnt;
                    break;
                }
                if (y_prod>x_prod) {
                    ans2+=cnt;
                    break;
                }
                if (j==n) ans1+=cnt;
            }
        }
        else if (c1[i]=='x') {
            ans1+=cnt;
        }
        else if (c2[i]=='x') {
            ans2+=cnt;
        }

        cnt=0;
        if (c1[i]=='x') cnt+=(x[i]-1)*ans1;
        else cnt+=x[i];
        if (c2[i]=='x') cnt+=(y[i]-1)*ans2;
        else cnt+=y[i];
    }

    cout << ans1+ans2+cnt << "\n";
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll T=1; cin >> T;
    while (T--) {
        solve();
    }
}
