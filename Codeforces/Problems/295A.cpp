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
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7;

ll arr[100005]={}, sum[100005]={}, query[100005]={};
pair<pair<ll, ll>, ll> op[100005];

int main()
{
    ll n, m, k; cin >> n >> m >> k;
    for (ll i=1; i<=n; i++) cin >> arr[i];
    for (ll i=1; i<=m; i++) cin >> op[i].f.f >> op[i].f.s >> op[i].s;
    for (ll i=1; i<=k; i++) {
        ll x, y; cin >> x >> y;
        query[x]++;
        query[y+1]--;
    }
    for (ll i=1; i<=m; i++) query[i]=query[i-1]+query[i];
    
    for (ll i=1; i<=m; i++) {
        sum[op[i].f.f]+=op[i].s*query[i];
        sum[op[i].f.s+1]-=op[i].s*query[i];
    }
    for (ll i=1; i<=n; i++) {
        sum[i]=sum[i]+sum[i-1];
        cout << arr[i]+sum[i] << ' ';
    }
}