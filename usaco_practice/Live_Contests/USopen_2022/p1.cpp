#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;
#define f first
#define s second
#define ll long long

const ll MAX=1e5+5;
ll N, sum=0, visit[MAX]={};
vector<pair<ll, ll>> graph[MAX], path;

void dfs(ll cur) {
    //cout << cur << endl;
    visit[cur]=1;
    for (ll i=0; i<graph[cur].size(); i++) {
        ll nx=graph[cur][i].f, w=graph[cur][i].s;
        path.push_back({cur, w});
        if (visit[nx]==1) {
            //cout << cur << " " << nx << endl;
            ll idx=-1;
            for (ll j=0; j<path.size(); j++) {
                //cout << path[j].f << " ";
                if (path[j].f==nx) idx=j;
            }
            //cout << idx << endl;
            //cout << endl;
            if (idx!=-1) {
                //cout << cur << " " << nx << endl;
                ll temp=1e18;
                for (ll j=idx; j<path.size(); j++) {
                    //cout << path[j].s << " ";
                    temp=min(temp, path[j].s);
                }
                //cout << temp << endl;
                //cout << temp << endl;
                sum-=temp;
            }
        }
        else {
            //path.push_back({cur, w});
            dfs(nx);
        }
    }
}


int main()
{
    cin >> N;
    for (ll i=1; i<=N; i++) {
        ll a, b; cin >> a >> b;
        graph[i].push_back({a, b});
        sum+=b;
        //graph[a].push_back({i, b});
    }

    for (ll i=1; i<=N; i++) {
        if (visit[i]==0) {
            dfs(i);
            path.clear();
        }
    }
    cout << sum;
    //cout << sum-subt;
}

/*
6
2 1
1 10
6 100
6 1000
6 10000
5 100000


6
3 1
1 10
2 100
2 1000
4 10000
4 100000
okay

4
4 200
1 10
1 100
1 1000
okay

5
2 1
3 10
4 100
5 1000
1 10000
*/
