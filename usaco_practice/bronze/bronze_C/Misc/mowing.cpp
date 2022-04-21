#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int field[2005][2005]={};

int main()
{
    freopen("mowing.in", "r", stdin);
    freopen("mowing.out", "w", stdout);
    int N, x=1001, y=1001, time=2, ans=1e9; cin >> N;

    field[x][y]=1;
    for (int i=0; i<N; i++) {
        char dir; cin >> dir;
        int step; cin >> step;
        if (dir=='N') {
            for (int j=0; j<step; j++) {
                y--;
                if (field[x][y]!=0) ans=min(ans, time-field[x][y]);
                field[x][y]=time;
                time++;
            }
        }
        if (dir=='E') {
            for (int j=0; j<step; j++) {
                x++;
                if (field[x][y]!=0) ans=min(ans, time-field[x][y]);
                field[x][y]=time;
                time++;
            }
        }
        if (dir=='S') {
            for (int j=0; j<step; j++) {
                y++;
                if (field[x][y]!=0) ans=min(ans, time-field[x][y]);
                field[x][y]=time;
                time++;
            }
        }
        if (dir=='W') {
            for (int j=0; j<step; j++) {
                x--;
                if (field[x][y]!=0) ans=min(ans, time-field[x][y]);
                field[x][y]=time;
                time++;
            }
        }
    }
    if (ans==1e9) cout << "-1";
    else cout << ans;
}
