#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define f first
#define s second

bool overlap(pii a, pii b) {
    if (a.s<b.f || b.s<a.f) return false;
    return true;
}

int main()
{
    int T; cin >> T;
    vector<int> out;
    while (T--) {
        int n; cin >> n;
        vector<pii> seg(n, {0, 0});
        for (int i=0; i<n; i++) cin >> seg[i].f >> seg[i].s;

        vector<pii> pairseg;
        for (int i=0; i<n; i++) {
            for (int j=0; j<i; j++) {
                if (overlap(seg[i], seg[j])) {
                    pairseg.push_back({max(seg[i].s, seg[j].s), min(seg[i].f, seg[j].f)});
                }
            }
        }
        sort(pairseg.begin(), pairseg.end());

        int cnt=0, prev=-1;
        for (int i=0; i<pairseg.size(); i++) {
            if (prev<pairseg[i].s) {
                cnt++;
                prev=pairseg[i].f;
            }
        }
        out.push_back(n-cnt*2);
    }
    for (int x: out) cout << x << "\n";
}
