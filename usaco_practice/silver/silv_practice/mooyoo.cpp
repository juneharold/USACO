#include <iostream>
#include <algorithm>
using namespace std;

int dx[4]={1, -1, 0, 0};
int dy[4]={0, 0, 1, -1};
int graph[105][15]={};
int visit[105][15]={};

void dfs(int Y, int X, int color)
{
  visit[Y][X]=1;
  for (int i=0; i<4; i++)
  {
    int next_Y=Y+dy[i], next_X=X+dx[i];
    if (visit[next_Y][next_X]==0 and graph[next_Y][next_X]==color) dfs(next_Y, next_X, color);
  }
}

int main()
{
  int N, K; cin >> N >> K;
  for (int i=1; i<=N; i++) for (int j=1; j<=10; j++)  cin >> graph[i][j];
  // dfs
  for (int y=1; y<=N; y++) for (int x=1; x<=10; x++)
  {
    int color=graph[y][x];
    if (color!=0)
    {
      dfs(y, x, color);
    }
  }
  /*
  for (int i=1; i<=N; i++)
  {
    for (int j=1; j<=10; j++)
    {
      cout << graph[i][j];
    }
    cout << "\n";
  }
  */
}
