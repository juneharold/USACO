#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAX=1005;
int H, G;
long long dp[MAX][MAX][2]={};
pair<int, int> h_loc[MAX];
pair<int, int> g_loc[MAX];

int energy(pair<int, int> a, pair<int, int> b) {
    int dx=a.first-b.first, dy=a.second-b.second;
    return pow(abs(dx), 2)+pow(abs(dy), 2);
}

int main()
{
    cin >> H >> G;
    for (int i=0; i<H; i++) cin >> h_loc[i].first >> h_loc[i].second;
    for (int i=0; i<G; i++) cin >> g_loc[i].first >> g_loc[i].second;

    for (int i=0; i<=H; i++) for (int j=0; j<=G; j++) {
        dp[i][j][0]=1e18; dp[i][j][1]=1e18;
    }

    dp[1][0][0]=0;
    for (int i=0; i<=H; i++) {
        for (int j=0; j<=G; j++) {
            if (i>=1 && j>=1) {
                int cost=energy(h_loc[i-1], g_loc[j-1]);
                dp[i][j][0]=min(dp[i][j][0], dp[i-1][j][1]+cost);
                dp[i][j][1]=min(dp[i][j][1], dp[i][j-1][0]+cost);
            }
            if (i>=2) {
                int cost=energy(h_loc[i-1], h_loc[i-2]);
                dp[i][j][0]=min(dp[i][j][0], dp[i-1][j][0]+cost);
            }
            if (j>=2) {
                int cost=energy(g_loc[j-1], g_loc[j-2]);
                dp[i][j][1]=min(dp[i][j][1], dp[i][j-1][1]+cost);
            }
        }
    }
    cout << dp[H][G][0];
}
