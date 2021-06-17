#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

multiset <int> room[1005];

int main()
{
    //freopen("cbarn.in", "r", stdin);
    //freopen("cbarn.out", "w", stdout);
    int n; cin >> n;
    pair<int, int> prev={-1, -1}; //위치와 d값
    for (int i=0; i<n; i++) {
        int a; cin >> a;
        for (int j=0; j<a; j++) room[i].insert(0);
        if (prev.first==-1 and !room[i].empty()) prev={i, 0};
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (room[j].empty()) {
                if (prev.first>j) {
                    int diff=n-prev.first+j;
                    room[j].insert(prev.second+diff);
                    room[prev.first].erase(room[prev.first].begin());
                }
                else {
                    int diff=j-prev.first;
                    room[j].insert(prev.second+diff);
                    room[prev.first].erase(room[prev.first].begin());
                }
                prev={j, *room[j].begin()};
            }
            else if (room[j].size()!=0) {
                prev={j, *room[j].begin()};
            }

            for (int k=0; k<n; k++) cout << room[k].size() << " ";
            cout << "\n";
        }
    }

    long long ans=0;
    for (int i=0; i<n; i++) {
        ans+=(*room[i].begin())*(*room[i].begin());
    }
    cout << ans;
}

/*
3
2
0
1

5
1
1
1
1
1
*/
