#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector <int> graph[1005];
char seq[505]={};
int dirnum=0;
int n, m, k;

int dfs(int cur, int dirnum)
{
    if (dirnum==m) return cur;
    if (seq[dirnum]=='L') {
        int next=graph[cur][0];
        return dfs(next, dirnum+1);
    }
    else if (seq[dirnum]=='R') {
        int next=graph[cur][1];
        return dfs(next, dirnum+1);
    }
}

int visit[1005]={};
int func[1005]={};
int counter=0;
int check=0;
int from=0;
vector <int> path;

void cycle(int cur)
{
    visit[cur]=1;
    path.push_back(cur);
    int next=func[cur];
    if (counter==k) {
        cout << cur;
        exit(0);
    }
    if (visit[next]==1) {
        check=1;
        from=next;
        return;
    }
    if (visit[next]==0) {
        counter++;
        cycle(next);
    }
    if (check==1) return;
}

int main()
{
    freopen("cruise.in", "r", stdin);
    freopen("cruise.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i=1; i<=n; i++) {
        int left, right; cin >> left >> right;
        graph[i].push_back(left); //0번 째 index가 left
        graph[i].push_back(right); //1번 째 index가 right
    }
    for (int i=0; i<m; i++) {
        cin >> seq[i];
    }
    // 새로운 functional graph 만들기
    for (int i=1; i<=n; i++)
    {
        int a=dfs(i, dirnum);
        func[i]=a;
        dirnum=0;
    }
    cycle(1);
    int a=0;
    for (int i=0; i<path.size(); i++) {
        if (path[i]==from) a=i;
    }
    for (int i=0; i<path.size(); i++) {
        if (path[i]==from) cout << path[i+k%(counter-a+1)];
    }
}

/*
4 3 3
2 4
3 1
4 2
1 3
L L R
*/
