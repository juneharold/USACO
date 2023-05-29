#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
using namespace std;
#define f first
#define s second
#define ll long long
#define MOD 1000000007

int a[200005]={}, b[200005]={}, cnta[400005]={}, cntb[400005]={};

int main()
{
    int T; cin >> T;
    while (T--) {
        int n, idx1=0, idx2=0; cin >> n;
        for (int i=0; i<n; i++) cin >> a[i];
        for (int i=0; i<n; i++) cin >> b[i];

        int cnt=1; cnta[a[0]]=1;
        for (int i=1; i<n; i++) {
            if (a[i]==a[i-1]) {
                cnt++;
            }
            else {
                cnt=1;
            }
            cnta[a[i]]=max(cnta[a[i]], cnt);
        }
        cnt=1; cntb[b[0]]=1;
        for (int i=1; i<n; i++) {
            if (b[i]==b[i-1]) {
                cnt++;
            }
            else {
                cnt=1;
            }
            cntb[b[i]]=max(cntb[b[i]], cnt);
        }

        int ans=0;
        for (int i=0; i<=2*n; i++) {
            ans=max(ans, cnta[i]+cntb[i]);
        }
        cout << ans << "\n";

        fill(&a[0], &a[n+1], 0);
        fill(&b[0], &b[n+1], 0);
        fill(&cnta[0], &cnta[2*n+4], 0);
        fill(&cntb[0], &cntb[2*n+4], 0);
    }
}
