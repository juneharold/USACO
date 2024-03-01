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

void query(int a, int b, int c, int d) {
    cout << "? " << a << ' ' << b << ' ' << c << ' ' << d << "\n";
    cout.flush();
}

void solve() {
    int n; cin >> n;
    int pos1=0;
    for (int i=1; i<n; i++) {
        query(pos1, pos1, i, i);
        char res; cin >> res;
        if (res=='<') pos1=i;
    }

    vector<int> candidates;
    candidates.push_back(0);
    for (int i=1; i<n; i++) {
        query(pos1, candidates.back(), pos1, i);
        char res; cin >> res;
        if (res=='<') {
            candidates.clear();
            candidates.push_back(i);
        }
        else if (res=='=') candidates.push_back(i);
    }

    int pos2=candidates[0];
    for (int i=1; i<candidates.size(); i++) {
        query(pos2, pos2, candidates[i], candidates[i]);
        char res; cin >> res;
        if (res=='>') pos2=candidates[i];
    }
    cout << "! " << pos1 << ' ' << pos2 << "\n";
    cout.flush();
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
