#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int MAX_N=1e5+5;
int N, K, cows[MAX_N], dp[MAX_N][25]={};
vector<int> graph[MAX_N];

int main()
{
    cin >> N >> K;
    for (int i=1; i<N; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i=1; i<=N; i++) {
        cin >> cows[i];
        dp[i][0]=cows[i];
        dp[i][1]+=dp[i][0];
    }

    for (int i=1; i<=N; i++) {
        for (int j=0; j<graph[i].size(); j++) {
            int nx=graph[i][j];
            dp[i][1]+=dp[nx][0];
        }
    }

    for (int j=2; j<=K; j++) {
        for(int i=1; i<=N; i++) {
            dp[i][j]=-(graph[i].size()-1)*(dp[i][j-2]);
            for (int k=0; k<graph[i].size(); k++) {
                int nx=graph[i][k];
                dp[i][j]+=dp[nx][j-1];
            }
        }
    }

    for(int i=1; i<=N; i++) {
        cout << dp[i][K] << "\n";
    }
}
