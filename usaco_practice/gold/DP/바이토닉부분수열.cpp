#include <iostream>
#include <algorithm>
using namespace std;

int dp1[1005]={}, dp2[1005]={}, num[1005]={};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    for (int i=1; i<=N; i++) cin >> num[i];

    for (int i=1; i<=N; i++) {
        for (int j=i-1; j>=0; j--) {
            if (num[j]<num[i]) dp1[i]=max(dp1[i], dp1[j]+1);
        }
    }
    for (int i=N; i>=1; i--) {
        for (int j=i+1; j<=N+1; j++) {
            if (num[j]<num[i]) dp2[i]=max(dp2[i], dp2[j]+1);
        }
    }

    int ans=0;
    for (int i=1; i<=N; i++) {
        ans=max(ans, dp1[i]+dp2[i]-1);
    }

    cout << ans;
}
