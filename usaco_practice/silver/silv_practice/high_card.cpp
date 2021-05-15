#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int elsie[50005]={};

int main()
{
    freopen("highcard.in", "r", stdin);
    freopen("highcard.out", "w", stdout);
    int n; cin >> n;
    set <int> bessie;
    for (int i=1; i<=2*n; i++) bessie.insert(i);
    for (int i=0; i<n; i++) {
        int c; cin >> c;
        elsie[i]=c;
        bessie.erase(c);
    }
    int ans=0;
    for (int i=0; i<n; i++) {
        set<int>::iterator it;
        it=bessie.lower_bound(elsie[i]);
        if (*it>elsie[i]) {
            bessie.erase(*it);
            ans++;
        }
        else {
            bessie.erase(bessie.begin());
        }
    }
    cout << ans;
}
