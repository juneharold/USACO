#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
  int t; cin >> t;
  for (int T=1; T<=t; T++)
  {
    int N, K; cin >> N >> K;
    string S; cin >> S;
    int score=0;
    for (int i=0; i<=N/2-1; i++)
    {
      char a=S[i], b=S[N-i-1];
      if (a!=b)
      {
        score++;
      }
    }
    if (score>=K) cout << "Case #" << T << ": " << score-K << "\n";
    else cout << "Case #" << T << ": " << K-score << "\n";
  }
}

/*
2
5 1
ABCAA
2 1
AB
*/
