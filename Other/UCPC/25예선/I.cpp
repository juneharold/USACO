#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

map<pii, int> mp;
int dx[4]={0, 0, 1, -1}, dy[4]={1, -1, 0, 0};
multiset<pii> points;
void dfs(int x, int y) {
    mp[make_pair(x, y)]=1;
    for (int i=0; i<4; i++) {
        int nx=x+dx[i], ny=y+dy[i];
        if (points.find(make_pair(nx, ny))==points.end()) continue;
        if (mp[make_pair(nx, ny)]==0) dfs(nx, ny);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    vector<int> y(N+1, 0);
    for (int i=1; i<=N; i++) cin >> y[i];

    int x=0, prev=1e9+1;
    for (int i=1; i<=N; i++) {
        if (y[i]<=prev) {
            x++;
        }
        points.insert({x, y[i]});
        mp[make_pair(x, y[i])]=0;
        prev=y[i];
    }
    //for (auto x: points) cout << x.fs << ' ' << x.sc << endl;
    int cnt=0;
    for (auto [a, b]: points) {
        if (mp[make_pair(a, b)]==1) continue;
        dfs(a, b);
        cnt++;
    }
    cout << cnt << "\n" << N;
}
