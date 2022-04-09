#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int T; cin >> T;
    while (T--) {
        int N, a[1005][4]={}; cin >> N;
        for (int i=1; i<=N; i++) {
            string s; cin >> s;
            int num[3]={-1, -1, -1}, idx=0, cnt=0;
            for (char c: s) {
                if (c=='.') {
                    int times=1;
                    for (int j=2; j>=0; j--) {
                        if (num[j]==-1) continue;
                        a[i][cnt]+=num[j]*times;
                        times*=10;
                        num[j]=-1;
                    }
                    idx=0;
                    cnt++;
                    continue;
                }
                num[idx]=c-48;
                idx++;
            }
            int times=1;
            for (int j=2; j>=0; j--) {
                if (num[j]==-1) continue;
                a[i][cnt]+=num[j]*times;
                times*=10;
                num[j]=-1;
            }
        }

        int sz=0, ans[4]={};
        bool same=true;
        for (int i=0; i<4; i++) {
            for (int j=7; j>=0; j--) {
                int x=(a[1][i]&(1<<j));
                for (int k=2; k<=N; k++) {
                    if (x!=(a[k][i]&(1<<j))) same=false;
                }
                if (same) {
                    sz++;
                    ans[i]+=x;
                }
            }
        }

        for (int i=0; i<4; i++) {
            cout << ans[i];
            if (i!=3) cout << '.';
        }
        cout << '/' << sz << "\n";
    }
}
