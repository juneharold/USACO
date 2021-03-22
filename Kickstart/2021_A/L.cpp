#include <iostream>
using namespace std;

int main()
{
  int t; cin >> t;
  for (int T=1; T<=t; T++)
  {
    int R, C; cin >> R >> C;
    int grid[1005][1005]={};
    for (int i=1; i<=R; i++) for (int j=1; j<=C; j++) cin >> grid[i][j];
    int counter=0;
    for (int i=1; i<=R; i++)
    {
      for (int j=1; j<=C; j++)
      {
        //count up
        int up=0;
        for (int u=0; u<=R; u++)
        {
          if (grid[i-u][j]==1) up++;
          else break;
        }
        // count down
        int down=0;
        for (int d=0; d<=R; d++)
        {
          if (grid[i+d][j]==1) down++;
          else break;
        }
        // count right
        int right=0;
        for (int r=0; r<=C; r++)
        {
          if (grid[i][j+r]==1) right++;
          else break;
        }
        // count left
        int left=0;
        for (int l=0; l<=C; l++)
        {
          if (grid[i][j-l]==1) left++;
          else break;
        }
        // check right, left from up down
        if ((up<=2*right or right>=up*2) and up>=2 and right>=2)
        {
          counter++;
          cout << i << j << "\n";
        }
        if ((up<=2*left or left>=up*2) and up>=2 and left>=2)
        {
          counter++;
          cout << i << j << "\n";
        }
        if ((down<=2*right or right>=down*2) and down>=2 and right>=2)
        {
          counter++;
          cout << i << j << "\n";
        }
        if ((down<=2*left or left>=down*2) and down>=2 and left>=2)
        {
          counter++;
          cout << i << j << "\n";
        }
      }
    }
    cout << "Case #" << T << ": " << counter << "\n";
  }
}


/*
1
6 4
1 0 0 0
1 0 0 1
1 1 1 1
1 0 1 0
1 0 1 0
1 1 1 0
*/
