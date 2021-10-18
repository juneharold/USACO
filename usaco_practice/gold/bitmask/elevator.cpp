#include <iostream>
#include <algorithm>
using namespace std;
#define f first
#define s second

int N, X, w[21];
pair<int, int> dp[(1<<20)]; //엘베 운행 횟수, 실은 무게

int main()
{
    cin >> N >> X;
    for (int i=0; i<N; i++) cin >> w[i];

    fill(&dp[0], &dp[(1<<20)], make_pair(1e9, 1e9));

    dp[0]={1, 0};

    for (int cur=0; cur<(1<<N); cur++) {
        for (int i=0; i<N; i++) {
            if (cur&(1<<i)) {
                int bef=cur&(~(1<<i));
                int num=dp[bef].f, weight=dp[bef].s;
                if (weight+w[i]<=X) dp[cur]=min(dp[cur], {num, weight+w[i]});
                else dp[cur]=min(dp[cur], {num+1, w[i]});
            }
        }
    }

    cout << dp[(1<<N)-1].f;

}
