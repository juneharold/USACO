#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int T; cin >> T;
    while (T--) {
        int n, k, x[21]={}, c[21]={}; cin >> n >> k;
        for (int i=1; i<=k; i++) cin >> x[i];
        for (int i=1; i<=k; i++) cin >> c[i];

        string ans="", xyz="xyz";
        bool possible=true;
        int idx=0;
        for (int i=1; i<=k; i++) {
            int need=c[i]-c[i-1], space=x[i]-x[i-1];
            if (need>space) {
                possible=false;
                break;
            }
            if (i==1) need-=3;
            for (int j=1; j<=space-need; j++) {
                ans+=xyz[idx%3];
                idx++;
            }
            for (int j=1; j<=need; j++) ans+=(char)(i+96);
        }

        if (possible) cout << "YES\n" << ans << "\n";
        else cout << "NO\n";
    }
}