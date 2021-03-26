#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dx[4]={1, -1, 0, 0};
int dy[4]={0, 0, 1, -1};
int graph[105][11]={};
int visit[105][11]={};
int counter=0;

void dfs(int Y, int X, int color)
{
  visit[Y][X]=1;
  counter++;
  for (int i=0; i<4; i++)
  {
    int next_Y=Y+dy[i], next_X=X+dx[i];
    if (visit[next_Y][next_X]==0 and graph[next_Y][next_X]==color) dfs(next_Y, next_X, color);
  }
}

void drop (int N)
{
    for (int c=1; c<=10; c++)
    {
        vector <int> nonzero;
        for (int r=1; r<=N; r++)
        {
            if (graph[r][c]!=0)
            {
                nonzero.push_back(graph[r][c]);
                graph[r][c]=0;
            }
        }
        int index=0;
        for (int v=nonzero.size()-1; v>=0; v--)
        {
            graph[N-index][c]=nonzero[v];
            index++;
        }
    }
}

int main()
{
  freopen("mooyomooyo.in", "r", stdin);
  freopen("mooyomooyo.out", "w", stdout);
  //ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
  int N, K;
  cin >> N >> K;
  for (int y=1; y<=N; y++) for (int x=1; x<=10; x++)
  {
      char a; cin >> a;
      graph[y][x] = a-48;
  }
  for (int t=0; t<N; t++)
  {
      // dfs
      for (int y=1; y<=N; y++) for (int x=1; x<=10; x++)
      {
        int color=graph[y][x];
        if (color!=0)
        {
          dfs(y, x, color);
          if (counter>=K)
          {
              for (int i=1; i<=N; i++) for (int j=1; j<=10; j++) if (visit[i][j]==1) graph[i][j]=0;
          }
          fill(&visit[0][0], &visit[N+1][11], 0);
          counter=0;
        }
      }
      drop(N);
  }
  // printing the final grid
  for (int i=1; i<=N; i++)
  {
    for (int j=1; j<=10; j++)
    {
      cout << graph[i][j];
    }
    cout << "\n";
  }
}

/*
6 3
0000000000
0000000300
0054000300
1054502230
2211122220
1111111223
*/
