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

map<string, int> m;
string name[10000];
vector<int> child[10000];
set<string> ans[1000];
int mxlevel=0;

void dfs(int cur, int level) {
    ans[level].insert(name[cur]);
    mxlevel=max(mxlevel, level);
    for (auto nx: child[cur]) {
        dfs(nx, level+1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    while (T--) {
        int N, M, idx=1; cin >> N >> M;
        for (int i=0; i<N; i++) {
            string a, b; cin >> a >> b;
            if (m.count(a)==0) {
                m[a]=idx;
                name[idx]=a;
                idx++;
            }
            if (m.count(b)==0) {
                m[b]=idx;
                name[idx]=b;
                idx++;
            }
            child[m[a]].push_back(m[b]);
        }

        for (int i=0; i<M; i++) {
            string x; cin >> x;
            int start=m[x];
            dfs(start, 1);
            for (int i=mxlevel; i>=1; i--) {
                for (auto x: ans[i]) cout << "restart " << x << "\n";
                ans[i].clear();
            }
            cout << "exit\n";
            mxlevel=0;
        }

        //
        for (int i=0; i<=idx; i++) {
            child[i].clear();
            name[i]="";
        }
        m.clear();
    }
}
/*
1
5 2
a.exe b.exe
a.exe c.exe
b.exe d.exe
b.exe e.exe
c.exe f.exe
b.exe
a.exe
*/
