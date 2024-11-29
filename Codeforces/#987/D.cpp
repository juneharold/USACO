#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=5e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

int ans[nmax]={};
void fill_ans(int a, int b, int x) {
    for (int i=a; i<=b; i++) ans[i]=x;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n+1);
    for (int i=1; i<=n; i++) cin >> a[i];

    vector<int> group(n+1, 0);
    int mx=0;
    for (int i=1; i<=n; i++) {
        group[i]=max(mx, a[i]);
        mx=max(mx, a[i]);
    }

    /*for (int i=1; i<=n; i++) cout << group[i] << ' ';
    cout << endl;*/
    
    vector<pii> start_end;
    vector<int> mn(n+1, 0);
    int prev=1;
    for (int i=2; i<=n; i++) {
        if (group[i]!=group[i-1]) {
            start_end.push_back({prev, i-1});
            prev=i;
        }
    }
    start_end.push_back({prev, n});
    int idx=0;
    for (auto [s, e]: start_end) {
        int temp=1e9;
        for (int i=s; i<=e; i++) {
            temp=min(temp, a[i]);
        }
        mn[idx++]=temp;
    }

    for (int i=idx-1; i>=0; i--) {
        if (i+2<idx) mn[i+1]=min(mn[i+1], mn[i+2]);
        if (i+1<idx && group[start_end[i].fs]>mn[i+1]) {
            fill_ans(start_end[i].fs, start_end[i].sc, ans[start_end[i].sc+1]);
        }
        else fill_ans(start_end[i].fs, start_end[i].sc, group[start_end[i].fs]);
    }

    for (int i=1; i<=n; i++) cout << ans[i] << ' ';
    cout << "\n";

    for (int i=1; i<=n; i++) ans[i]=0;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
