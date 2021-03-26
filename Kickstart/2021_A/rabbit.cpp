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
    multiset < pair< int, pair <int, int> > > coordinates;
    for (int i=1; i<=R; i++) for (int j=1; j<=C; j++)
    {
      cin >> grid[i][j];
      coordinates.insert(make_pair(grid[i][j], make_pair(i, j)));
    }
    long long counter=0;
    for (int a=0; a<R*C; a++)
    {
      // 가장 큰 칸 찾기
      auto it = coordinates.end();
      it--;
      int i = (*it).second.first, j = (*it).second.second;
      int size=(*it).first;
      // 가장 큰 칸에서 올리기
      for (int d=0; d<4; d++)
      {
        if ((i+dy[d]>=1 and i+dy[d]<=R) and (j+dx[d]>=1 and j+dx[d]<=C))
        {
          int diff=size-grid[i+dy[d]][j+dx[d]];
          if (diff>1)
          {
            coordinates.erase(coordinates.find(make_pair(grid[i+dy[d]][j+dx[d]], make_pair(i+dy[d], j+dx[d]))));
            grid[i+dy[d]][j+dx[d]]+=(diff-1);
            coordinates.insert(make_pair(grid[i+dy[d]][j+dx[d]], make_pair(i+dy[d], j+dx[d])));
            counter+=(diff-1);
          }
        }
      }
      // 지우기
      coordinates.erase(--coordinates.end());
    }
    //for (int i=1; i<=R; i++) for (int j=1; j<=C; j++) cout << grid[i][j];
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
4 1 5
*/
