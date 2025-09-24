#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

int n, dp[nmax][3]={}, p[3][nmax]={};
pii nx[nmax][3]={};

int find_idx(int pi, set<pii> &s) {
    auto it=s.lower_bound(make_pair(pi, 0));
    if (it==s.begin()) return -1;
    it--;
    return (*it).sc;
}

void init() {
    for (int j=0; j<3; j++) {
        for (int i=1; i<=n; i++) {
            dp[i][j]=0;
            nx[i][j]={0, 0};
            p[j][i]=0;
        }
    }
}

void solve() {
    cin >> n;
    init();
    for (int j=0; j<3; j++) for (int i=1; i<=n; i++) cin >> p[j][i];

    for (int j=0; j<3; j++) dp[n][j]=1;

    set<pii> s[3];
    for (int i=n; i>=1; i--) {
        for (int j=0; j<3; j++) {
            int idx=find_idx(p[j][i], s[j]);
            if (idx!=-1 && dp[idx][j]) {
                dp[i][j]=1;
                nx[i][j]={idx, j};
            }
        }
        for (int j=0; j<3; j++) {
            for (int k=0; k<3; k++) {
                if (k!=j && dp[i][k] && dp[i][j]==0) {
                    dp[i][j]=1;
                    nx[i][j]=nx[i][k];
                }
            }
            if (dp[i][j]) s[j].insert({p[j][i], i});
        }
    }
    
    if (dp[1][2]==0) {
        cout << "NO\n";
        init();
        return;
    }
    
    int cur=1, type=2;
    vector<pii> ans;
    while (cur<n) {
        ans.push_back({nx[cur][type].sc, nx[cur][type].fs});
        pii temp=nx[cur][type];
        cur=temp.fs; type=temp.sc;
    }
    map<int, char> m;
    m[0]='q'; m[1]='k'; m[2]='j';
    cout << "YES\n";
    cout << ans.size() << "\n";
    for (pii a: ans) cout << m[a.fs] << ' ' << a.sc << "\n";

    init();
}
/*
4
3 1 2 4
2 4 1 3
2 3 1 4
*/
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
