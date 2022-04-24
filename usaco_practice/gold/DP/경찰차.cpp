#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define f first
#define s second

const int MAX=1005;
int N, W, dp[MAX][MAX]={};
pair<int, int> cases[MAX], from[MAX][MAX];
vector<int> path;

int dist(int a, int b, int type) {
    if (type==1 && b==0) return abs(cases[a].f-1)+abs(cases[a].s-1);
    if (type==2 && b==0) return abs(cases[a].f-N)+abs(cases[a].s-N);
    return abs(cases[a].f-cases[b].f)+abs(cases[a].s-cases[b].s);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> W;
    for (int i=1; i<=W; i++) cin >> cases[i].f >> cases[i].s;

    // dp solve
    fill(&dp[0][0], &dp[1001][1001], 2e9);
    dp[0][0]=0;
    for (int i=0; i<=W; i++) {
        for (int j=0; j<=W; j++) {
            if (i!=0 && i==j) continue;
            int nx=max(i, j)+1;
            if (dp[i][j]+dist(nx, i, 1)<dp[nx][j]) {
                dp[nx][j]=dp[i][j]+dist(nx, i, 1);
                from[nx][j]={i, j};
            }
            if (dp[i][j]+dist(nx, j, 2)<dp[i][nx]) {
                dp[i][nx]=dp[i][j]+dist(nx, j, 2);
                from[i][nx]={i, j};
            }
        }
    }

    // finding answer and backtracking
    int ans=2e9;
    pair<int, int> cur;
    for (int i=0; i<=W; i++) {
        if (dp[i][W]<ans) {
            ans=dp[i][W];
            cur={i, W};
        }
    }
    for (int j=0; j<=W; j++) {
        if (dp[W][j]<ans) {
            ans=dp[W][j];
            cur={W, j};
        }
    }

    int case_num=W;
    while (case_num>0){
        if (from[cur.f][cur.s].f<cur.f) path.push_back(1);
        else if (from[cur.f][cur.s].s<cur.s) path.push_back(2);
        case_num--;
        cur=from[cur.f][cur.s];
    }

    cout << ans << "\n";
    for (int i=path.size()-1; i>=0; i--) cout << path[i] << "\n";
}
