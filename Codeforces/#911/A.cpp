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
    int n; cin >> n;
    string s; cin >> s;
    int ans=0, len=0;
    for (int i=0; i<n; i++) {
        if (s[i]=='.') len++;
        else {
            if (len==0) continue;
            else if (len==1) ans++;
            else if (len==2) ans+=2;
            else {
                cout << "2\n";
                return;
            }
            len=0;
        }
    }
    if (len==1) ans++;
    else if (len==2) ans+=2;
    else if (len!=0) {
        cout << "2\n";
        return;
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
