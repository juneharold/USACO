#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

struct cmp {
    bool operator() (pair<int, int> a, pair<int, int> b) {
        if (a.second==b.second) return a.first<b.first;
        return a.second<b.second;
    }
};

multiset <pair<int, int>, cmp> times;

int main()
{
    int n; cin >> n;
    for (int i=0; i<n; i++) {
        int a, b; cin >> a >> b;
        times.insert({a, b});
    }
    int until=0;
    int cnt=0;
    for (auto it: times) {
        if (it.first>=until) {
            cnt++;
            until=it.second;
        }
    }
    cout << cnt;
}
