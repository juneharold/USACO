#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define pb push_back
#define ff first
#define ss second

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

const int INF = 1e9;
const ll LLINF = 1e18;
const int MOD = 1e9 + 7;

template<class K> using sset =  tree<K, null_type, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

inline ll ceil0(ll a, ll b) {
    return a / b + ((a ^ b) > 0 && a % b);
}

void setIO() {
    ios_base::sync_with_stdio(0); cin.tie(0);
}

int main(){
    setIO();
    int T;
    cin >> T;
    for(int tt = 1; tt <= T; tt++){
        int n;
        cin >> n;
        int a[n + 1], b[n + 1];
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= n; i++) cin >> b[i];
        bool val[n + 1];
        memset(val, false, sizeof(val));
        for(int t = 0; t < 2; t++){
            int prvb[n + 1]; //prev smaller
            int nxta[n + 1]; //next greater
            stack<pii> s;
            s.push({INF, n + 1});
            for(int i = n; i >= 1; i--){
                while(s.top().ff <= a[i]) s.pop();
                nxta[i] = s.top().ss;
                s.push({a[i], i});
            }
            while(!s.empty()) s.pop();
            s.push({0, 0});
            for(int i = 1; i <= n; i++){
                while(s.top().ff >= b[i]) s.pop();
                prvb[i] = s.top().ss;
                s.push({b[i], i});
            }
            int m[n + 1];
            memset(m, 0, sizeof(m));
            for(int i = 1; i <= n; i++){
                m[a[i]] = i;
                if(a[i] <= b[i] && m[b[i]]) val[i] |= prvb[i] < m[b[i]] && nxta[m[b[i]]] > i;
            }
            reverse(a + 1, a + n + 1);
            reverse(b + 1, b + n + 1);
            reverse(val + 1, val + n + 1);
        }
        bool ans = true;
        for(int i = 1; i <= n; i++) ans &= val[i];
        cout << (ans ? "YES" : "NO") << endl;
    }
}