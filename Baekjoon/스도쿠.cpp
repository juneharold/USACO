#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define f first
#define s second

int board[9][9], n;
vector<pair<int, int>> a;

bool check(int x, int y) {
    int b1[10]={};
    for (int i=(x/3)*3; i<(x/3+1)*3; i++) {
        for (int j=(y/3)*3; j<(y/3+1)*3; j++) {
            if (board[i][j]!=0 && b1[board[i][j]]) return false;
            b1[board[i][j]]=1;
        }
    }
    int b2[10]={};
    for (int i=0; i<9; i++) {
        if (board[i][y]!=0 && b2[board[i][y]]) return false;
        b2[board[i][y]]=1;
    }
    int b3[10]={};
    for (int j=0; j<9; j++) {
        if (board[x][j]!=0 && b3[board[x][j]]) return false;
        b3[board[x][j]]=1;
    }
    return true;
}

void solve(int cur) {
    if (cur==n) {
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) cout << board[i][j] << ' ';
            cout << "\n";
        }
        exit(0);
    }
    int x=a[cur].f, y=a[cur].s;
    for (int j=1; j<=9; j++) {
        board[x][y]=j;
        if (check(x, y)) {
            solve(cur+1);
        }
        board[x][y]=0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            cin >> board[i][j];
            if (board[i][j]==0) a.push_back({i, j});
        }
    }
    
    n=a.size();
    solve(0);
}
