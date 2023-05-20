#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
using namespace std;
#define f first
#define s second

int nx[200005]={}, vst[200005]={}, start[200005]={}, count_component=0, count_cycle2=0;
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
            if (path.size()-idx==2) count_cycle2++;
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
            cin >> nx[i];
            start[nx[i]]=1;
        }

        for (int i=1; i<=n; i++) {
            if (start[i]==0 && vst[i]==0) {
                count_component++;
                dfs(i);
            }
            path.clear();
        }
        for (int i=1; i<=n; i++) {
            if (vst[i]==0) {
                count_component++;
                dfs(i);
            }
            path.clear();
        }

        //cout << count_component-count_cycle2+1 << ' ' << count_component << "\n";
        ans.push_back(make_pair(count_component+min(0, -count_cycle2+1), count_component));
        //cout << count_component << ' ' << count_cycle2 << "\n";

        // initialize global variables
        for (int i=1; i<=n; i++) {
            vst[i]=0;
            nx[i]=0;
            start[i]=0;
        }
        count_component=0, count_cycle2=0;
    }

    for (int i=0; i<ans.size(); i++) cout << ans[i].f << ' ' << ans[i].s << "\n";
}

/*
1
6
5 3 4 1 1 2 
*/