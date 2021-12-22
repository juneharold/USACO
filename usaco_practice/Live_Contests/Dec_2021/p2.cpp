#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const long long MAX=1e5+5;
long long visit[MAX]={}, mindist_1[MAX]={}, mindist_N[MAX]={}; //0은 1번 노드가 속한 컴포넌트에서, 1은...
vector<long long> graph[MAX];

void dfs (long long cur, long long p) {
    visit[cur]=p;
    for (long long i=0; i<graph[cur].size(); i++) {
        long long nx=graph[cur][i];
        if (visit[nx]==0) dfs(nx, p);
    }
}

int main()
{
    long long T; cin >> T;
    for (long long t=1; t<=T; t++) {
        long long N, M; cin >> N >> M;
        for (long long i=0; i<M; i++) {
            long long a, b; cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        fill(&visit[0], &visit[N+1], 0);

        for (long long i=1; i<=N; i++) {
            if (visit[i]==0) dfs(i, i);
        }

        fill(&mindist_1[0], &mindist_1[N+1], 1e18);
        fill(&mindist_N[0], &mindist_N[N+1], 1e18);

        long long last_1=-1;
        for (long long i=1; i<=N; i++) {
            if (visit[i]==1) last_1=i;
            if (last_1!=-1) mindist_1[visit[i]]=min(mindist_1[visit[i]], (i-last_1)*(i-last_1));
        }
        last_1=-1;
        for (long long i=N; i>=1; i--) {
            if (visit[i]==1) last_1=i;
            if (last_1!=-1) mindist_1[visit[i]]=min(mindist_1[visit[i]], (i-last_1)*(i-last_1));
        }

        long long last_N=-1;
        for (long long i=1; i<=N; i++) {
            if (visit[i]==visit[N]) last_N=i;
            if (last_N!=-1) mindist_N[visit[i]]=min(mindist_N[visit[i]], (i-last_N)*(i-last_N));
        }
        last_N=-1;
        for (long long i=N; i>=1; i--) {
            if (visit[i]==visit[N]) last_N=i;
            if (last_N!=-1) mindist_N[visit[i]]=min(mindist_N[visit[i]], (i-last_N)*(i-last_N));
        }

        long long ans=1e18;
        for (long long i=1; i<=N; i++) {
            ans=min(ans, mindist_1[i]+mindist_N[i]);
        }
        cout << ans << "\n";

        for (long long i=1; i<=N; i++) graph[i].clear();
    }
}
