#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  int T; cin >> T;
  for (int t=1; t<=T; t++)
  {
    int R, C; cin >> R >> C;
    int grid[305][305]={};
    for (int i=1; i<=R; i++)
    {
      for (int j=1; j<=C; j++)
      {
        cin >> grid[i][j];
      }
    }
    int counter=0;
    for (int i=1; i<=R; i++)
    {
      for (int j=1; j<=C; j++)
      {
        // right
        int right_diff=abs(grid[i][j]-grid[i][j+1]);
        // left
        // up
        // down
      }
    }
  }
}
