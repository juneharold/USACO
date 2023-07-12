#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int N, K; cin >> N >> K;
    int ans=0;
    vector<int> a(K+1, 0), plug(N+1, 0);
    for (int i=1; i<=K; i++) cin >> a[i];
    for (int i=1; i<=K; i++) {
        bool skip=false;
        for (int j=1; j<=N; j++) {
            if (plug[j]==a[i]) {
                skip=true;
                break;
            }
            if (plug[j]==0) {
                plug[j]=a[i];
                skip=true;
                break;
            }
        }
        if (skip) continue;
        for (int j=1; j<=N; j++) {
            bool nofuture=true;
            for (int k=i+1; k<=K; k++) {
                if (a[k]==plug[j]) nofuture=false;
            }
            if (nofuture) {
                plug[j]=a[i];
                skip=true;
                ans++;
                break;
            }
        }
        if (skip) continue;
        int farthest=0, idx=0;;
        for (int j=1; j<=N; j++) {
            for (int k=i+1; k<=K; k++) {
                if (a[k]==plug[j] && k>farthest) {
                    farthest=k;
                    idx=j;
                    break;
                }
                if (a[k]==plug[j]) break;
            }
        }
        ans++;
        plug[idx]=a[i];
    }
    cout << ans;
}