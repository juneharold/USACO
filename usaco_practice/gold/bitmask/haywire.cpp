#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, dp[1<<12];
vector<int> friends[13];

int bitcount(int A){
  if(A==0) return 0;
  return A%2 + bitcount(A / 2);
}

int add_hays (int cur, int cow) {
    int ret=0, order=bitcount(cur);

    for (int i=0; i<3; i++) {
        int target=friends[cow][i]-1;
        if (cur&(1<<target)) ret+=order;
        else ret-=order;
        //앞에 있는 친구 수만큼 더하고 없는 수만큼 index 빼기.
    }

    return ret;
}

int main()
{
    freopen("haywire.in", "r", stdin);
    freopen("haywire.out", "w", stdout);

    cin >> N;
    for (int i=0; i<N; i++) {
        int a, b, c; cin >> a >> b >> c;
        friends[i].push_back(a);
        friends[i].push_back(b);
        friends[i].push_back(c);
    }

    fill(&dp[0], &dp[1<<12], 1e9);
    dp[0]=0;

    for (int i=0; i<(1<<N); i++) {
        for (int c=0; c<N; c++) if (i&(1<<c)) {
            int bef=i^(1<<c);
            dp[i]=min(dp[i], dp[bef]+add_hays(bef, c));
        }
    }
    cout << dp[(1<<N)-1];
}
