#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int dp[2000][10001]={}, V[101]={}, C[101]={}, K[101]={};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, M; cin >> N >> M;
    for (int i=1; i<=N; i++) cin >> V[i] >> C[i] >> K[i];
    vector<pair<int, int>> items;
    items.push_back(make_pair(0, 0));
    for (int i=1; i<=N; i++) {
        int sum=0;
        for (int j=0; j<14; j++) {
            if (sum+(1<<j)<=K[i]) {
                items.push_back(make_pair(V[i]*(1<<j), C[i]*(1<<j)));
                sum+=(1<<j);
            }
        }
        items.push_back(make_pair(V[i]*(K[i]-sum), C[i]*(K[i]-sum)));
    }

    for (int i=1; i<items.size(); i++) {
        int v=items[i].first, c=items[i].second;
        for (int j=0; j<=M; j++) {
            dp[i][j]=dp[i-1][j];
            if (0<=j-v) dp[i][j]=max(dp[i][j], dp[i-1][j-v]+c);
        }
    }

    int ans=0;
    for (int j=0; j<=M; j++) ans=max(ans, dp[items.size()-1][j]);
    cout << ans;
}

/*
1 3
1 100 10
*/