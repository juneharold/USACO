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

ll cnt[nmax]={};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll T; cin >> T;
    while (T--) {
        ll n; cin >> n;
        vector<ll> a(n+1, 0);
        map<ll, ll> hash;
        ll idx=1;
        for (ll i=1; i<=n; i++) {
            cin >> a[i]; 
            if (hash.count(a[i])==0) hash[a[i]]=idx++;
            cnt[hash[a[i]]]++;
        }

        ll ans=0;
        for (ll i=1; i<=n; i++) ans+=(cnt[hash[a[i]]]-1)*(cnt[hash[a[i]]]-2);
        
        for (ll j=1; j<=n; j++) {
            if (a[j]>1e6) {
                for (ll b=2; b<1000; b++) {
                    if (a[j]%b==0 && hash.count(a[j]/b) && hash.count(a[j]*b)) ans+=cnt[hash[a[j]/b]]*cnt[hash[a[j]*b]];
                }
            }
            else {
                for (ll b=2; b*b<=a[j]; b++) {
                    if (a[j]%b==0) {
                        if (hash.count(a[j]/b) && hash.count(a[j]*b)) ans+=cnt[hash[a[j]/b]]*cnt[hash[a[j]*b]];
                        if (a[j]!=b*b && hash.count(b) && hash.count(a[j]*(a[j]/b))) ans+=cnt[hash[b]]*cnt[hash[a[j]*(a[j]/b)]];
                    }
                }
                if (a[j]!=1 && hash.count(1) && hash.count(a[j]*a[j])) ans+=cnt[hash[1]]*cnt[hash[a[j]*a[j]]];
            }
        }
        cout << ans << "\n";

        for (ll i=1; i<=n; i++) {
            cnt[hash[a[i]]]=0;
        }
    }
}
