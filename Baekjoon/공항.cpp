#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
    int G, P; cin >> G >> P;
    set<int> s;
    for (int i=1; i<=G; i++) s.insert(i);
    int ans=0;
    for (int i=1; i<=P; i++) {
        int x; cin >> x;
        auto it=s.upper_bound(x);
        if (it==s.begin()) break;
        it--;
        s.erase(it);
        ans++;
    }
    cout << ans;
}