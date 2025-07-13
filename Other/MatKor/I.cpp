#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

int P[11], Q[11];

double prob(int p, int q, int k) {
    double pp=p, qq=(double)q;
    double a[2]={pp/(pp+qq), qq/(pp+qq)};
    return a[k];
}

double dp[nmax]={};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int i=1; i<=10; i++) cin >> P[i] >> Q[i];
    P[0]=1, Q[0]=0;
    int N; cin >> N;
    vector<int> a(N+1);
    for (int i=1; i<=N; i++) {
        char c; cin >> c;
        a[i]=c-'0';
    }

    for (int i=0; i<N; i++) {
        if (a[i+1]==a[i+2]) {
            dp[i+2]+=(dp[i]+1)*prob(P[a[i+1]], Q[a[i+1]], 1);
            dp[i+1]+=(dp[i]+1)*prob(P[a[i+1]], Q[a[i+1]], 0);
        }
        else {
            dp[i+1]+=(dp[i]+1)*prob(P[a[i+1]], Q[a[i+1]], 0)+(dp[i]+2)*prob(P[a[i+1]], Q[a[i+1]], 1);
        }
    }
    cout << dp[N];
}
