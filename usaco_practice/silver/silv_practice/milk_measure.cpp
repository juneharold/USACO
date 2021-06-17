#include <iostream>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

map <int, int> current;
multiset <int> values;

struct measurement {
    int day, cow_id, change;
};
measurement milk[100005]={};

bool cmp (measurement a, measurement b) {
    return a.day<b.day;
}

int main()
{
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);
    int n, g; cin >> n >> g;
    for (int i=0; i<n; i++) cin >> milk[i].day >> milk[i].cow_id >> milk[i].change;
    sort (milk, milk+n, cmp);
    long long ans=0;
    for (int i=0; i<n+1; i++) values.insert(g);
    for (int i=0; i<n; i++) {
        int id=milk[i].cow_id, dm=milk[i].change;

        auto M = values.end();
        M--;
        int cnt=values.count(*M);

        auto second=values.end();
        second--;
        second--;

        if (current.count(id)==0) {
            values.erase(values.find(g));
            current[id]=g+dm;
            values.insert(current[id]);
        }
        else {
            values.erase(values.find(current[id]));
            current[id]+=dm;
            values.insert(current[id]);
        }

        auto M2 = values.end();
        M2--;
        int cnt2=values.count(*M);

        if (cnt>1) {
            if (cnt2!=cnt) ans++;
            else if (current[id]>=*M) ans++;
        }
        else if (cnt==1) {
            if (*M2==*M and cnt!=cnt2) ans++;
            else if (cnt2==0 and current[id]<=*second) ans++;
            else if (*M2>*M) ans++;
        }

    }
    cout << ans;
}

/*
4 10
1 1 +2
4 2 -1
7 3 +3
9 3 -1

3 10
1 1 +2
2 1 -1
3 1 -1
ans=2

5 10
1 1 -1
2 2 -1
3 3 -1
4 4 -1
5 4 +1

3 10
1 1 +1
1 1 -1
1 1 +1

3 10
1 1 +2
2 2 +2
3 2 -1

3 10
1 1 +2
2 1 -1
3 1 -1

2 10
1 1 +1
1 1 -1
*/
