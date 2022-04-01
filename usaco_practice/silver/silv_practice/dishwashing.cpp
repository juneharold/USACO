#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
#define f first
#define s second

int dish[100005]={};
set<pair<int, int>> s;
priority_queue<int> pq;

int main()
{
    freopen("dishes.in", "r", stdin);
    freopen("dishes.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    for (int i=1; i<=N; i++) cin >> dish[i];

    int clean_top=0, largest=0;
    for (int i=1; i<=N; i++) {
        if (dish[i]<clean_top) {
            cout << i-1;
            exit(0);
        }

        if (s.empty()) {
            pq.push(-dish[i]);
            s.insert({0, dish[i]});
        }
        else if (dish[i]>largest) {
            pq.push(-dish[i]);
            s.insert({largest, dish[i]});
        }
        else {
            auto it=s.lower_bound(make_pair(dish[i], 0));
            it--;
            int a=(*it).f, b=(*it).s;

            if (a<dish[i] && dish[i]<b) {
                pq.push(-dish[i]);
                s.erase(it);
                s.insert({a, dish[i]});
            }
            else {
                while (!pq.empty() && -pq.top()<dish[i]) {
                    if ((*s.begin()).s<-pq.top()) s.erase(s.begin());
                    clean_top=-pq.top();
                    pq.pop();
                }
                if (pq.empty()) largest=dish[i];
                pq.push(-dish[i]);
                s.erase(s.begin());
                s.insert({0, dish[i]});
            }
        }
        largest=max(largest, dish[i]);
    }
    cout << N;
}
