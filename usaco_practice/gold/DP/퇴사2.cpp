#include <iostream>
#include <algorithm>
using namespace std;

const int MAX=15e5+5;
int N, dp[MAX]={}, T[MAX], P[MAX];

int main()
{
    cin >> N;
    for (int i=1; i<=N; i++) cin >> T[i] >> P[i];

    int max_so_far=0;
    for (int i=1; i<=N+1; i++) {
        dp[i]=max(dp[i], max_so_far);
        dp[i+T[i]]=max(dp[i+T[i]], dp[i]+P[i]);
        max_so_far=dp[i];
    }
    cout << max_so_far;
}
