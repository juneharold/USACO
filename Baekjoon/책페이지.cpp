#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;

int main()
{
    int N; cin >> N;
    vector<ll> ans(10, 0);
    int idx=0, leftover=0;
    while (N!=0) {
        ll last=N%10;
        if (0==last) ans[0]+=(N/10-1)*pow(10, idx)+(leftover+1);
        else ans[0]+=(N/10)*pow(10, idx);
        for (int i=1; i<=last; i++) {
            if (i==last) ans[i]+=(N/10)*pow(10, idx)+(leftover+1);
            else ans[i]+=(N/10+1)*pow(10, idx);
        }
        for (int i=last+1; i<10; i++) {
            ans[i]+=(N/10)*pow(10, idx);
        }
        N/=10;
        leftover+=last*pow(10, idx);
        idx++;
    }
    for (int i=0; i<10; i++) cout << ans[i] << ' ';
}
