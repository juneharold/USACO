#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int p[200];
map<pair<int, int>, int> dp;
int P, Q;

int solve(int a, int b) {
  pair<int, int> pr={a, b};
  if(dp.find(pr)!=dp.end()) return dp[pr];

  for(int i=0; i<Q; i++) {
    if(p[i]>=a &&p[i]<=b) {
      dp[pr]=min(dp[pr], (b-a)+solve(a, p[i]-1)+solve(p[i]+1, b));
      if (!dp[pr]) dp[pr]=(b-a)+solve(a, p[i]-1)+solve(p[i]+1, b);
    }
  }
  return dp[pr];
}

int main() {
    int t; cin >> t;
    for (int c=1; c<=t; c++)
    {
        cin >> P >> Q;
        for (int i=0; i<Q; i++) cin >> p[i];
        cout << "Case #" << c << ": " << solve(1, P) << "\n";
        dp.clear();
    }
}
