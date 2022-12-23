#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define f first
#define s second

ll dp[205][205][205]={}, dp2[2005][2005]={};
pair<ll, pair<ll, ll> > XCP[2005];

int main()
{
    ll N, A, B; cin >> N >> A >> B;
    for (ll i=1; i<=N; i++) cin >> XCP[i].s.s >> XCP[i].s.f >> XCP[i].f;
    sort(&XCP[1], &XCP[N+1]);

    if (B==0) {
        fill(&dp2[0][0], &dp2[2003][2003], -1e9);
        dp2[0][A]=0;
        for (ll i=0; i<=N-1; i++) {
            for (ll j=0; j<=A; j++) { // number of mooney left
                if (dp2[i][j]!=-1e9) {
                    // case 1: don't choose (i+1)th cow
                    dp2[i+1][j]=max(dp2[i+1][j], dp2[i][j]);

                    // case 2: choose (i+1)th cow
                    ll mooney_used=XCP[i+1].s.f;
                    if (j-mooney_used<0) continue;
                    dp2[i+1][j-mooney_used]=max(dp2[i+1][j-mooney_used], dp2[i][j]+XCP[i+1].s.s);
                }
            }
        }

        ll ans=0;
        for (ll j=0; j<=A; j++) ans=max(ans, dp2[N][j]);
        cout << ans;
        exit(0);
    }

    fill(&dp[0][0][0], &dp[203][203][203], -1e9);
    dp[0][A][B]=0;
    for (ll i=0; i<=N-1; i++) {
        for (ll j=0; j<=A; j++) { // number of mooney left
            for (ll k=0; k<=B; k++) { // number of ice cream left
                if (dp[i][j][k]!=-1e9) {
                    // case 1: don't choose (i+1)th cow
                    dp[i+1][j][k]=max(dp[i+1][j][k], dp[i][j][k]);

                    // case 2: choose (i+1)th cow
                    ll ice_used, mooney_used;
                    if (k>XCP[i+1].f*XCP[i+1].s.f) { //if discount greater than cost
                        ice_used=XCP[i+1].f*XCP[i+1].s.f;
                        mooney_used=0;
                    }
                    else { // use maximum number of ice cream
                        ice_used=k/XCP[i+1].f*XCP[i+1].f;
                        mooney_used=XCP[i+1].s.f-k/XCP[i+1].f;
                    }
                    if (j-mooney_used<0) continue;
                    dp[i+1][j-mooney_used][k-ice_used]=max(dp[i+1][j-mooney_used][k-ice_used], dp[i][j][k]+XCP[i+1].s.s);
                }
            }
        }
    }
    ll ans=0;
    for (ll j=0; j<=200; j++) { // number of mooney left
        for (ll k=0; k<=200; k++) { // number of ice cream left
            ans=max(ans, dp[N][j][k]);
        }
    }
    cout << ans;
}

/*
*/
