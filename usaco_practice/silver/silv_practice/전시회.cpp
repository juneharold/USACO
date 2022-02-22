#include <iostream>
#include <algorithm>
using namespace std;
#define f first
#define s second
#define ll long long

ll N, pfs[500005]={};
pair<ll, ll> art[500005]={};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i=1; i<=N; i++) cin >> art[i].f >> art[i].s;
    sort(&art[1], &art[N+1]);

    ll g=-1e18, ans=0;
    for (int i=1; i<=N; i++) {
        pfs[i]=pfs[i-1]+art[i].s;
        g=max(g, art[i].f-pfs[i-1]);
        ans=max(ans, pfs[i]-art[i].f+g);
    }

    cout << ans;
}
