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
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

void solve() {
    int n, k, m; cin >> n >> k >> m;
    vector<char> s(m+1);
    for (int i=1; i<=m; i++) cin >> s[i];

    vector<int> cnt(k+1, 0);
    string ans="";
    for (int i=1; i<=m; i++) {
        int cur=s[i]-'a';
        cnt[cur]++;
        bool all_exist=true;
        for (int j=0; j<k; j++) if (cnt[j]==0) all_exist=false;
        if (all_exist) {
            ans+=s[i];
            fill(&cnt[0], &cnt[k], 0);
        }
    }
    if (ans.size()<n) {
        char c;
        for (int j=0; j<k; j++) if (cnt[j]==0) c=j+'a';
        while (ans.size()<n) {ans+=c;}
        cout << "NO\n" << ans << "\n";
    }
    else cout << "YES\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}