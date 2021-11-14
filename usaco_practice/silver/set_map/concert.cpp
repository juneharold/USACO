#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

const int MAX=2e5+5;
int n, m, people[MAX];
multiset<int> tickets;

int main()
{
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        int a; cin >> a;
        tickets.insert(a);
    }
    for (int i=0; i<m; i++) cin >> people[i];


    for (int i=0; i<m; i++) {
        int t=people[i];
        if (tickets.size()==0) {
            cout << -1 << "\n";
            continue;
        }
        auto it=tickets.upper_bound(t);
        if (it==tickets.begin()) {
            cout << -1 << "\n";
        }
        else {
            it--;
            if (*it<=t) {
                cout << *it << "\n";
                tickets.erase(it);
            }
            else if (*it>t) {
                cout << -1 << "\n";
            }
        }
    }
}
