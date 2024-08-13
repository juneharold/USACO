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
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

void solve() {
    int n, k; cin >> n >> k;
    map<int, int> a1, a2;
    int cnt1=n, cnt2=n;
    vector<int> idx1, idx2;
    for (int i=0; i<n; i++) {
        int x; cin >> x;
        a1[x]++;
        if (a1[x]==2) idx1.push_back(x);
    }
    for (int i=0; i<n; i++) {
        int x; cin >> x;
        a2[x]++;
        if (a2[x]==2) idx2.push_back(x);
    }

    while (cnt1-2>=2*k && !idx1.empty()) {
        a1[idx1.back()]=0;
        idx1.pop_back();
        cnt1-=2;
    }
    while (cnt2-2>=cnt1 && !idx2.empty()) {
        a2[idx2.back()]=0;
        idx2.pop_back();
        cnt2-=2;
    }

    for (auto x: a1) {
        if (cnt1>2*k && x.sc==1) {
            a1[x.fs]--;
            a2[x.fs]--;
            cnt1--;
        }
    }

    for (auto x: a1) {
        for (int i=0; i<x.sc; i++) cout << x.fs << ' ';
    }
    cout << "\n";
    for (auto x: a2) {
        for (int i=0; i<x.sc; i++) cout << x.fs << ' ';
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
