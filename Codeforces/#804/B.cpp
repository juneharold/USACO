#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <map>
#include <set>
using namespace std;
#define f first
#define s second
#define ll long long
#define db double

int main()
{
    int T; cin >> T;
    while (T--) {
        int n, m; cin >> n >> m;
        for (int i=0; i<n; i++) {
            int cnt;
            if (i%4==0 || i%4==3) cnt=1; // 0,1 is black
            else cnt=3; // 2, 3 is white
            for (int j=0; j<m; j++) {
                if (cnt==0 || cnt==1) cout << 1 << ' ';
                else cout << 0 << ' ';
                cnt=(cnt+1)%4;
            }
            cout << "\n";
        }
    }
}
