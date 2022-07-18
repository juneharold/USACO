#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
#define ll long long
#define f first
#define s second
#define pii pair<int, int>

int arr[10005]={};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T; cin >> T;
    for (int t=1; t<=T; t++) {
        int N, M; cin >> N >> M;
        for (int i=1; i<=N; i++) cin >> arr[i];
        sort(&arr[1], &arr[N+1]);

        double ans=0;
        for (int i=N; i>=1; i--) {
            if (M==0) break;
            if (M==1) { //i부터 1까지 median
                if (i%2==0) {
                    ans+=(double)(arr[i/2]+arr[i/2+1])/2.0;
                }
                else {
                    ans+=(double)(arr[i/2+1]);
                }
            }
            else {
                ans+=arr[i];
            }
            M--;
        }
        cout << fixed;
        cout << "Case #" << t << ": " << ans << "\n";
    }
}
