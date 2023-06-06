#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <random>
#include <chrono>
using namespace std;
#define f first
#define s second
typedef long long ll;
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7;

ll cnt[1000001]={};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll T; cin >> T;
    while (T--) {
        ll n; cin >> n;
        vector<ll> a(n+1, 0);
        for (ll i=1; i<=n; i++) {
            cin >> a[i]; 
            cnt[a[i]]++;
        }

        ll ans=0;
        for (ll i=1; i<=n; i++) {
            for (ll b=1; b<=1000; b++) {
                if (a[i]*b*b>1e6) break;
                ll aj=a[i]*b, ak=a[i]*b*b;
                if (b==1) {
                    ans+=(cnt[aj]-1)*(cnt[ak]-2);
                }
                else {
                    ans+=cnt[aj]*cnt[ak];
                }
            }
        }
        cout << ans << "\n";

        for (ll i=1; i<=n; i++) cnt[a[i]]=0;
    }
}
