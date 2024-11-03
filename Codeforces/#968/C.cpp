#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

void solve() {
    int n; cin >> n;
    vector<char> a(n+1);
    for (int i=1; i<=n; i++) cin >> a[i];


    vector<int> cnt(26, 0);
    for (int i=1; i<=n; i++) cnt[a[i]-'a']++;
    set<pii> s;
    for (int i=0; i<26; i++) s.insert({cnt[i], i});

    string ans="";
    for (int i=0; i<n; i++) {
        auto it=--s.end();
        while (true) {
            if ((*it).fs==0) {
                it++;
                break;
            }
            bool possible=true;
            for (int j=i-1; j>=max(0, i-1); j--) {
                if (ans[j]-'a'==(*it).sc) possible=false;
            }
            if (possible) break;
            else it--;
        }
        ans+=(*it).sc+'a';
        pii newcnt={(*it).fs-1, (*it).sc};
        s.erase(it);
        s.insert(newcnt);
    }
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
