#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long

ll N, K, dp[(1<<16)][17]={}, cows[17], ans=0;

bool pass(int a, int b) {
    if (a==b) return false;
    if (abs(cows[a]-cows[b])>K) return true;
    else return false;
}

int main()
{
    cin >> N >> K;
    for (ll i=0; i<N; i++) cin >> cows[i];

    for (ll i=0; i<N; i++) dp[(1<<i)][i]=1;

    for (ll i=0; i<(1<<N); i++) {
        for (ll j=0; j<N; j++) {
            if (dp[i][j]) continue; //이미 계산.
            if (i&(1<<j)) {
                for (ll c=0; c<N; c++) {
                    int temp=i&(~(1<<j));
                    if (pass(j, c)) dp[i][j]+=dp[temp][c];
                }
            }
        }
    }

    for (ll i=0; i<N; i++) {
        ans+=dp[(1<<N)-1][i];
    }
    cout << ans;
}
