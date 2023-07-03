#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve() {
    int n=0, temp=0; cin >> n;
    cout << "+ " << n+1 << "\n" << flush;
    cin >> temp;
    cout << "+ " << n+2 << "\n" << flush;
    cin >> temp;
    int mx=0, r=0, i=0;
    for (int j=2; j<=n; j++) {
        cout << "? 1 " << j << "\n" << flush;
        cin >> r;
        if (r>mx) {
            mx=r;
            i=j;
        }
    }

    vector<int> ans1(n+1, 0), ans2(n+1, 0);
    ans1[i]=1; ans2[i]=n/2+1;
    for (int j=1; j<=n; j++) {
        if (j==i) continue;
        cout << "? " << j << ' ' << i << "\n" << flush;
        cin >> r;
        if (r%2==0) {
            ans1[j]=ans1[i]+r/2;
            if (n%2==0) ans2[j]=ans2[i]+r/2;
            else ans2[j]=ans2[i]-r/2;
        }
        else {
            ans1[j]=n-(r-1)/2;
            if (n%2==0) ans2[j]=ans2[i]-(r+1)/2;
            else ans2[j]=ans2[i]+(r+1)/2;
        }
    }
    cout << "! " << flush;
    for (int i=1; i<=n; i++) cout << ans1[i] << ' ' << flush;
    for (int i=1; i<=n; i++) cout << ans2[i] << ' ' << flush;
    cout << "\n" << flush;
    cin >> temp;
}

int main()
{
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

/*
3
1 3 2
*/