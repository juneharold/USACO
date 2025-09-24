#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

void solve() {
    int n; cin >> n;
    vector<int> a(n+1);
    for (int i=1; i<=n; i++) cin >> a[i];

    vector<int> cnt(5, 0);
    for (int i=1; i<=n; i++) cnt[a[i]]++;
    for (int i=1; i<3; i++) cnt[i]+=cnt[i-1];

    vector<pii> ans;
    vector<int> idx2;
    for (int i=1; i<=cnt[0]; i++) {
        if (a[i]==2) idx2.push_back(i);
    }
    for (int i=cnt[0]+1; i<=cnt[1]; i++) {
        if (a[i]==1 && !idx2.empty()) {
            ans.push_back({idx2.back(), i});
            swap(a[idx2.back()], a[i]);
            idx2.pop_back();
        }
    }

    vector<int> a1, c0, c1, a2, b2;
    for (int i=1; i<=cnt[0]; i++) {
        if (a[i]==1) a1.push_back(i);
        if (a[i]==2) a2.push_back(i);
    }
    for (int i=cnt[0]+1; i<=cnt[1]; i++) {
        if (a[i]==2) b2.push_back(i);
    }
    for (int i=cnt[1]+1; i<=cnt[2]; i++) {
        if (a[i]==0) c0.push_back(i);
        if (a[i]==1) c1.push_back(i);
    }

    while (true) {
        int did=0;
        while (!a1.empty() && !c0.empty()) {
            int u=a1.back(), v=c0.back();
            a1.pop_back(), c0.pop_back();
            ans.push_back({u, v});
            a[v]=1;
            c1.push_back(v);
            a[u]=0;
            did++;
        }
        while (!c1.empty() && !a2.empty()) {
            int u=c1.back(), v=a2.back();
            c1.pop_back(), a2.pop_back();
            ans.push_back({u, v});
            a[v]=1;
            a1.push_back(v);
            a[u]=2;
            did++;
        }
        while (!c1.empty() && !b2.empty()) {
            int u=c1.back(), v=b2.back();
            c1.pop_back(), b2.pop_back();
            ans.push_back({u, v});
            a[v]=1;
            a[u]=2;
            did++;
        }
        if (did==0) break;
    }
    
    vector<int> idx1;
    for (int i=1; i<=cnt[0]; i++) {
        if (a[i]==1) idx1.push_back(i);
    }
    for (int i=cnt[0]+1; i<=cnt[1]; i++) {
        if (a[i]==0) {
            ans.push_back({idx1.back(), i});
            swap(a[idx1.back()], a[i]);
            idx1.pop_back();
        }
    }

    /*for (int i=1; i<=n; i++) cout << a[i] << ' ';
    cout << endl;*/

    cout << ans.size() << "\n";
    for (auto p: ans) cout << p.fs << ' ' << p.sc << "\n";
}

/*
2121211001010100112210


22100
*/

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
