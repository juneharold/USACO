#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long

int n, a[200005]={}, nxt[200005]={}, vst[200005]={}, dp[200005]={};
vector<int> path;

int dfs(int cur) {
    vst[cur]=1;
    path.push_back(cur);
    if (vst[nxt[cur]]==1) {
        int idx=-1;
        for (int i=0; i<path.size(); i++) {
            if (path[i]==nxt[cur]) idx=i;
        }
        if (idx!=-1) return dp[cur]=-2e9; 
    }

    if (nxt[cur]>n || nxt[cur]<1) {
        dp[cur]=0;
    }
    else if (vst[nxt[cur]]==0) {
        dp[cur]+=dfs(nxt[cur]);
    }
    return dp[cur]+1;
}

int main()
{
    int T; cin >> T;
    while (T--) {
        cin >> n;
        vector<int> start(n+1);
        for (int i=1; i<=n; i++) start[i]=1;
        for (int i=1; i<=n; i++) {
            cin >> a[i]; 
            nxt[i]=i+a[i];
            if (1<=i+a[i] && i+a[i]<=n) start[i+a[i]]=0;
        }
        
        //fill(&dp[0], &dp[n+1], -1);
        for (int i=1; i<=n; i++) {
            dfs(i);
            path.clear();
        }

        int cnt=0; // number of nodes in trees that end. 
        for (int i=1; i<=n; i++) {
            if (dp[i]>=0) cnt++;
        }
        //cout << cnt << endl;

        int ans=0;
        if (dp[1]>=0) { // naturally ends game
            ans+=(n-dp[1]-1)*(2*n+1);
            cout << ans << endl;
            int cur=1;
            while (1<=cur && cur<=n) {
                ans+=dp[cur];
                cout << ans << endl;
                ans+=cnt-dp[1]-1;
                cout << ans << endl;
                ans+=n+1;
                cout << ans << endl;
                cur=nxt[cur];
            }
        }
        else {
            int cur=1;
            fill(&vst[0], &vst[n+1], 0);
            while (1<=cur && cur<=n) {
                if (vst[cur]==1) break;
                vst[cur]=1;
                ans+=cnt;
                ans+=n+1;
                cur=nxt[cur];
            }
        }
        cout << ans << "\n";
    }
}

/*

1
3
1 -2 -1

1
4
-1 4 -2 1

1
5
1 1 1 1 -4

1
5
1 1 1 1 1

*/