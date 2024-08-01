#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fs first
#define sc second
const int nmax=2e5+5, sqrmax=300;

int n, q, a[nmax], ans[nmax];
vector<int> pos[nmax], reva[nmax];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> q;
    for (int i=1; i<=n; i++) cin >> a[i];

    ordered_set OS;
    for (int i=1; i<=n; i++) {
        OS.insert(i);
        reva[a[i]].push_back(i);
        pos[i].push_back(1);
    }
    for (int level=2; level<=n; level++) {
        for (int k=1; k<=n; k++) {
            if (pos[k].back()==-1) break;
            int ord=OS.order_of_key(pos[k].back());
            auto it=OS.find_by_order(ord+k-1);
            if (it!=OS.end() && *it+1<=n) pos[k].push_back(*it+1);
            else pos[k].push_back(-1);
        }
        for (int i: reva[level-1]) OS.erase(i);
    }
    /*cout << endl;
    for (int k=1; k<=n; k++) {
        for (int i: pos[k]) cout << i << ' ';
        cout << endl;
    }*/

    int i, x;
    while (q--) {
        cin >> i >> x;
        int lo=0, hi=pos[x].size()-2;
        while (lo<hi) {
            int mid=(lo+hi+1)/2;
            if (pos[x][mid]>i) hi=mid-1;
            else lo=mid;
        }
        //cout << lo+1 << endl;
        if (lo+1<=a[i]) cout << "YES\n";
        else cout << "NO\n";
    }
}
/*
4 1
2 1 2 1
4 3


5 0 
1 2 3 4 5
*/