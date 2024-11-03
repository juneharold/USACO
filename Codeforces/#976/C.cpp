#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

void solve() {
    ll b, c, d; cin >> b >> c >> d;
    ll a=0;
    for (ll i=0; i<62; i++) {
        //cout << a << endl;
        if ((b&(1LL<<i))==0 && (c&(1LL<<i))==0) {// += 2**i
            if (d&(1LL<<i)) a+=(1LL<<i);
        }
        else if ((b&(1LL<<i)) && (c&(1LL<<i))) {// += 2**i
            if ((d&(1LL<<i))==0) a+=(1LL<<i);
        }
        /*else if ((b&(1LL<<i))==0 && (c&(1LL<<i))) {
            if (d&(1LL<<i)) {
                //cout << "here\n";
                a+=(1LL<<i);
                while (i+1<62) {
                    i++;
                    //cout << i << ' ' << d&(1LL<<i) << (b&(1LL<<i)) << (c&(1LL<<i)) << endl;
                    if ((d&(1LL<<i))==0 && (b&(1LL<<i))==0 && (c&(1LL<<i))==0) {
                        //cout << "here\n";
                        a+=(1LL<<i);
                        break;
                    }
                    else if ((d&(1LL<<i))==0 && (b&(1LL<<i))==0 && (c&(1LL<<i))) {
                        //cout << "here\n";
                        a+=(1LL<<i);
                    }
                    else if ((d&(1LL<<i))==0 && (b&(1LL<<i))==1) {
                        cout << "-1\n";
                        return;
                    }
                }
            }
        }*/
    }
    //cout << a << endl;
    if ((a|b)-(a&c)==d) cout << a << "\n";
    else cout << -1 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
