#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

int N;
struct Event {
    int time, y, type;
};
vector<Event> A;

bool cmp (Event a, Event b) {return a.time<b.time;}

int main()
{
    cin >> N;
    for (int i=0; i<N; i++) {
        int a, b, r; cin >> a >> b >> r;
        int t2=abs(a)*r, t1=t2-r;
        A.push_back({t1, b, 1});
        A.push_back({t2, b, -1});
    }

    sort(A.begin(), A.end(), cmp);

    set<int> active, ans; //y_pos 저장.
    for (int i=0; i<A.size(); i++) {
        for (int j=i; j<A.size() && A[i].time==A[j].time; j++) {
            if (A[j].type==1) active.insert(A[j].y);
            else active.erase(A[j].y);
        }
        if (!active.empty()) ans.insert(*active.begin());
        
    }
    cout << ans.size();

}
