#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

const int N=5e4+5;
set<int> bess, b1, b2;
int elsie[N]={};

int main()
{
    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);
    int n; cin >> n;
    for (int i=1; i<=2*n; i++) bess.insert(i);
    for (int i=1; i<=n; i++) {
        cin >> elsie[i];
        bess.erase(elsie[i]);
    }

    int idx=1;
    for (int i=1; i<=2*n; i++) {
        if (bess.count(i)) {
            if (idx<=n/2) b2.insert(i);
            else b1.insert(i);
            idx++;
        }
    }

    int ans=0;
    for (int i=1; i<=n; i++) {
        int e=elsie[i];
        if (i<=n/2) {
            set<int>::iterator it;
            it=b1.lower_bound(e);
            if (*it>e) {
                b1.erase(*it);
                ans++;
            }
        }
        else {
            set<int>::iterator it;
            it=b2.lower_bound(e);
            if (it==b2.begin()) continue;
            it--;
            if (*it<e) {
                b2.erase(*it);
                ans++;
            }
        }
    }
    cout << ans;
}

/*
4
8
6
1
2
*/
