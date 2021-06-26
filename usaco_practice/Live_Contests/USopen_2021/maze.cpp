#include <iostream>
#include <algorithm>
using namespace std;

char board[30][30][3];
int visit[30][30][20000];
int tictactoe[10]={};
int dx[4]={1, -1, 0, 0};
int dy[4]={0, 0, 1, -1};

void dfs(int x, int y, int bs) {
    visit[x][y][bs]=1;
    if (board[x][y][0]==)
    for (int i=0; i<4; i++) {
        int next_x=x+dx[i], next_y=y+dy[i];
        if (board[next_x][next_y][0]=='#') continue;
        if (visit[next_x][next_x][bs]==0) dfs(next_x, next_x, bs);
    }
}

int main()
{
    int n; cin >> n;
    pair<int, int> bess;
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) for (int k=0; k<3; k++) {
        cin >> board[i][j][k];
        if (board[i][j][k]=='B') {
            bess.first=i;
            bess.second=j;
        }
    }


}
