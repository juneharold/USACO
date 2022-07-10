#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

ll a[100005]={};

int main()
{
    ll N, S; cin >> N >> S;
    for (int i=1; i<=N; i++) cin >> a[i];

    ll l=1, r=1, sum=a[1], ans=1e9;
    while (l<=r && r<=N) {
        if (sum>=S) {
            ans=min(ans, r-l+1);
            if (l<r) {
                sum-=a[l];
                l++;
            }
            else if (l==r) {
                sum-=a[l];
                l++;
                r++;
            }
        }
        else {
            r++;
            sum+=a[r];
        }
    }
    if (ans==1e9) cout << 0;
    else cout << ans;
}
