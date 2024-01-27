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
    int a, b, c; cin >> a >> b >> c;
    if (a%2==b%2 && b%2==c%2) cout << "1 1 1\n";
    else if (a%2==b%2) cout << "0 0 1\n"; 
    else if (a%2==c%2) cout << "0 1 0\n"; 
    else if (c%2==b%2) cout << "1 0 0\n"; 
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
