#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int dy[4]={1, -1, 0, 0};
int dx[4]={0, 0, 1, -1};
int visit[1005][1005]={};
int grid[1005][1005]={};
int area=0;
int perimeter=0;

void dfs(int y, int x)
{
    visit[y][x]=1;
    area++;
    perimeter+=4;
    for (int i=0; i<4; i++)
    {
      int next_Y=y+dy[i], next_X=x+dx[i];
      if (grid[next_Y][next_X]==1) perimeter--;
      if (visit[next_Y][next_X]==0 and grid[next_Y][next_X]==1)
      {
          dfs(next_Y, next_X);
      }
    }
}

int main()
{
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);
    int N; cin >> N;
    for (int i=1; i<=N; i++) for (int j=1; j<=N; j++)
    {
        char a; cin >> a;
        if (a=='#') grid[i][j]=1;
        else grid[i][j]=0;
    }
    pair <int, int> ans (0, 0);
    for (int i=1; i<=N; i++) for (int j=1; j<=N; j++)
    {
        //cout << "hello" << "\n";
        if (grid[i][j]==1) dfs(i, j);
        if (area>ans.first)
        {
            ans.first=area;
            ans.second=perimeter;
        }
        else if (area==ans.first and perimeter<ans.second)
        {
            ans.first=area;
            ans.second=perimeter;
        }
        area=0;
        perimeter=0;
        int visit[1005][1005]={};
    }
    cout << ans.first << " " << ans.second;
}
// lol
