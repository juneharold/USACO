#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
using namespace std;
#define f first
#define s second

int dp[3005]={}, pfs[3005][3005]={}, from[3005]={}; //친구 수의 합, a와b 사이 연결 갯수

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    for (int i=1; i<=N; i++) {
        int cnt=0;
        while (true) {
            int x; cin >> x;
            if (x==0) break;
            cnt++;
            pfs[i][x]++;
        }
    }
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            pfs[i][j]+=pfs[i][j-1];
        }
    }

    fill(&dp[1], &dp[N+1], 1e9);
    for (int i=1; i<=N; i++) {
        int sum=0;
        for (int j=i; j>=1; j--) {
            sum+=(i-j)-(pfs[j][i]-pfs[j][j])+pfs[j][j-1]-(pfs[j][i]-pfs[j][j]);
            if (dp[j-1]+sum<dp[i]) {
                dp[i]=dp[j-1]+sum;
                from[i]=j-1;
            }
        }
    }
    cout << dp[N] << "\n";
    vector<int> path;
    int pos=N;
    while (pos) {
        path.push_back(pos-from[pos]);
        pos=from[pos];
    }
    reverse(path.begin(), path.end());
    cout << path.size() << " ";
    for (int x: path) cout << x << " ";
}
