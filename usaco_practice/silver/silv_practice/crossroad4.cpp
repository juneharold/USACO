#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int chicken[20005]={};
pair <int, int> cow[20005];

struct cmp {
    bool operator() (pair<int, int> a, pair<int, int> b) {
        if (a.second==b.second) return a.first<b.first;
        return a.second<b.second;
    }
};


int main()
{
    int c, n; cin >> c >> n;
    for (int i=0; i<c; i++) cin >> chicken[i];
    for (int i=0; i<n; i++) cin >> cow[i].first >> cow[i].second;
    sort(&chicken[0], &chicken[c]);
    sort(&cow[0], &cow[n]);
    int ind=0;
    int cnt=0;
    multiset <pair<int, int>, cmp> active;
    for (int i=0; i<c; i++) {

        while (ind<n && cow[ind].first<=chicken[i]) {
                active.insert(cow[ind]);
                ind++;
        }

        for (auto it=active.begin(); it!=active.end(); it++) {
            if (it->second>=chicken[i]) {
                cnt++;
                active.erase(it);
                break;
            }
            else if (it->second<chicken[i]) {
                active.erase(it);
            }
        }

    }
    cout << cnt;
}

/*
2 2
3
5
0 6
1 3

3 3
1
2
3
0 2
0 3
0 1

5 4
7
8
6
2
9
2 5
4 9
0 3
8 13
*/
