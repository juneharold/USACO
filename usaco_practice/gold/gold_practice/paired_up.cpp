#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define f first
#define s second

int T, N, K, x[100005]={}, y[100005]={};
vector<pair<int, int>> comp;

void T1() {
    x[0]=-1e9, x[N+1]=1e9;
    int ans=0;
    for (auto range: comp) {
        if ((range.s-range.f+1)%2==0) continue;
        int Min=1e9;
        for (int i=0; i<=range.s-range.f; i++) {
            if (i%2==0) Min=min(Min, y[i+range.f]);
            else if (x[i+range.f+1]-x[i+range.f-1]<=K) Min=min(Min, y[i+range.f]);
        }
        ans+=Min;
    }
    cout << ans;
}

int a[100005]={}; // a[i] contains the index of rightmost cow on the left of i that can be unpaired if cow i is unpaired.
void T2() {
    x[0]=-1e9, x[N+1]=1e9;
    int idx=0;
    for (int i=1; i<=N; i++) {
        while (x[i]-x[idx]>K) idx++;
        a[i]=idx-1;
    }

    int ans=0;
    for (auto range: comp) {
        int sz=range.s-range.f+1;
        vector<pair<int, int>> dp(N+1);
        dp[range.f-1]={0, -1e9};
        for (int i=range.f; i<=range.s; i++) {
            dp[i]=dp[i-1];
            if (i==range.f || i==range.s || x[i+1]-x[i-1]<=K || (i-range.f+1)%2==0) {
                dp[i].f=max(dp[i].f, dp[a[i]].s+y[i]);
            }
            if (i==range.f || i==range.s || x[i+1]-x[i-1]<=K || (i-range.f+1)%2==1) {
                dp[i].s=max(dp[i].s, dp[a[i]].f+y[i]);
            }
        }
        if (sz%2==0) ans+=dp[range.s].f;
        else ans+=dp[range.s].s;
    }
    cout << ans;
}

int main()
{
    cin >> T >> N >> K;
    for (int i=1; i<=N; i++) cin >> x[i] >> y[i];

    int last=1;
    for (int i=2; i<=N; i++) {
        if (x[i]-x[i-1]>K) {
            comp.push_back({last, i-1});
            last=i;
        }
    }
    comp.push_back({last, N});

    if (T==1) T1();
    else T2();
}
