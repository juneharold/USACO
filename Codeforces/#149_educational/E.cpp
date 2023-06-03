#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <random>
#include <chrono>
using namespace std;
#define f first
#define s second
typedef long long ll;
const ll nmax=1e6+5, sqrmax=635, MOD=998244353;
 
int main()
{
    int k; cin >> k;
    vector<int> a(1<<k);
    for (int i=0; i<(1<<k); i++) {
        cin >> a[i];
        if (a[i]!=-1) a[i]--;
    }
    int ans=1;
    for (int i=k-1; i>=0; i--) {
        int num_loser=(1<<i), num_pair=0;
        vector<int> na(1<<i);
        for (int j=0; j<(1<<i); j++) {
            int mn=min(a[2*j], a[2*j+1]);
            int mx=max(a[2*j], a[2*j+1]);
            if (mn==-1) { 
                if (mx==-1) {
                    na[j]=-1;
                    num_pair++;
                }
                if (mx>=(1<<i)) {
                    na[j]=-1;
                    num_loser--;
                }
                else {
                    na[j]=mx;
                }
            }
            else if ((a[2*j]<(1<<i))==(a[2*j+1]<(1<<i))) {
                ans=0;
            }
            else {
                na[j]=mn;
                num_loser--;
            }
        }
        for (int j=0; j<num_pair; j++) ans=ans*2LL%MOD;
        for (int j=1; j<=num_loser; j++) ans=ans*1LL*j%MOD;
        a=na;
    }
    cout << ans;
}
