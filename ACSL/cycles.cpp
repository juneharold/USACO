#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;
#define ll long long
#define f first
#define s second

vector<string> tokenize (string s) {
    vector<string> ret;
    string temp="";
    for (char x: s) {
        if (x==32) {
            ret.push_back(temp);
            temp="";
        }
        else temp+=x;
    }
    ret.push_back(temp);
    return ret;
}

vector<pair<int, int>> graph[27];
vector<pair<int, int>> path;
int ans=-1e9, visit[27]={};

void dfs(int cur, int weight) {
    visit[cur]=1;
    path.push_back({cur, weight});
    for (int i=0; i<graph[cur].size(); i++) {
        int nx=graph[cur][i].f, w=graph[cur][i].s;
        if (visit[nx]==1) {
            int temp=w, idx=-1;
            for (int j=0; j<path.size(); j++) if (path[j].f==nx) idx=j;

            if (idx!=-1) {
                for (int j=idx+1; j<path.size(); j++) {
                    temp+=path[j].s;
                }
                ans=max(ans, temp);
            }
        }
        else dfs(nx, w);
    }
    path.pop_back();
}

int main()
{
    string s; getline(cin, s);
    vector<string> inpt=tokenize(s);
    for (int i=0; i<inpt.size(); i+=2) {
        int a=inpt[i][0]-64, b=inpt[i][1]-64, w=stoi(inpt[i+1]);
        graph[a].push_back({b, w});
    }

    for (int i=1; i<=26; i++) {
        dfs(i, 0);
        fill(&visit[0], &visit[27], 0);
        path.clear();
    }

    if (ans==-1e9) cout << 0;
    else cout << ans;
}
