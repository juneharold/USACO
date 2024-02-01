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
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n; i++) cin >> b[i];

    vector<pii> v(n);
    for (int i=0; i<n; i++) {
        v[i].fs=a[i]+b[i];
        v[i].sc=i;
    }
    sort(v.begin(), v.end());

    for (int i=0; i<n; i++) cout << a[v[i].sc] << ' ';
    cout << "\n";
    for (int i=0; i<n; i++) cout << b[v[i].sc] << ' ';
    cout << "\n";

    /*vector<int> pos(n+1, -1);
    for (int i=0; i<n; i++) pos[b[i]]=i;
    
    for (int i=0; i<n; i++) {
        if (i+1!=b[i]) {
            int temp=pos[i+1];
            swap(a[i], a[temp]);
            swap(b[i], b[temp]);
        }
    }
    for (int i=0; i<n; i++) cout << a[i] << ' ';
    cout << "\n";
    for (int i=0; i<n; i++) cout << b[i] << ' ';
    cout << "\n";*/
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
