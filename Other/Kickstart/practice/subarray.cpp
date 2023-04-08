#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

ll pfs[100005]={}, cnt[20000005]={};
const int mx=1e7;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T; cin >> T;
    for (int t=1; t<=T; t++) {
        int N; cin >> N;
        for (int i=1; i<=N; i++) {
            int x; cin >> x;
            pfs[i]=pfs[i-1]+x;
        }

        ll ans=0;
        cnt[mx]++;
        for (int i=1; i<=N; i++) {
            for (int j=0; j*j<=mx; j++) {
                int need=pfs[i]-j*j+mx;
                if (need>=2*mx || need<0) continue;
                ans+=cnt[need];
            }
            cnt[pfs[i]+mx]++;
        }

        cout << "Case #" << t << ": " << ans << "\n";
        for (int i=0; i<=N; i++) cnt[pfs[i]+mx]=0;
        fill(&pfs[0], &pfs[100001], 0);
    }
}


/*
1
20
1 1 -2 23 -32 -31 99 -100 -39 45 -64 32 -64 -49 -16 100 31 25 36 32
*/
