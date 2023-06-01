#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;
#define f first
#define s second
typedef long long ll;
const int nmax=2e5+5, sqrmax=635, MOD=1e9+7;
 
int a[nmax]={}, b[nmax]={}, arr[sqrmax][nmax]={};
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll T; cin >> T;
    while (T--) {
        ll n; cin >> n;
        for (ll i=1; i<=n; i++) cin >> a[i];
        ll mx=sqrt(2*n);
        for (ll i=1; i<=n; i++) {
            cin >> b[i];
            if (a[i]<=mx) arr[a[i]][b[i]]++;
        }
 
        ll ans=0;
        for (ll i=1; i<=n; i++) {
            if (a[i]<=mx) {
                if (1<=a[i]*a[i]-b[i] && a[i]*a[i]-b[i]<=n) {
                    ans+=arr[a[i]][a[i]*a[i]-b[i]];
                }
            }
        }
        for (ll ai=1; ai<=mx; ai++) {
            if (ai*ai%2==1) continue;
            ans-=arr[ai][ai*ai/2];
        }
        ans/=2;
 
        for (ll i=1; i<=n; i++) {
            for (ll aj=1; aj<=mx && aj<a[i] && a[i]*aj<=2*n; aj++) {
                if (1<=a[i]*aj-b[i] && a[i]*aj-b[i]<=n) {
                    ans+=arr[aj][a[i]*aj-b[i]];
                }
            }
        }
 
        cout << ans << "\n";

        for(ll i=1; i<=n; i++) {
            if (a[i]<=mx) arr[a[i]][b[i]]=0;
        }
        fill(&a[0], &a[n+1], 0);
        fill(&b[0], &b[n+1], 0);
    }
}
