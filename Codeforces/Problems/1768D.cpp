#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int p[200005]={}, vst[200005]={};

void dfs(int cur, int group) {
    vst[cur]=group;
    if (vst[p[cur]]==0) dfs(p[cur], group);
}

void solve() {
    int n; cin >> n;
    vector<int> pos(n+1, 0);
    for (int i=1; i<=n; i++) {
        cin >> p[i];
        pos[p[i]]=i;
    }
    int cycle=0;
    for (int i=1; i<=n; i++) {
        if (vst[i]==0) dfs(i, ++cycle);
    }
    int ans=n-cycle+1;
    for (int i=1; i<n; i++) {
        if (vst[i]==vst[i+1]) ans=min(ans, n-cycle-1);
    }
    cout << ans << "\n";

    for (int i=1; i<=n; i++) {
        p[i]=0;
        vst[i]=0;
    }
}

int main()
{
    int T; cin >> T;
    while (T--) {
        solve();
    }
}
/*
1
6
3 6 2 5 4 1
*/

/*
1
4
2 4 3 1

1
8
1 3 7 6 8 5 2 4

1
8
1 6 7 2 3 5 8 4

1
8
1 7 5 8 2 6 3 4
*/

