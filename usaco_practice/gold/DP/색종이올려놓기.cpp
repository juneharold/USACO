#include <iostream>
#include <algorithm>
using namespace std;
#define f first
#define s second

int N, dp[105];
pair<int, int> p[105];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i=1; i<=N; i++) {
        int x, y; cin >> x >> y;
        p[i].f=min(x, y); p[i].s=max(x, y);
    }
    sort(&p[1], &p[N+1]);

    int ans=1;
    for (int i=1; i<=N; i++) {
        dp[i]=1;
        for (int j=1; j<i; j++) {
            if (p[i].f>=p[j].f && p[i].s>=p[j].s) {
                dp[i]=max(dp[i], dp[j]+1);
            }
        }
        ans=max(ans, dp[i]);
    }
    cout << ans;

}
