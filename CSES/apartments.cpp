#include <iostream>
#include <algorithm>
using namespace std;

const long long MAX_NM=2e5+5;
long long target[MAX_NM]={}, apartments[MAX_NM]={};

int main()
{
    long long n, m, k; cin >> n >> m >> k;
    for (long long i=0; i<n; i++) cin >> target[i];
    for (long long i=0; i<m; i++) cin >> apartments[i];

    sort(target, target+n);
    sort(apartments, apartments+m);

    long long ind=0, ans=0;
    for (long long i=0; i<m; i++) {
        if (apartments[i]+k<target[ind]) continue;

        while (target[ind]<apartments[i]-k) {
            ind++;
        }
        if (apartments[i]-k<=target[ind] && target[ind]<=apartments[i]+k) {
            ans++;
            ind++;
        }
    }
    cout << ans;
}
