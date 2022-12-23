#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

ll X[100005]={}, pfs[100005]={};

int main()
{
    ll R, L, B; cin >> R >> L >> B;
    for (int i=1; i<=R; i++) cin >> X[i];
    for (int i=1; i<=R; i++) pfs[i]=pfs[i-1]+X[i];

    int l=1, r=1, ans=0;
    while (l<=r && r<=R) {
        int a=X[(r-l)/2+l], k=(r-l)/2+l;
        ll dist=(k-l+1)*a-(pfs[k]-pfs[l-1])+(pfs[r]-pfs[k])-(r-k)*a;

        if (abs(dist)<=B && r<R) {
            ans=max(ans, r-l+1);
            r++;
        }
        else if (abs(dist)<=B && r==R) {
            ans=max(ans, r-l+1);
            l++;
        }
        else {
            l++;
        }
    }
    cout << ans;
}
