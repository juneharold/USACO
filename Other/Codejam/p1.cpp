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

bool check(string s) {
    bool ret=true;
    for (int i=0; i<26; i++) {
        char cc=i+65;
        bool exist=false, different=false;
        for (int j=0; j<s.size(); j++) {
            if (s[j]==cc) {
                if (!exist) exist=true;
                else if (exist && different) ret=false;
            }
            else if (exist) different=true;
        }
    }
    return ret;
}

string blocks[105], ans="";
pair<char, char> se[105];
vector<int> adj[105];
int visit[105]={}, sz=0;

void dfs(string s, int cur) {
    //cout << cur << endl;
    string ns=s+blocks[cur];
    if (!check(ns)) return;
    if (check(ns) && ns.size()==sz) {
        ans=ns;
        return;
    }
    visit[cur]=1;
    for (int i=0; i<adj[cur].size(); i++) {
        int nx=adj[cur][i];
        //cout << nx << endl;
        if (visit[nx]==0) dfs(ns, nx);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    for (int t=1; t<=T; t++) {
        int N; cin >> N;
        bool pass=true;
        for (int i=1; i<=N; i++) {
            cin >> blocks[i];
            if(!check(blocks[i])) pass=false;
            se[i]={blocks[i][0], blocks[i][blocks[i].size()-1]};
            sz+=blocks[i].size();
        }
        if (!pass) {
            cout << "Case #" << t << ": IMPOSSIBLE\n";
            continue;
        }

        for (int i=1; i<=N; i++) {
            for (int j=1; j<=N; j++) {
                if (i==j) continue;
                if (se[i].s==se[j].f) adj[i].push_back(j);
            }
        }

        for (int i=1; i<=N; i++) {
            dfs("", i);
            fill(&visit[1], &visit[N+1], 0);
            if (ans.size()==sz) {
                cout << "Case #" << t << ": " << ans << "\n";
                break;
            }
            ans="";
        }
        for (int i=1; i<=N; i++) adj[i].clear();
        sz=0;
    }
}

/*
1
5
CODE JAM MIC EEL ZZZZZ
*/
