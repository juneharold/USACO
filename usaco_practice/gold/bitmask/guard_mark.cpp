#include <iostream>
#include <algorithm>
using namespace std;

struct COW {
    int h, w, s;
};
COW cow[21];
int N, H, dp[(1<<20)]={}, ans=0;

int main()
{
    freopen("guard.in", "r", stdin);
    freopen("guard.out", "w", stdout);
    cin >> N >> H;
    for (int i=0; i<N; i++) cin >> cow[i].h >> cow[i].w >> cow[i].s;

    for (int i=0; i<N; i++) {
        dp[(1<<i)]=cow[i].s;
    }

    for (int i=0; i<(1<<N); i++) {
        if (dp[i]) continue;
        for (int j=0; j<N; j++) {
            if (i&(1<<j)) {
                int bef=i^(1<<j);
                if (dp[bef]>=cow[j].w) dp[i]=max(dp[i], min(dp[bef]-cow[j].w, cow[j].s));
            }
        }
        int height=0;
        for (int p=0; p<N; p++) {
            if (i&(1<<p)) height+=cow[p].h;
        }
        if (height>=H) ans=max(ans, dp[i]);
    }
    if (ans==0) cout << "Mark is too tall";
    else cout << ans;
}
