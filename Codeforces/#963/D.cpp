#include <iostream>
#include <algorithm>
using namespace std;
const int nmax=5e5+5;

int N, K, a[nmax], dp[nmax]={};

void solve() {
    cin >> N >> K;
    for (int i=1; i<=N; i++) cin >> a[i];

    int need=N%K;
    if (need==0) need=K;
    need=(need+2)/2;

    int lo=1, hi=1e9;
    while (lo<hi) {
        int mid=(lo+hi)/2+1;
        dp[0]=(a[1]>=mid);
        for (int i=1; i<N; i++) {
            if (i%K==0) dp[i]=max((i-K>=0 ? dp[i-K] : 0), (int)(a[i+1]>=mid));
            else dp[i]=max((i-K>=0 ? dp[i-K] : 0), dp[i-1]+(a[i+1]>=mid));
        }
        if (dp[N-1]>=need) lo=mid;
        else hi=mid-1;
    }
    cout << lo << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
