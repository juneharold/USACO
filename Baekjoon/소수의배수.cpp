#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

bool oddbits(ll n) {
    int cnt=0;
    while (n) {
        if (n%2) cnt++;
        n/=2;
    }
    if (cnt%2) return true;
    else return false;
}

int main()
{
    ll n, m; cin >> n >> m;
    vector<int> p(n, 0);
    for (int i=0; i<n; i++) cin >> p[i];

    ll ans=0;
    for (int i=1; i<(1<<n); i++) {
        ll res=1;
        for (int j=0; j<n; j++) {
            if (i&(1<<j)) res*=p[j];
        }
        if (oddbits(i)) ans+=m/res;
        else ans-=m/res;
    }
    cout << ans;
}