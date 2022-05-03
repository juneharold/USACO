#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
#define ll long long

ll N, mx=0, fw[200005]={}, a[100005]={}, pfs[100005]={};

ll query (ll p) {
    ll ret=0;
    while (p!=0) {
        ret+=fw[p];
        p-=(p&-p);
    }
    return ret;
}

void update(ll p, ll v) {
    while (p<=mx) {
        fw[p]+=v;
        p+=(p&-p);
    }
}

int main()
{
    ll X; cin >> N >> X;
    for (int i=1; i<=N; i++) {
        cin >> a[i];
        if (a[i]>=X) pfs[i]=pfs[i-1]+1;
        else pfs[i]=pfs[i-1]-1;
    }

    for (int i=1; i<=N; i++) {
        pfs[i]+=100000;
        mx=max(mx, pfs[i]);
    }

    ll ans=0;
    update(100000, 1);
    for (ll i=1; i<=N; i++) {
        ans+=query(pfs[i]);
        update(pfs[i], 1);
    }

    cout << ans;
    return 0;
}

/*
4 6
10
5
6
2
4 2
1
1
1
2
*/
