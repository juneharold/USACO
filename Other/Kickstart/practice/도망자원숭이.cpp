#include <iostream>
#include <algorithm>
using namespace std;
#define f first
#define s second

int dp[505][505]={}, attack[505][505]={};
pair<int, int> order[505];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N, M, Q; cin >> N >> M >> Q;
    for (int i=1; i<=N; i++) {
        cin >> attack[i][i];
        order[i]={attack[i][i], i};
    }
    sort(&order[1], &order[N+1]);
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            dp[i][j]=1e9;
            attack[i][j]=max(attack[i][i], attack[j][j]);
        }
        dp[i][i]=attack[i][i];
    }
    for (int i=1; i<=M; i++) {
        int a, b, d; cin >> a >> b >> d;
        dp[a][b]=d+max(attack[a][a], attack[b][b]);
        dp[b][a]=d+max(attack[a][a], attack[b][b]);
    }

    for (int k=1; k<=N; k++) {
        for (int i=1; i<=N; i++) {
            for (int j=1; j<=N; j++) {
                int v=order[k].s, att=max(order[k].f, attack[i][j]);
                int dist=(dp[i][v]-attack[i][v])+(dp[v][j]-attack[v][j])+att;
                if (dist<dp[i][j]) {
                    dp[i][j]=dist;
                    attack[i][j]=att;
                }
            }
        }
    }

    for (int i=1; i<=Q; i++) {
        int a, b; cin >> a >> b;
        if (dp[a][b]>=1e9) cout << -1 << "\n";
        else cout << dp[a][b] << "\n";
    }
}
