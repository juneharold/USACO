#include <iostream>
#include <algorithm>
using namespace std;

void solve() {
    int cnt; cin >> cnt;
    int idx=0, ans=0;
    while (cnt) {
        cout << "- " << (1<<idx) << "\n" << flush;
        int ncnt; cin >> ncnt;
        if (ncnt==-1) exit(0);

        int dcnt=ncnt-cnt;
        ans+=(1<<(dcnt+idx+1));
        if (dcnt>=0) {
            int temp=0;
            for (int i=idx; i<=idx+dcnt; i++) temp+=(1<<i);
            cout << "- " << temp << "\n" << flush;
            cin >> cnt;
            if (cnt==-1) exit(0);
        }
        else cnt=ncnt;
        idx+=dcnt+2;
    }
    cout << "! " << ans << "\n" << flush;
}

int main()
{
    int T; cin >> T;
    while (T--) {
        solve();
    }
}