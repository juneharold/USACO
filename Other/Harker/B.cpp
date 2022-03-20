#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;

int a[1005]={};

int main()
{
    int N, Q; cin >> N >> Q;
    for (int i=1; i<=N; i++) cin >> a[i];

    for (int i=1; i<=Q; i++) {
        int l, r; cin >> l >> r;
        map<int, int> m;
        for (int j=l; j<=r; j++) {
            m[a[j]]++;
        }
        int ans=0, cnt=0;
        for (auto x: m) {
            if (x.second>cnt) {
                ans=x.first;
                cnt=x.second;
            }
        }

        cout << ans << "\n";
    }
}
