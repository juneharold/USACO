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
const ll nmax=1e6+5, sqrmax=635, MOD=1e9+7, INF=1e18;

int N;
char s[nmax];

void solve() {
    cin >> N;
    for (int i=1; i<=N; i++) cin >> s[i];
    ll cnt=0, ans=0;
    stack<ll> st;
    for (ll i=1; i<=N; i++) {
        if (s[i]=='T') {
            if (i%2) {
                cnt++;
                if (!st.empty() && st.top()>0) {
                    ans+=i-st.top();
                    st.pop();
                }
                else st.push(-i);
            }
            else {
                cnt--;
                if (!st.empty() && st.top()<0) {
                    ans+=i+st.top();
                    st.pop();
                }
                else st.push(i);
            }
        }
    }
    if (cnt!=0) {
        cout << "-1\n";
        return;
    }
    cout << ans << "\n";
}
/*
1
10
THHTTHHTHH

1
12
THHTTHHTHHTT

1
4
TTTT

TTTHHTTTHHHTTTHT

13
HTTHHTTHHTHHT

12
TTHTTHTTHTTH

12
TTHTTHTTHTTH

13
TTHTHHTHTTHTT

THHTHHTT

6
THTTHT

8
THTHHTHT
1 2 3 4 4 3 2 1 
T 하나 지날 때마다 하나 증가 
between adjacent odd T blocks
- even number of elements
- even number of odd T blocks

6
THTTHT
4
TTTT
10
THTTHTTHHT
13
TTHTHHTHTTHTT
ans: 
6
2
9
6
*/

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
