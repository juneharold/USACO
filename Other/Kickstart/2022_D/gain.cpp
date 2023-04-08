#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
#define ll long long
#define f first
#define s second
#define pii pair<ll, ll>

ll pfsA[6005]={}, pfsB[6005]={}, Amax[3005]={}, Bmax[3005]={};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll T; cin >> T;
    for (ll t=1; t<=T; t++) {
        ll N, M, K; cin >> N;
        for (ll i=1; i<=N; i++) {
            ll x; cin >> x;
            pfsA[i]=pfsA[i-1]+x;
        }
        cin >> M;
        for (ll i=1; i<=M; i++) {
            ll x; cin >> x;
            pfsB[i]=pfsB[i-1]+x;
        }
        cin >> K;

        for (ll i=0; i<=K; i++) {
            for (ll j=0; j<=K; j++) {
                if (i+j>K) break;
                if (i+j<=N) Amax[i+j]=max(Amax[i+j], pfsA[i]+pfsA[N]-pfsA[N-j]);
                if (i+j<=M) Bmax[i+j]=max(Bmax[i+j], pfsB[i]+pfsB[M]-pfsB[M-j]);
            }
        }

        ll ans=0;
        for (ll i=0; i<=K; i++) {
            if (i<=N && K-i<=M) ans=max(ans, Amax[i]+Bmax[K-i]);
            if (i<=M && K-i<=N) ans=max(ans, Bmax[i]+Amax[K-i]);
        }
        cout << "Case #" << t << ": " << ans << "\n";

        fill(&pfsA[0], &pfsA[N+1], 0);
        fill(&pfsB[0], &pfsB[M+1], 0);
        fill(&Amax[0], &Amax[K+1], 0);
        fill(&Bmax[0], &Bmax[K+1], 0);
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
