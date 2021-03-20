#include <iostream>
using namespace std;

int  main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int  T; cin >> T;
  for (int  i=1; i<=T; i++)
  {
    long long  N, D; cin >> N >> D;
    long long  X[1005]={};
    for (int  j=1; j<=N; j++) cin >> X[j];
    long long prev=X[N]*(D/X[N]);
    for (int  j=N-1; j>=1; j--)
    {
      prev=X[j]*(prev/X[j]);
    }
    cout << "Case #" << i << ": " << prev << "\n";
  }
}
