#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX=14;
int N, M, C, dp[(1<<MAX)][11][21]={}; //현재보석조합, 현재가방, 남은공간
int diamond[MAX]={};

int solve (int cur, int idx, int cap) {
    if (cur==(1<<MAX)-1 || idx==M) return 0;

    int &ret=dp[cur][idx][cap];
    if (ret!=-1) return ret;

    ret=0;

    for (int i=0; i<N; i++) {
        if ((cur&(1<<i)) || cap<diamond[i]) continue;
        int nx=cur|(1<<i);

        if (cap>=diamond[i]) {
            ret=max(ret, solve(nx, idx, cap-diamond[i])+1);
        }

        ret=max(ret, solve(nx, idx+1, C)+1);
    }
    return ret;
}

int main()
{
    cin >> N >> M >> C;
    for (int i=0; i<N; i++) cin >> diamond[i];
    fill(&dp[0][0][0], &dp[(1<<MAX)-1][10][21], -1);

    cout << solve(0, 0, C);

}
