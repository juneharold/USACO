#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
using namespace std;
#define ll long long
#define f first
#define s second

int main()
{
    int T; cin >> T;
    while (T--) {
        pair<int, int> pos[25];
        int N; cin >> N;
        for (int i=0; i<N; i++) cin >> pos[i].f >> pos[i].s;

        double ans=1e9;
        for (int i=1; i<(1<<N); i++) {
            ll cnt=0, Xsum=0, Ysum=0;
            for (int j=0; j<N; j++) {
                if (i&(1<<j)) {
                    cnt++;
                    Xsum+=pos[j].f;
                    Ysum+=pos[j].s;
                }
                else {
                    cnt--;
                    Xsum-=pos[j].f;
                    Ysum-=pos[j].s;
                }
            } 

            if (cnt==0) {
                ans=min(ans, sqrt(Xsum*Xsum+Ysum*Ysum));
            }
        }
        cout << fixed << setprecision(6) << ans << "\n";
    }
}

/*
1
4
5 5
5 -5
-5 5
-5 -5
*/