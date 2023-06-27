#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    vector<pair<int, int>> clause(m, {0, 0});
    for (int i=0; i<m; i++) cin >> clause[i].first >> clause[i].second;
    for (int i=0; i<(1<<n); i++) {
        int res=1;
        for (int j=0; j<m; j++) {
            int a=(bool)(i&(1<<(abs(clause[j].first)-1)));
            int b=(bool)(i&(1<<(abs(clause[j].second)-1)));
            if (clause[j].first<0) a=1-a;
            if (clause[j].second<0) b=1-b;
            res&=(a|b);
        }
        if (res==1) {
            cout << "1\n";
            for (int k=0; k<n; k++) {
                if (i&(1<<k)) cout << "1 ";
                else cout << "0 ";
            }
            exit(0);
        }
    }
    cout << 0;
}
