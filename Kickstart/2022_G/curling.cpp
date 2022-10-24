#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
#define ll long long
#define f first
#define s second
#define pii pair<ll, ll>

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T; cin >> T;
    for (ll t=1; t<=T; t++) {
        int Rs, Rh, N, M; cin >> Rs >> Rh >> N;
        pii red[10], yel[10];
        for (int i=1; i<=N; i++) {
            cin >> red[i].f >> red[i].s;
            red[i].f=abs(red[i].f);
            red[i].s=abs(red[i].s);
        }
        cin >> M;
        for (int i=1; i<=M; i++) {
            cin >> yel[i].f >> yel[i].s;
            yel[i].f=abs(yel[i].f);
            yel[i].s=abs(yel[i].s);
        }

        vector<int> dist_red, dist_yel; //distance squared
        for (int i=1; i<=N; i++) {
            if (red[i].f*red[i].f+red[i].s*red[i].s<=(Rs+Rh)*(Rs+Rh)) { //  원 안에 있음.
                dist_red.push_back(red[i].f*red[i].f+red[i].s*red[i].s);
            }
        }
        for (int i=1; i<=M; i++) {
            if (yel[i].f*yel[i].f+yel[i].s*yel[i].s<=(Rs+Rh)*(Rs+Rh)) { //  원 안에 있음.
                dist_yel.push_back(yel[i].f*yel[i].f+yel[i].s*yel[i].s);
            }
        }
        //cout << dist_red.size() << ' ' << dist_yel.size() << endl;
        if (dist_red.size()==0) dist_red.push_back(1e9);
        if (dist_yel.size()==0) dist_yel.push_back(1e9);
        sort(dist_red.begin(), dist_red.end());
        sort(dist_yel.begin(), dist_yel.end());

        //cout << dist_red.size() << ' ' << dist_yel.size() << endl;

        int ans=0;
        if (dist_red[0]<dist_yel[0]) {
            for (int x: dist_red) if (x<dist_yel[0]) ans++;
            cout << "Case #" << t << ": " << ans << " 0\n";
        }
        else {
            for (int x: dist_yel) if (x<dist_red[0]) ans++;
            cout << "Case #" << t << ": " << 0 << ' ' << ans << "\n";
        }
    }
}

/*
1
1 5
2
1 0
-3 0
1
0 2

*/
