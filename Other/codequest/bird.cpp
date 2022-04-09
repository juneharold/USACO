#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct Bird {
    int type;
    double a, b, c, d;
};

int main()
{
    int T; cin >> T;
    while (T--) {
        Bird bird[1005];
        int N, Q; cin >> N >> Q;
        for (int i=1; i<=N; i++) {
            string name; cin >> name;
            if (name[0]=='A') bird[i].type=1;
            if (name[0]=='P') bird[i].type=2;
            if (name[0]=='C') bird[i].type=3;
            cin >> bird[i].a >> bird[i].b >> bird[i].c >> bird[i].d;
        }

        for (int i=1; i<=Q; i++) {
            double w, x, y, z; cin >> w >> x >> y >> z;
            vector<pair<double, int>> dis;
            for (int j=1; j<=N; j++) {
                double dist=(bird[j].a-w)*(bird[j].a-w);
                dist+=(bird[j].b-x)*(bird[j].b-x);
                dist+=(bird[j].c-y)*(bird[j].c-y);
                dist+=(bird[j].d-z)*(bird[j].d-z);
                dis.push_back({dist, bird[j].type});
            }

            sort(dis.begin(), dis.end());

            int ans[4]={}, cnt=0, end=0;
            for (auto pp: dis) {
                if (end==1) break;
                ans[pp.second]++;
                cnt++;
                if (cnt>=5) {
                    if (ans[1]>ans[2] && ans[1]>ans[3]) {
                        cout << "Accipitridae\n";
                        end=1;
                    }
                    if (ans[2]>ans[3] && ans[2]>ans[1]) {
                        cout << "Passeridae\n";
                        end=1;
                    }
                    if (ans[3]>ans[1] && ans[3]>ans[2]) {
                        cout << "Cathartidae\n";
                        end=1;
                    }
                }
            }
        }
    }
}
