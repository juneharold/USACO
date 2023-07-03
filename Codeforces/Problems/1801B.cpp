#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
#define f first
#define s second

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<pair<int, int>> v(n, {0, 0});
        for (int i=0; i<n; i++) cin >> v[i].f >> v[i].s;
        sort(v.begin(), v.end());

        vector<int> mx(n, 0);
        int b=-1e9;
        for (int i=n-1; i>=0; i--) {
            mx[i]=b;
            b=max(b, v[i].s);
        }

        set<int> S;
        int ans=1e9;
        for (int i=0; i<n; i++) {
            if (mx[i]==v[i].f) ans=0;
            if (mx[i]>v[i].f) ans=min(ans, mx[i]-v[i].f);
            if (mx[i]<v[i].f) {
                ans=min(ans, v[i].f-mx[i]);
                auto lb=S.upper_bound(v[i].f);
                if (lb!=S.end()) ans=min(ans, *lb-v[i].f);
                if (lb!=S.begin()) ans=min(ans, v[i].f-*--lb);
            }
            S.insert(v[i].s);
        }
        cout << ans << "\n";
    }
}