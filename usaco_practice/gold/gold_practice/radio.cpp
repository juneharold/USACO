#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define f first
#define s second

const int MAX=1005;
int N, M, dp[MAX][MAX]={};
pair<int, int> fj[MAX], bs[MAX];
string fjpath, bspath;

int solve(int a, int b) {
    if (a<0 || b<0) return 1e9;
    if (dp[a][b]!=1e9) return dp[a][b];

    int cost=(fj[a].f-bs[b].f)*(fj[a].f-bs[b].f)+(fj[a].s-bs[b].s)*(fj[a].s-bs[b].s);
    dp[a][b]=min(dp[a][b], solve(a-1, b-1)+cost);
    dp[a][b]=min(dp[a][b], solve(a, b-1)+cost);
    dp[a][b]=min(dp[a][b], solve(a-1, b)+cost);

    return dp[a][b];
}

void make_path() {
    for (int i=0; i<N; i++) {
        if (fjpath[i]=='N') {
            fj[i+1].f=fj[i].f;
            fj[i+1].s=fj[i].s+1;
        }
        if (fjpath[i]=='E') {
            fj[i+1].f=fj[i].f+1;
            fj[i+1].s=fj[i].s;
        }
        if (fjpath[i]=='W') {
            fj[i+1].f=fj[i].f-1;
            fj[i+1].s=fj[i].s;
        }
        if (fjpath[i]=='S') {
            fj[i+1].f=fj[i].f;
            fj[i+1].s=fj[i].s-1;
        }
    }

    for (int i=0; i<M; i++) {
        if (bspath[i]=='N') {
            bs[i+1].f=bs[i].f;
            bs[i+1].s=bs[i].s+1;
        }
        if (bspath[i]=='E') {
            bs[i+1].f=bs[i].f+1;
            bs[i+1].s=bs[i].s;
        }
        if (bspath[i]=='W') {
            bs[i+1].f=bs[i].f-1;
            bs[i+1].s=bs[i].s;
        }
        if (bspath[i]=='S') {
            bs[i+1].f=bs[i].f;
            bs[i+1].s=bs[i].s-1;
        }
    }

}

int main()
{
    freopen("radio.in", "r", stdin);
    freopen("radio.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> fj[0].f >> fj[0].s >> bs[0].f >> bs[0].s;
    cin >> fjpath >> bspath;

    make_path();

    fill(&dp[0][0], &dp[1004][1004], 1e9);
    dp[0][0]=0;

    cout << solve(N, M);
}
