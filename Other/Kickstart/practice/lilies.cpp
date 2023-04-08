#include <iostream>
#include <algorithm>
using namespace std;

int dp[100005]={};

int main()
{
    int T; cin >> T;
    for (int t=1; t<=T; t++) {
        int L; cin >> L;
        for (int i=1; i<=L; i++) {
            dp[i]=dp[i-1]+1;
            for (int j=1; j*j<=i; j++) {
                if (i%j==0) {
                    dp[i]=min(dp[i], dp[j]+4+2*(i/j-1));
                    dp[i]=min(dp[i], dp[i/j]+4+2*(j-1));
                }
            }
        }
        cout << "Case #" << t << ": " << dp[L] << "\n";
        fill(&dp[0], &dp[L+1], 0);
    }
}
