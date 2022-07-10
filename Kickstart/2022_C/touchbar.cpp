#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
#define ll long long
#define f first
#define s second
#define pii pair<ll, ll>

ll S[2505]={}, dp[2505][2505]={};
vector<ll> num[2505];

int find_idx(int j, vector<ll> v) { //k는 v의 원소
    int lo=0, hi=v.size()-1;
    while (lo<hi) {
        int mid=(lo+hi)/2;
        if (j-v[mid]>0) lo=mid+1;
        else  hi=mid;
    }
    return lo;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll T; cin >> T;
    for (ll t=1; t<=T; t++) {
        ll N, M; cin >> N;
        for (ll i=1; i<=N; i++) cin >> S[i];
        cin >> M;
        ll mx=0;
        for (ll i=1; i<=M; i++) {
            ll x; cin >> x;
            num[x].push_back(i);
            mx=max(mx, x);
        }

        fill(&dp[0][0], &dp[N+3][M+3], 2e9);
        for (ll j: num[S[1]]) dp[1][j]=0;

        for (ll i=2; i<=N; i++) {
            for (ll j: num[S[i]]) {
                int k=find_idx(j, num[S[i-1]]), cnt=3;
                while (cnt--) {
                    if (k<0) break;
                    dp[i][j]=min(dp[i][j], dp[i-1][num[S[i-1]][k]]+abs(j-num[S[i-1]][k]));
                    k--;
                }
            }
        }

        ll ans=2e9;
        for (ll j=1; j<=M; j++) ans=min(ans, dp[N][j]);
        cout << "Case #" << t << ": " << ans << "\n";

        fill(&S[0], &S[N+1], 0);
        for (ll i=0; i<=mx; i++) num[i].clear();
    }
}
