#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct info {
    string type;
    int a, b;
};
info sensor[105];

int main()
{
    freopen("traffic.in", "r", stdin);
    freopen("traffic.out", "w", stdout);
    int N; cin >> N;
    for (int i=0; i<N; i++) {
        cin >> sensor[i].type >> sensor[i].a >> sensor[i].b;
    }

    int s=0, e=1000;
    for (int i=N-1; i>=0; i--) {
        if (sensor[i].type=="none") {
            s=max(s, sensor[i].a);
            e=min(e, sensor[i].b);
        }
        if (sensor[i].type=="on") {
            s-=sensor[i].b;
            e-=sensor[i].a;
        }
        if (sensor[i].type=="off") {
            s+=sensor[i].a;
            e+=sensor[i].b;
        }
    }
    cout << max(s, 0) << " " << min(e, 1000) << "\n";

    s=0, e=1000;
    for (int i=0; i<N; i++) {
        if (sensor[i].type=="none") {
            s=max(s, sensor[i].a);
            e=min(e, sensor[i].b);
        }
        if (sensor[i].type=="on") {
            s+=sensor[i].a;
            e+=sensor[i].b;
        }
        if (sensor[i].type=="off") {
            s-=sensor[i].b;
            e-=sensor[i].a;
        }
    }
    cout << max(s, 0) << " " << min(e, 1000);
}
