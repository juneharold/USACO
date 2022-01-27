#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

const int MAX=1e5+5;
ll N, piece[MAX*3]={}, pfs[MAX*3]={};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i=1; i<=N; i++) cin >> piece[i];
    for (int i=N+1; i<=3*N; i++) piece[i]=piece[i-N];

    for (int i=1; i<=3*N; i++) pfs[i]=pfs[i-1]+piece[i];

    ll l=1, r=1, ans=0;
    while (l<=r && r<=2*N-1) {
        ll p1=pfs[r]-pfs[l-1], p2=0, p3=0;

        ll hi=l+N-1, lo=r+1;
        while (lo<hi) {
            ll mid=(hi+lo)/2;
            p2=pfs[mid]-pfs[r];

            if (p1<=p2) hi=mid;
            else lo=mid+1;
        }
        p2=pfs[lo]-pfs[r];
        p3=pfs[l+N-1]-pfs[lo];

        if (p1<=p2 && p1<=p3) {
            ans=max(ans, p1);
            r++;
        }
        else {
            l++;
        }
    }
    cout << ans;
}
