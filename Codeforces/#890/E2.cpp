#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define fs first
#define sc second
const int nmax=1e6+5, sqrmax=635, MOD=1e9+7;

ll ans=0, temp, sz[nmax]={};
//bitset<nmax> dp;
vector<int> graph[nmax];
vector<pii> item_comp;

template <int len=1>
void calc_dp(ll sum) {
    if (sum>=len) {
        calc_dp<min(len*2, nmax)>(sum);
        return;
    }
    bitset<len> dp;
    dp[0]=1;
    for (int i=0; i<item_comp.size(); i++) {
        for (int j=0; j<21; j++) {
            if ((1<<j)>item_comp[i].sc) break;
            dp|=(dp<<((1<<j)*item_comp[i].fs));
            item_comp[i].sc-=(1<<j);
        }
        dp|=(dp<<(item_comp[i].sc*item_comp[i].fs));
    }
    temp=0;
    for (int i=0; i<=sum; i++) {
        if (dp[i]) temp=max(temp, i*(sum-i));
    }
}

void dfs(int cur) {
    sz[cur]=1;
    ll sum=0;
    vector<int> item;
    for (int nx: graph[cur]) {
        dfs(nx);
        sz[cur]+=sz[nx];
        sum+=sz[nx];
        item.push_back(sz[nx]);
    }
    if (item.empty()) return;
    sort(item.begin(), item.end());
    
    item_comp.clear();
    for (int i=item.size()-1; i>=0; i--) {
        int x=item[i];
        if (2*x>=sum) {
            ans+=x*(sum-x);
            return;
        }
        if (item_comp.empty() || x!=item_comp.back().fs) item_comp.push_back({x, 1});
        else item_comp.back().sc++;
    }
    calc_dp(sum);
    ans+=temp;
}

void solve() {
    int n; cin >> n;
    for (int i=2; i<=n; i++) {
        int p; cin >> p;
        graph[p].push_back(i);
    }
    dfs(1);
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; //cin >> T;
    while (T--) {
        solve();
    }
}
