#include <iostream>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;
#define f first
#define s second

int N;
double dp[16][(1<<16)]={};
pair<int, int> pos[16];

double distance(int i, int j) {
    double xx=pow(pos[i].f-pos[j].f, 2);
    double yy=pow(pos[i].s-pos[j].s, 2);
    return sqrt(xx+yy);
}

double solve(int cur, int state) {
    if (dp[cur][state]!=-1) return dp[cur][state];
    if (state==(1<<N)-1) {
        return distance(cur, 0);
    }
    dp[cur][state]=1e18;
    for (int i=0; i<N; i++) {
        if (state&(1<<i)) continue;
        int nxstate=state|(1<<i);
        dp[cur][state]=min(dp[cur][state], solve(i, nxstate)+distance(i, cur));
    }
    return dp[cur][state];
}

int main()
{
    cin >> N;
    for (int i=0; i<N; i++) cin >> pos[i].f >> pos[i].s;
    fill(&dp[0][0], &dp[15][(1<<16)], -1);
    cout << fixed << setprecision(6) << solve(0, 1);
}