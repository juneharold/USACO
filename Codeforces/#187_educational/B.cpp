#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

int F(ll x) {
    int ret=0;
    while (x) {
        ret+=x%10;
        x/=10;
    }
    return ret;
}

void solve() {
    ll x; cin >> x;
    if (F(F(x))==F(x)) {
        cout << "0\n";
        return;
    }
    vector<int> v;
    while (x) {
        v.push_back(x%10);
        x/=10;
    }
    int y=v.back();
    vector<int> v1=v, v2=v;

    int ans=20;
    // turn first to 1 
    int temp=0;
    if (y!=1) temp++;
    int left=8;
    v1.pop_back(); // remove first
    sort(v1.begin(), v1.end());
    for (int i=0; i<v1.size(); i++) {
        if (left-v1[i]<0) temp++;
        else left-=v1[i];
    }
    ans=min(ans, temp);

    // do not turn first to 1
    left=9-y;
    temp=0;
    v2.pop_back(); // remove first
    sort(v2.begin(), v2.end());
    for (int i=0; i<v2.size(); i++) {
        if (left-v2[i]<0) temp++;
        else left-=v2[i];
    }
    ans=min(ans, temp);

    cout << ans << "\n";

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
