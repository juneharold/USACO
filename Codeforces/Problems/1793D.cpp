#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
const ll nmax=200005;

ll p[nmax]={}, q[nmax]={}, pos1[nmax]={}, pos2[nmax]={};
vector<ll> prange[nmax]={}, qrange[nmax]={};

int main()
{
    ll n; cin >> n;
    for (ll i=1; i<=n; i++) {
        cin >> p[i];
        pos1[p[i]]=i;
    }
    for (ll i=1; i<=n; i++) {
        cin >> q[i];
        pos2[q[i]]=i;
    }

    ll ans=0;
    ll temp=min(pos1[1], pos2[1])-1;
    if (temp>0) ans+=(temp+1)*temp/2;
    temp=n-max(pos1[1], pos2[1]);
    if (temp>0) ans+=(temp+1)*temp/2;
    temp=max(pos1[1], pos2[1])-min(pos1[1], pos2[1])-1;
    if (temp>0) ans+=(temp+1)*temp/2;

    ll mn1=1e9, mn2=1e9, mx1=0, mx2=0;
    for (ll x=1; x<n; x++) {
        mn1=min(mn1, pos1[x]), mx1=max(mx1, pos1[x]);
        if (pos1[x+1]<mn1) prange[x+1]={pos1[x+1]+1, mn1, mx1, n};
        else if (pos1[x+1]>mx1) prange[x+1]={1, mn1, mx1, pos1[x+1]-1};

        mn2=min(mn2, pos2[x]), mx2=max(mx2, pos2[x]);
        if (pos2[x+1]<mn2) qrange[x+1]={pos2[x+1]+1, mn2, mx2, n};
        else if (pos2[x+1]>mx2) qrange[x+1]={1, mn2, mx2, pos2[x+1]-1};
    }
    prange[n+1]={1, 1, n, n};
    qrange[n+1]={1, 1, n, n};

    for (ll i=2; i<=n+1; i++) {
        if (prange[i].empty() || qrange[i].empty()) continue;
        ll cntl=min(prange[i][1], qrange[i][1])-max(prange[i][0], qrange[i][0])+1;
        ll cntr=min(prange[i][3], qrange[i][3])-max(prange[i][2], qrange[i][2])+1;
        if (cntl<=0 || cntr<=0) continue;
        ans+=cntl*cntr;
    }
    cout << ans;
}