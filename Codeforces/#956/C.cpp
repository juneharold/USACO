#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <iomanip>
#include <bitset>
#include <numeric>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

ll n;
ll tot=0;
ll pos[3]={};

vector<ll> check(vector<ll> &a, vector<ll> &b, vector<ll> &c) {
    ll la=0, ra=-1, lb, rb, lc, rc=n-1;
    ll target=(tot+2)/3, sum1=0, sum2=0, sum3=0;
    while (sum1<target && ra+1<n) {
        ra++;
        sum1+=a[ra];
    }
    lb=ra+1;
    rb=ra;
    while (sum2<target && rb+1<n) {
        rb++;
        sum2+=b[rb];
    }
    lc=rb+1;
    rc=rb;
    while (rc+1<n) {
        rc++;
        sum3+=c[rc];
    }
    vector<ll> ret(6, 0);
    ret[pos[0]*2]=la;
    ret[pos[0]*2+1]=ra;
    ret[pos[1]*2]=lb;
    ret[pos[1]*2+1]=rb;
    ret[pos[2]*2]=lc;
    ret[pos[2]*2+1]=rc;
    if (sum1>=target && sum2>=target && sum3>=target) {
        return ret;
    }
    else return {-1};
}

void solve() {
    cin >> n;
    vector<ll> a(n), b(n), c(n);
    tot=0;
    for (ll i=0; i<n; i++) {
        cin >> a[i];
        tot+=a[i];
    }
    for (ll i=0; i<n; i++) cin >> b[i];
    for (ll i=0; i<n; i++) cin >> c[i];
    
    vector<vector<ll>> answers;
    pos[0]=0, pos[1]=1, pos[2]=2;
    answers.push_back(check(a, b, c));
    pos[0]=0, pos[1]=2, pos[2]=1;
    answers.push_back(check(a, c, b));
    pos[0]=1, pos[1]=0, pos[2]=2;
    answers.push_back(check(b, a, c));
    pos[0]=1, pos[1]=2, pos[2]=0;
    answers.push_back(check(b, c, a));
    pos[0]=2, pos[1]=0, pos[2]=1;
    answers.push_back(check(c, a, b));
    pos[0]=2, pos[1]=1, pos[2]=0;
    answers.push_back(check(c, b, a));
    for (auto ans: answers) {
        //cout << "here\n";
        if (ans.size()>1) {
            for(ll x: ans) cout << x+1 << ' ';
            cout << "\n";
            return;
        }
    }
    cout << "-1\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll T=1; cin >> T;
    while (T--) {
        solve();
    }
}
