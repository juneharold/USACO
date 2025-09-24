#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=998244353, INF=9e18;

ll P;
vector<ll> object[31];
ll dp[31][3005]={};

bool is_valid(ll N, ll x, vector<vector<ll>> &to) {
    for (ll i=0; i<N; i++) {
        if ((1<<i)&x) {
            for (ll nx: to[i+1]) {
                if (!((1<<(nx-1))&x)) return false;
            }
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll N, M, X, Y;
    cin >> P;
    for (ll i=1; i<=P; i++) {
        cin >> N >> M;
        vector<ll> S(N+1);
        for (ll j=1; j<=N; j++) cin >> S[j];
        vector<vector<ll>> to(N+1, vector<ll>(0, 0));
        for (ll j=1; j<=M; j++) {
            cin >> X >> Y;
            to[Y].push_back(X);
        }

        for (ll j=0; j<(1<<N); j++) {
            //cout << N <<  ' ' << j << ' ' << is_valid(N, j, to) << endl;
            if (!is_valid(N, j, to)) continue;
            ll sum=0;
            for (ll k=0; k<N; k++) {
                if ((1<<k)&j) sum+=S[k+1];
            }
            object[i].push_back(sum);
        }
    }


    dp[0][0]=1;
    for (ll i=1; i<=P; i++) {
        for (ll j=0; j<object[i].size(); j++) {
            ll score=object[i][j];
            //cout << score << ' ' ;
            for (ll k=100*P; k>=0; k--) {
                if (k-score>=0) dp[i][k]+=dp[i-1][k-score];
                dp[i][k]%=MOD;
            }
        }
        //cout << endl;
    }

    //cout << dp[P][100] << ' ' << dp[P][200] << ' ' << dp[P][300] << endl;

    ll ans=0;
    for (ll i=0; i<=100*P; i++) ans=(ans+dp[P][i]*i)%MOD;
    cout << ans;
}
