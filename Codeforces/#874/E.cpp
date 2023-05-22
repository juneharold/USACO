#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
using namespace std;
#define f first
#define s second

int nx[200005]={}, vst[200005]={}, cnt1=0, cnt2=0;
vector <int> graph[200005];
vector<int> path;

void dfs(int cur) {
    vst[cur]=1;
    path.push_back(cur);
    if (vst[nx[cur]]==1) {
        int idx=-1;
        for (int i=0; i<path.size(); i++) {
            if (path[i]==nx[cur]) idx=i;
        }
        if (idx!=-1) { // path[idx ~ path.size()-1]까지 cycle
            if (path.size()-idx==2) cnt2++;
            cnt1++;
        }
    }
    else dfs(nx[cur]);
}

int main()
{
    int T; cin >> T;
    vector<pair<int, int>> ans;
    while (T--) {
        int n; cin >> n;
        for (int i=1; i<=n; i++) {
            int x; cin >> x;
            nx[i]=x;
            graph[i].push_back(x);
            graph[x].push_back(i);
        }

        for (int i=1; i<=n; i++) {
            if (vst[i]==0) dfs(i);
            path.clear();
        }

        if (cnt2>1) {
            ans.push_back(make_pair(cnt1-cnt2+1, cnt1));
        }
        else {
            ans.push_back(make_pair(cnt1, cnt1));
        }

        // initialize global variables
        for (int i=1; i<=n; i++) {
            vst[i]=0;
            nx[i]=0;
            graph[i].clear();
        }
        cnt1=0, cnt2=0;
    }

    for (int i=0; i<ans.size(); i++) cout << ans[i].f << ' ' << ans[i].s << "\n";
}
