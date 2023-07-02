#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
using namespace std;
#define f first
#define s second

int dist(pair<int, int> a, pair<int, int> b) {
    return (a.f-b.f)*(a.f-b.f)+(a.s-b.s)*(a.s-b.s);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<pair<int, int>> a(n, {0, 0});
    for (int i=0; i<n; i++) cin >> a[i].f >> a[i].s;
    sort(a.begin(), a.end());

    int mn=dist(a[0], a[1]), idx=0;
    set<pair<int, int>> temp;
    temp.insert({a[0].s, a[0].f}); 
    temp.insert({a[1].s, a[1].f});
    for (int i=2; i<n; i++) {
        while (!temp.empty()) {
            int x_dist=(a[idx].f-a[i].f)*(a[idx].f-a[i].f);
            if (x_dist<mn) break;
            else {
                temp.erase(make_pair(a[idx].s, a[idx].f));
                idx++;
            }
        }
        auto lb=temp.lower_bound(make_pair(a[i].s-sqrt(mn), -1e9));
        auto ub=temp.upper_bound(make_pair(a[i].s+sqrt(mn), 1e9));
        for (auto it=lb; it!=ub; it++) {
             mn=min(mn, dist(a[i], make_pair((*it).s, (*it).f)));
        }
        temp.insert({a[i].s, a[i].f});
    }
    cout << mn;
}