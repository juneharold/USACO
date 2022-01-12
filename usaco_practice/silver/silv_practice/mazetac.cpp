#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <math.h>
using namespace std;

int N, visit[26][26][20000]={}, dx[4]={1, -1, 0, 0}, dy[4]={0, 0, 1, -1};
string graph[26][26];
set<int> ans;

string find_grid(int n) {
    int num3[100], cnt=0;
    for (int i=0; i<9; i++){
        num3[i]=n%3;
        n=n/3;
        cnt++;
    }
    //9-(index of num3)
    string grid="";
    for (int j=cnt-1; j>=0; j--) {
        if (num3[j]==0) grid+='E'; //empty
        if (num3[j]==1) grid+='M';
        if (num3[j]==2) grid+='O';
    }
    return grid;
}

int grid_to_num(string grid) {
    int ret=0;
    for (int i=0; i<=8; i++) {
        if (grid[i]=='M') ret+=pow(3, 8-i);
        if (grid[i]=='O') ret+=2*pow(3, 8-i);
    }
    return ret;
}

bool check_row_col(string grid) {
    if (grid[0]=='M') {
        if (grid[1]=='O' && grid[2]=='O') return true;
        if (grid[3]=='O' && grid[6]=='O') return true;
    }
    if (grid[1]=='M' && grid[4]=='O' && grid[7]=='O') return true;
    if (grid[2]=='M') {
        if (grid[0]=='O' && grid[1]=='O') return true;
        if (grid[5]=='O' && grid[8]=='O') return true;
    }
    if (grid[3]=='M' && grid[4]=='O' && grid[5]=='O') return true;
    if (grid[5]=='M' && grid[4]=='O' && grid[3]=='O') return true;

    if (grid[6]=='M') {
        if (grid[3]=='O' && grid[0]=='O') return true;
        if (grid[7]=='O' && grid[8]=='O') return true;
    }
    if (grid[7]=='M' && grid[4]=='O' && grid[1]=='O') return true;
    if (grid[8]=='M') {
        if (grid[5]=='O' && grid[2]=='O') return true;
        if (grid[7]=='O' && grid[6]=='O') return true;
    }
    return false;
}

bool check_diag(string grid) {
    if (grid[0]=='M' && grid[4]=='O' && grid[8]=='O') return true;
    if (grid[2]=='M' && grid[4]=='O' && grid[6]=='O') return true;
    if (grid[6]=='M' && grid[4]=='O' && grid[2]=='O') return true;
    if (grid[8]=='M' && grid[4]=='O' && grid[0]=='O') return true;
    return false;
}

void dfs(int x, int y, int state) {
    visit[x][y][state]=1;

    int ns=state;
    if (graph[x][y][0]=='M' || graph[x][y][0]=='O') {
        int pi=graph[x][y][1]-48, pj=graph[x][y][2]-48;
        string grid=find_grid(state);

        if (grid[3*(pi-1)+pj-1]=='E') {
            grid[3*(pi-1)+pj-1]=graph[x][y][0];
            ns=grid_to_num(grid);
            if (check_row_col(grid) || check_diag(grid)) {
                ans.insert(ns);
                return;
            }
        }
    }

    for (int i=0; i<4; i++) {
        int nx=x+dx[i], ny=y+dy[i];
        if (graph[nx][ny]=="###") continue;
        if (visit[nx][ny][ns]==0) dfs(nx, ny, ns);
    }
}


int main()
{
    pair<int, int> start;
    cin >> N;
    for (int i=1; i<=N; i++) {
        string a; cin >> a;
        for (int j=0; j<N; j++) {
            graph[i][j+1]=a.substr(j*3, 3);
            if (graph[i][j+1]=="BBB") start={i, j+1};
        }
    }

    dfs(start.first, start.second, 0);

    cout << ans.size();
}
