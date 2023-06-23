#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <random>
#include <chrono>
#include <numeric>
using namespace std;
#define f first
#define s second
typedef long long ll;
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    while (T--) {
        int n, m, d; cin >> n >> m >> d;
        vector<int> loc(n+1, 0);
        for (int i=1; i<=n; i++) {
            int x; cin >> x;
            loc[x]=i;
        }
        vector<int> pos(m+1, 0);
        for (int i=1; i<=m; i++) {
            int x; cin >> x;
            pos[i]=loc[x];
        }

        int ans=1e9;
        for (int i=1; i<m; i++) {
            if (pos[i+1]<pos[i] || pos[i+1]>pos[i]+d) {
                ans=0;
                break;
            }
            int temp=abs(pos[i+1]-pos[i]);
            if (d+1<=n-1) temp=min(temp, abs(d+1-(pos[i+1]-pos[i])));
            ans=min(ans, temp);
        }
        cout << ans << "\n";
    }
}
