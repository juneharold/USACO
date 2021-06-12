#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

struct info {
    int start_m, start_d, end_m, end_d;
};
bool cmp (info a, info b){
    if (a.start_m==b.start_m) return a.start_d<b.start_d;
    return a.start_m<b.start_m;
};

info dates[100005];
multiset <pair<int, int>> ending;

int main()
{
    int n; cin >> n;
    for (int i=0; i<n; i++) {
        cin >> dates[i].start_m >> dates[i].start_d >> dates[i].end_m >> dates[i].end_d;
    }
    sort(dates, dates+n, cmp);
    pair <int, int> until={3, 1};
    int ind=0, cnt=0;
    for (int i=0; i<n; i++) {
        if ((until.first==11 and until.second==31) or (until.first==12)) break;
        while (ind<n && ((dates[ind].start_m==until.first && dates[ind].start_d<=until.second) || (dates[ind].start_m<until.first))) {
            ending.insert({dates[ind].end_m, dates[ind].end_d});
            ind++;
        }
        if (ending.empty()) {
            cout << 0;
            exit(0);
        }
        auto it=ending.end();
        it--;
        until={it->first, it->second};
        cnt++;
    }
    if ((until.first==11 and until.second==31) or (until.first==12)) cout << cnt;
    else cout << 0;
}
