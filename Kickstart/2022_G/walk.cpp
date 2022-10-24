#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
#define ll long long
#define f first
#define s second
#define pii pair<ll, ll>



int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll T; cin >> T;
    for (ll t=1; t<=T; t++) {
        ll me[35]={}, steps[35]={};
        ll M, N, P; cin >> M >> N >> P;
        for (ll i=1; i<=M; i++) {
            if (i==P) {
                for (ll j=1; j<=N; j++) cin >> me[j];
            }
            else {
                for (ll j=1; j<=N; j++) {
                    ll a; cin >> a;
                    steps[j]=max(steps[j], a);
                }
            }
        }
        ll ans=0;
        for (ll j=1; j<=N; j++) {
            if (steps[j]>me[j]) ans+=steps[j]-me[j];
        }
        cout << "Case #" << t << ": " << ans << "\n";
    }
}

/*
1
3
10 100 10
3
10 100 10
4
*/
