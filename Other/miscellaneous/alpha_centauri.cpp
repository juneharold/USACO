#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    while (T--) {
        int x, y; cin >> x >> y;
        y-=x;
        ll lo=1, hi=1e6;
        while (lo<hi) {
            ll mid=(lo+hi+1)/2;
            ll res=y-mid*(mid+1)/2-mid*(mid-1)/2;
            if (res>=0) lo=mid;
            else hi=mid-1;
        }
        int ans=2*lo-1, dist_left=y-lo*(lo+1)/2-lo*(lo-1)/2;
        if (dist_left%lo==0) {
            ans+=dist_left/lo;
        }
        else {
            ans+=dist_left/lo+1;
        }
        cout << ans << "\n";
    }
}
