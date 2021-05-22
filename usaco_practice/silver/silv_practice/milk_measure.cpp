#include <iostream>
#include <algorithm>
using namespace std;

int cur[100005]={};

struct measurement {
    int day, cow_num, change;
};
measurement milk[100005]={};

bool cmp (measurement a, measurement b) {
    return a.day<b.day;
}

int main()
{
    int n, g; cin >> n >> g;
    for (int i=1; i<=n; i++) cur[i]=g;
    for (int i=0; i<n; i++) cin >> milk[i].day >> milk[i].cow_num >> milk[i].change;
    sort (milk, milk+n, cmp);
}
