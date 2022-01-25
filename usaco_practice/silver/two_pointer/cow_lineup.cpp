#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

pair <int, int> cow[100005];
set <int> u;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    for (int i=0; i<n; i++) {
        cin >> cow[i].first >> cow[i].second;
        u.insert(cow[i].second);
    }
    sort(cow, cow+n);
    multiset <int> active;
    set <int> active2;
    int left=0, right=0;
    int Min=1e9;

    while (true) {
        bool ind=true;
        if (active2.size()!=u.size())ind=false;

        if (ind==true and cow[right-1].first-cow[left].first<Min) Min=cow[right-1].first-cow[left].first;

        if (ind==false and right==n) break;

        if (ind==false) {
            active.insert(cow[right].second);
            active2.insert(cow[right].second);
            right++;
        }
        else if (ind==true and active.count(cow[left].second)>1) {
            active.erase(active.lower_bound(cow[left].second));
            left++;
        }
        else {
            if (active.count(cow[left].second)==1) active2.erase(cow[left].second);
            active.erase(active.lower_bound(cow[left].second));
            left++;
        }
    }
    cout << Min;
}

/*
15 1
20 1
22 3
25 7
26 1
30 1

8
1 1
3 1
4 2
6 1
7 3
8 9
10 1
11 2

3
2 1
1 2
3 1
*/
