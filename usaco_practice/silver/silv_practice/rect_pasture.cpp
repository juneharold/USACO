#include <iostream>
#include <algorithm>
using namespace std;

const long long MAX_N=2505;
long long n;
pair<long long, long long> point[MAX_N];
pair<long long, long long> new_p[MAX_N];
long long pfs[MAX_N][MAX_N]={};
bool sortY (pair<long long, long long> a, pair<long long, long long> b) {
    return a.second < b.second;
}
long long ans=0;

int main()
{
    cin >> n;
    for (long long i=1; i<=n; i++) {
        long long x, y; cin >> x >> y;
        point[i]={x, y};
    }

    sort(point, point+n);
    for (long long i=1; i<=n; i++) point[i].first=i;
    sort(point, point+n, sortY);
    for (long long i=1; i<=n; i++) point[i].second=i;

    for (long long i=1; i<=n; i++) pfs[point[i].first][point[i].second]=1;
    for (long long i=2; i<=n; i++) {
        for (long long j=2; j<=n; j++) {
            pfs[i][j]+=pfs[i-1][j]+pfs[i][j-1]-pfs[i-1][j-1];
        }
    }

    for (long long i=1; i<=n; i++) { //y1
        for (long long j=i; j<=n; j++) { //y2
            long long x_min=min(point[i].first, point[j].first);
            long long x_max=max(point[i].first, point[j].first);

            long long pos_l=pfs[x_min][i]-pfs[x_min][j]-pfs[0][i]+pfs[0][j];
            long long pos_r=pfs[n][i]-pfs[n][j]-pfs[x_max][i]+pfs[x_max][j];
            ans+=pos_l*pos_r;
        }
    }
    cout << ans;
}
