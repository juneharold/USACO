#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, p[100005]={}, visit[100005]={};

int main()
{
    cin >> N;
    for (int i=1; i<=N; i++) cin >> p[i];
    fill(&visit[2], &visit[N+1], 1e9);
    queue<int> q; q.push(1);
    while(!q.empty()) {
        int cur=q.front();
        //cout << cur << endl;
        q.pop();
        if (p[cur]!=0 && visit[cur+p[cur]]>visit[cur]) {
            visit[cur+p[cur]]=visit[cur];
            q.push(cur+p[cur]);
        }
        else if (p[cur]==0) {
            //cout << cur << endl;
            for (int nx=cur+1; nx<=cur+6; nx++) {
                if (nx>N) continue;
                if (visit[nx]>visit[cur]+1) {
                    visit[nx]=visit[cur]+1;
                    q.push(nx);
                }
            }
        }
    }
    cout << visit[N];
}
