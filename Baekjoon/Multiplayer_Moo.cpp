/*
make a graph for all (x, y) pairs of cows where node is connected region 
-> find largest connected component in all graphs 

worst case: n^4 nodes 

there are maximum of 4*n^2 edges in all of the graphs
so there are maximum of 8*n^2 nodes we have to consider, since other nodes are not connected to other nodes. 
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
typedef pair<int, int> pii;
#define f first
#define s second

int dx[4]={0, 0, 1, -1}, dy[4]={1, -1, 0, 0};
int N, grid[255][255]={}, vst1[255][255]={}, sz[255*255]={}, region[255*255]={};
int ans1=0, ans2=0, idx=0, temp=0, id=0;

void dfs1(int x, int y, int id, int num) {
    vst1[x][y]=id;
    temp++;
    for (int i=0; i<4; i++) {
        int nx=x+dx[i], ny=y+dy[i];
        if (nx<1 || nx>N || ny<1 || ny>N) continue;
        if (vst1[nx][ny] || grid[nx][ny]!=num) continue;
        dfs1(nx, ny, id, num);
    }
}

struct Graph {
    map<int, set<int>> edges;
    map<int, int> vst2;
};

map<pii, Graph> graphs;

void dfs2(pii graph_num, int cur) {
    graphs[graph_num].vst2[cur]=1;
    temp+=sz[cur];
    for (int nx: graphs[graph_num].edges[cur]) {
        if (graphs[graph_num].vst2.find(nx)!=graphs[graph_num].vst2.end()) continue;
        dfs2(graph_num, nx);
    }
}

int main()
{
    cin >> N;
    vector<int> used(1e6+1, 0);
    for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) {
        int x; cin >> x;
        if (!used[x]) {
            grid[i][j]=++idx;
            used[x]=idx;
        }
        else grid[i][j]=used[x];
    }
    for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) {
        if (vst1[i][j]==0) {
            dfs1(i, j, ++id, grid[i][j]);
            region[id]=grid[i][j];
            sz[id]=temp;
            ans1=max(ans1, temp);
            temp=0;
        }
    }

    for (int x=1; x<=N; x++) for (int y=1; y<=N; y++) {
        for (int i=0; i<4; i++) {
            int nx=x+dx[i], ny=y+dy[i];
            if (nx<1 || nx>N || ny<1 || ny>N) continue;
            if (vst1[x][y]!=vst1[nx][ny]) {
                pii graph_num={min(grid[x][y], grid[nx][ny]), max(grid[x][y], grid[nx][ny])};
                graphs[graph_num].edges[vst1[x][y]].insert(vst1[nx][ny]);
                graphs[graph_num].edges[vst1[nx][ny]].insert(vst1[x][y]);
            }
        }
    }
    ans2=ans1;
    for (int x=1; x<=N; x++) for (int y=1; y<=N; y++) {
        for (int i=0; i<4; i++) {
            int nx=x+dx[i], ny=y+dy[i];
            if (nx<1 || nx>N || ny<1 || ny>N) continue;
            if (vst1[x][y]==vst1[nx][ny]) continue;
            pii graph_num={min(grid[x][y], grid[nx][ny]), max(grid[x][y], grid[nx][ny])};
            if (graphs[graph_num].vst2.find(vst1[x][y])==graphs[graph_num].vst2.end()) {
                dfs2(graph_num, vst1[x][y]);
                ans2=max(ans2, temp);
                temp=0;
            }
        }
    }
    cout << ans1 << "\n" << ans2;
}