#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define f first
#define s second

int x[100005]={}, y[100005]={};
vector<pair<int, int>> comp;

int main()
{
    int T, N, K; cin >> T >> N >> K;
    for (int i=1; i<=N; i++) cin >> x[i] >> y[i];

    int last=1;
    for (int i=2; i<=N; i++) {
        if (x[i]-x[i-1]>K) {
            comp.push_back({last, i-1});
            last=i;
        }
    }
    comp.push_back({last, N});
    x[0]=-INT_MAX, x[N+1]=INT_MAX;
    int ans=0;
    for (auto range: comp) {
        if ((range.s-range.f+1)%2==0) continue;
        int Min=INT_MAX;
        for (int i=0; i<=range.s-range.f; i++) {
            if (i%2==0) Min=min(Min, y[i+range.f]);
            else if (x[i+range.f+1]-x[i+range.f-1]<=K) Min=min(Min, y[i+range.f]);
        }
        ans+=Min;
    }
    cout << ans;
}
