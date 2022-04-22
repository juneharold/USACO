#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int visit[100005]={}, from[100005]={};
queue<int> q;
vector<int> path;

int main()
{
    int N, K; cin >> N >> K;
    fill(visit, visit+100005, -1);

    q.push(N);
    visit[N]=0;
    while (!q.empty()) {
        int cur=q.front();
        q.pop();
        if (cur+1<100001 && visit[cur+1]==-1) {
            visit[cur+1]=visit[cur]+1;
            from[cur+1]=cur;
            q.push(cur+1);
        }
        if (cur-1>=0 && visit[cur-1]==-1) {
            visit[cur-1]=visit[cur]+1;
            from[cur-1]=cur;
            q.push(cur-1);
        }
        if (cur*2<100001 && visit[cur*2]==-1) {
            visit[cur*2]=visit[cur]+1;
            from[cur*2]=cur;
            q.push(cur*2);
        }
    }

    int cur=K;
    while (true) {
        path.push_back(cur);
        if (cur==N) break;
        cur=from[cur];
    }

    cout << visit[K] << "\n";
    for (int i=path.size()-1; i>=0; i--) cout << path[i] << " ";
}
