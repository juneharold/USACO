#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

vector <int> graph[3005];
int visit[3005]={};
set <int> open;

void dfs(int cur) {
    visit[cur]=1;
    for (int i=0; i<graph[cur].size(); i++) {
        int next=graph[cur][i];
        if (visit[next]==0 and open.count(next)==1) dfs(next);
    }
}

int main()
{
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
    int n, m; cin >> n >> m;
    for (int i=1; i<=n; i++) open.insert(i);
    for (int i=0; i<m; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1);
    bool connected=true;
    for (int i=1; i<=n; i++) if (visit[i]==0) {
        connected=false;
        break;
    }
    if (connected==true) cout << "YES" << "\n";
    else cout << "NO" << "\n";
    fill(visit, visit+3000, 0);

    for (int i=0; i<n-1; i++) {
        int loc; cin >> loc;
        open.erase(loc);
        auto it=open.begin();
        dfs(*it);
        connected=true;
        for (int j=1; j<=n; j++) if (visit[j]==0 and open.count(j)==1) {
            connected=false;
            break;
        }
        if (connected==true) cout << "YES" << "\n";
        else cout << "NO" << "\n";
        fill(visit, visit+3000, 0);
    }
    int extra; cin >> extra;
    return 0;
}
