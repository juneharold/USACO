#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
#define f first
#define s second

const long long MAX=1e5+5;
long long N, M;
pair<long long, long long> dish[MAX];

int main()
{
    freopen("hayfeast.in", "r", stdin);
    freopen("hayfeast.out", "w", stdout);
    cin >> N >> M;
    for (long long i=0; i<N; i++) cin >> dish[i].f >> dish[i].s;

    multiset<long long> meal;
    long long t_flavor=0, r=0, l=0, ans=1e9;

    while (r<=N) {
        meal.insert(dish[r].s);
        t_flavor+=dish[r].f;
        r++;

        while (t_flavor-dish[l].f>=M) {
            if (meal.find(dish[l].s)!=meal.end()) meal.erase(meal.find(dish[l].s));
            t_flavor-=dish[l].f;
            l++;
        }

        if (t_flavor>=M) {
            auto it=meal.end();
            it--;
            ans=min(ans, *it);
        }
    }
    cout << ans;
}

/*
10 5
1 1
1 2
1 3
1 3
1 10
1 9
1 9
1 9
1 9
1 9
*/
