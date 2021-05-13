#include <iostream>
#include <algorithm>
using namespace std;

pair < pair<int, int>, int> namu[100005];
#define f first
#define s second

int group[100005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q; cin >> n >> q;
    for (int i=0; i<n; i++) {
        int y;
        cin >> namu[i].f.f >> namu[i].f.s >> y;
        namu[i].s=i+1;
    }
    sort(namu, namu+n);
    long long cur=namu[0].s;
    group[namu[0].s]=cur;
    long long end=namu[0].f.s;
    for (int i=1; i<n; i++) {
        if (namu[i].f.f<=end) { //겹침.
            if (namu[i].f.s>end) end=namu[i].f.s;
            group[namu[i].s]=cur;
        }
        else { // 안겹침.
            end=namu[i].f.s;
            cur=namu[i].s;
            group[namu[i].s]=cur;
        }
    }
    for (int i=0; i<q; i++) {
        int a, b; cin >> a >> b;
        if (group[a]==group[b]) cout << 1 << "\n";
        else cout << 0 << "\n";
    }
}
