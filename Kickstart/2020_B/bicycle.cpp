#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  int T; cin >> T;
  for (int i=1; i<=T; i++)
  {
    int heights[105]={};
    int N; cin >> N;
    for (int j=1; j<=N; j++) cin >> heights[j];
    int counter=0;
    for (int j=2; j<=N-1; j++)
    {
      if ((heights[j]>heights[j-1]) and (heights[j]>heights[j+1]))
      {
        counter++;
      }
    }
    cout << "Case #" << i << ": " << counter << "\n";
  }
}

/*
1
4
7 7 7 7

4
3
10 20 14
4
7 7 7 7
5
10 90 20 90 10
3
10 3 10
*/
