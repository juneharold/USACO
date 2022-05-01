#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int arr[505]={}, loc[505]={}, in[505]={}, adj[505][505]={};

int main()
{
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        for (int i=1; i<=N; i++) {
            cin >> arr[i];
            loc[arr[i]]=i;
        }
        for (int i=1; i<=N; i++) {
            for (int j=i+1; j<=N; j++) {
                adj[arr[i]][arr[j]]=1;
                in[arr[j]]++;
            }
        }
        int M; cin >> M;
        for (int i=0; i<M; i++) {
            int a, b; cin >> a >> b;
            if (loc[a]>loc[b]) swap(a, b);
            adj[a][b]=0;
            adj[b][a]=1;
            in[b]--;
            in[a]++;
        }

        vector<int> ans;
        queue<int> q;
        for (int i=1; i<=N; i++) if (in[arr[i]]==0) q.push(arr[i]);
        while (!q.empty()) {
            int cur=q.front();
            q.pop();
            ans.push_back(cur);
            for (int i=1; i<=N; i++) {
                if (adj[cur][i]==1) {
                    in[i]--;
                    if (in[i]==0) q.push(i);
                }
            }
        }

        if (ans.size()!=N) cout << "IMPOSSIBLE";
        else for (int x: ans) cout << x << " ";
        cout << "\n";

        fill(&in[0], &in[501], 0);
        fill(&adj[0][0], &adj[501][501], 0);
    }
}
