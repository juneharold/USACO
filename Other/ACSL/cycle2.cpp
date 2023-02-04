/*
어떤 노드에서 시작해서 만들 수 있는 싸이클의 갯수 찾기
input:
number of nodes
N*N adjacency matrix;
*/

#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

int N, st, adj[100][100]={}, visit[100]={}, cnt=0;
set<string> s;
vector<char> path;

void dfs(int cur) {
    visit[cur]=1;
    path.push_back('A' + cur);

    for (int i=0; i<N; i++) {
        if (adj[cur][i]==0) continue;

        if (visit[i]==0) dfs(i);
        else if ('A'+i==path[0]) {
            cnt++;
            string temp="";
            for (char x: path) temp+=x;
            temp+=('A'+i);
            s.insert(temp);
        }
    }

    visit[cur]=0;
    path.pop_back();
}

int main()
{
    cin >> N >> st;
    for (int i=0; i<N; i++) for (int j=0; j<N; j++) cin >> adj[i][j];

    dfs(st);

    cout << cnt << "\n";
    for (auto x: s) cout << x << "\n";
}

/*
6 1
0 1 0 0 0 1
1 0 1 1 0 1
0 1 0 1 0 1
0 0 0 0 1 0
1 1 0 0 0 1
0 1 0 0 0 0
*/
