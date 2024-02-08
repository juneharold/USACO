#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int cnt[1<<21]={}, dp1[1<<21][21]={}, dp2[1<<21][21]={};

void solve() {
    int n; cin >> n;
    vector<int> a(n+1);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    for (int j=0; j<=20; j++) {
        for (int i=0; i<(1<<20); i++) {
            if (j==0) {
                if (i&(1<<j)) {
                    dp1[i][j]=cnt[i]+cnt[i^(1<<j)];
                    dp2[i][j]=cnt[i];
                }
                else {
                    dp1[i][j]=cnt[i];
                    dp2[i][j]=cnt[i]+cnt[i^(1<<j)];
                }
            }
            else {
                if (i&(1<<j)) {
                    dp1[i][j]=dp1[i][j-1]+dp1[i^(1<<j)][j-1];
                    dp2[i][j]=dp2[i][j-1];
                }
                else {
                    dp1[i][j]=dp1[i][j-1];
                    dp2[i][j]=dp2[i][j-1]+dp2[i^(1<<j)][j-1];
                }
            }
        }
    }

    for (int i=1; i<=n; i++) {
        cout << dp1[a[i]][20] << ' ' << dp2[a[i]][20] << ' ' << n-dp1[a[i]^((1<<20)-1)][20] << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; //cin >> T;
    while (T--) {
        solve();
    }
}