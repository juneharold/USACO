#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
#define ll long long
#define f first
#define s second
#define pii pair<ll, ll>

int S[2505]={}, keys[2505]={}, dp[2505][2505]={};
vector<int> pos[2505], nxt[2505][2505];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    for (int t=1; t<=T; t++) {
        int N, M; cin >> N;
        for (int i=1; i<=N; i++) cin >> S[i];
        cin >> M;
        for (int i=1; i<=M; i++) {
            cin >> keys[i];
            pos[keys[i]].push_back(i);
        }

        fill(&dp[0][0], &dp[N+1][M+1], 1e9);
        for (int i=1; i<=M; i++) {
            if (keys[i]==S[1]) dp[1][i]=0;
        }
        for (int i=1; i<=N; i++) {
            int idx=1e9;
            for (int j=1; j<=M; j++) {
                if (keys[j]==S[i+1]) idx=j;
                if (keys[j]==S[i] && idx!=1e9) nxt[i][j].push_back(idx);
            }
            idx=1e9;
            for (int j=M; j>=1; j--) {
                if (keys[j]==S[i+1]) idx=j;
                if (keys[j]==S[i] && idx!=1e9) nxt[i][j].push_back(idx);
            }
        }
        for (int i=2; i<=N; i++) {
            for (int j: pos[S[i-1]]) {
                for (int nx: nxt[i-1][j]) {
                    dp[i][nx]=min(dp[i][nx], dp[i-1][j]+abs(j-nx));
                }
            }
        }

        int ans=1e9;
        for (ll j=1; j<=M; j++) ans=min(ans, dp[N][j]);
        cout << "Case #" << t << ": " << ans << "\n";
        fill(&S[0], &S[N+1], 0);
        for(int i=1; i<=N; i++) for (int j=1; j<=M; j++) {
            nxt[i][j].clear();
            pos[i].clear();
        }
    }
}
