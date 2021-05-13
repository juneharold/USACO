#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

struct event {
    //누가 언제 뭘
    int who, when, what;
};

vector<event> lg;

bool cmp (event a, event b) {
    return a.when < b.when;
}

int cnt[100005]={}; //alone

int main()
{
    int n; cin >> n;
    for (int i=1; i<=n; i++) {
        int s, e; cin >> s >> e;
        lg.push_back({i, s, 1});
        lg.push_back({i, e, -1});
    }
    sort(lg.begin(), lg.end(), cmp);
    set <int> active;
    int time=0;
    for (int i=0; i<lg.size(); i++) {
        if (active.size()==1) {
            cnt[*active.begin()]+=lg[i].when-lg[i-1].when;
        }

        if (active.size()>0) {
            time+=lg[i].when-lg[i-1].when;
        }

        if (lg[i].what==1) {
            active.insert(lg[i].who);
        }
        else if (lg[i].what==-1) {
            active.erase(lg[i].who);
        }
    }
    //cout << time;
    //for (int i=1; i<=n; i++) cout << cnt[i] << "\n";
    // 최솟값 찾기.
    int small=1e9;
    for (int i=1; i<=n; i++) if (cnt[i]<small) small=cnt[i];
    cout << time-small;
    return 0;
}
