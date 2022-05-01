#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <map>
#include <set>
using namespace std;
#define f first
#define s second
#define ll long long
#define db double

int N, points[1000][1000], dp[1000][1000]={}, from[1000][1000]={};


void dfs(int x, int y, int score) {
    if (x==N+1) return;
    // move left (x+1, y);
    if (score+points[x+1][y]>dp[x+1][y]) {
        dp[x+1][y]=score+points[x+1][y];
        from[x+1][y]=y;
        dfs(x+1, y, dp[x+1][y]);
    }
    // move right (x+1, y+1);
    if (score+points[x+1][y+1]>dp[x+1][y+1]) {
        dp[x+1][y+1]=score+points[x+1][y+1];
        from[x+1][y+1]=y;
        dfs(x+1, y+1, dp[x+1][y+1]);
    }
}

int main()
{
    int T; cin >> T;
    while (T--) {
        fill(&points[0][0], &points[1000][1000], -1);
        cin >> N;
        for (int i=1; i<=N+1; i++) {
            for (int j=1; j<=i; j++) cin >> points[i][j];
        }

        dfs(1, 1, points[1][1]);

        int ans=0, cur;
        pair<int, int> loc;
        for (int i=1; i<=N+1; i++) {
            if (dp[N+1][i]>ans) {
                ans=dp[N+1][i];
                cur=i;
            }
        }
        string path="";
        for (int i=N+1; i>=2; i--) {
            if (from[i][cur]==cur) path+='L';
            else path+='R';
            cur=from[i][cur];
        }

        for (int i=path.size()-1; i>=0; i--) cout << path[i];
        cout << " = " << ans;
    }
}

/*
1
4
4
3 6
9 1 2
5 8 10 7
10 8 6 8 10
*/
