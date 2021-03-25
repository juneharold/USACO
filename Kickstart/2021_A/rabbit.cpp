#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int dy[4]={0, 0, 1, -1};
int dx[4]={1, -1, 0, 0};

int main()
{
  int T; cin >> T;
  for (int t=1; t<=T; t++)
  {
    int R, C; cin >> R >> C;
    int grid[305][305]={};
    for (int i=1; i<=R; i++) for (int j=1; j<=C; j++) cin >> grid[i][j];
    int prev=-1;
    int counter=0;
    multiset pair< int, pair <int, int> > s;
    int visit[305][305]={};
    while (counter>prev)
    {
      prev=counter;
      // 가장 큰 칸 찾기
      int max_space=0;
      int I, J;
      for (int i=1; i<=R; i++) for (int j=1; j<=C; j++)
      {
        if (grid[i][j]>max_space and visit[i][j]==0)
        {
          max_space=grid[i][j];
          I=i; J=j;
        }
      }
      visit[I][J]
      // 가장 큰 칸에서 올리기
      for (int i=1; i<=R; i++) for (int j=1; j<=C; j++)
      {
        // 가장 큰 칸일때
        if (grid[i][j]==max_space)
        {
          for (int d=0; d<4; d++)
          {
            if ((i+dy[d]>=1 and i+dy[d]<=R) and (j+dx[d]>=1 and j+dx[d]<=C))
            {
              int diff=grid[i][j]-grid[i+dy[d]][j+dx[d]];
              if (diff>1)
              {
                grid[i+dy[d]][j+dx[d]]+=(diff-1);
                counter+=(diff-1);
              }
            }
          }
        }
      }
    }
    cout << "Case #" << t << ": " << counter << "\n";
  }
}

/*
3
1 3
3 4 3
1 3
3 0 0
3 3
0 0 0
0 2 0
0 0 0

1
3 3
5 1 1
1 2 1
4 1 1
*/
