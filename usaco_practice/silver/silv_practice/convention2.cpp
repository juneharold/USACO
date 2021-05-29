#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

struct info {
    int arrive, spend, senior;
};

struct cmp {
    bool operator() (info a, info b) {
        return a.senior>b.senior;
    }
};

bool sml (info a, info b) {
    return a.arrive<b.arrive;
}

multiset <info, cmp> s;
info cows[100005]={};

int main()
{
    freopen("convention2.in", "r", stdin);
    freopen("convention2.out", "w", stdout);
    int n; cin >> n;
    for (int i=0; i<n; i++) {
        cin >> cows[i].arrive >> cows[i].spend;
        cows[i].senior=n-i;
    }
    sort(cows, cows+n, sml);
    int ind=0, time=0, ans=0;
    while (true) {
        if (ind==n and s.size()==0) break;

        if (cows[ind].arrive<=time) {
            for (int i=ind; i<n; i++) {
                if (cows[i].arrive<=time) s.insert(cows[i]);
                else break;
                ind++;
            }
        }
        else if (s.size()==0) {
            int tmp=cows[ind].arrive;
            for (int i=ind; i<n; i++) {
                if (tmp!=cows[i].arrive) break;
                s.insert(cows[i]);
                ind++;
            }
        }

        auto it=s.begin();
        if (s.size()!=0) ans=max(ans, time-(*it).arrive);
        time=max((*it).arrive+(*it).spend, time+(*it).spend);
        s.erase(it);
        //cout << time << "\n";
    }
    cout << ans;
}
