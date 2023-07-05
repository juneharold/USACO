#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define f first
#define s second

int dist[500005][2]={};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, k; cin >> n >> k;
    fill(&dist[0][0], &dist[500000][2], 1e9);
    queue<pair<int, int>> q;
    q.push({0, n});
    dist[n][0]=0;
    while (!q.empty()) {
        int nt=q.front().f+1, pos=q.front().s;
        q.pop();
        if (pos-1>=0 && dist[pos-1][nt%2]>nt) {
            dist[pos-1][nt%2]=nt;
            q.push({nt, pos-1});
        }
        if (pos+1<=500000 && dist[pos+1][nt%2]>nt) {
            dist[pos+1][nt%2]=nt;
            q.push({nt, pos+1});
        }
        if (pos*2<=500000 && dist[pos*2][nt%2]>nt) {
            dist[pos*2][nt%2]=nt;
            q.push({nt, pos*2});
        }
        
    }

    int pos=k, idx=1, ans=1e9, time=0;
    while (pos<=500000) {
        if (time%2 && dist[pos][time%2]<=time) {
            ans=min(ans, time);
        }
        if (time%2==0 && dist[pos][time%2]<=time) {
            ans=min(ans, time);
        }
        pos+=idx++;
        time++;
    }

    if (ans==1e9) cout << -1;
    else cout << ans;
}