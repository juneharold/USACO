#include <iostream>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

multiset <pair <string, string>> city_state;
multiset <pair <string, string>> state_city;

int main()
{
    freopen("citystate.in", "r", stdin);
    freopen("citystate.out", "w", stdout);
    int n; cin >> n;
    int subtract=0;
    for (int i=0; i<n; i++) {
        string city, state; cin >> city >> state;
        //if (city.substr(0, 2)==state) subtract++;
        city_state.insert({city.substr(0, 2), state});
        state_city.insert({state, city.substr(0, 2)});
    }
    int cnt=0;
    for (auto it: city_state) {
        if (it.first==it.second) continue;
        cnt+=state_city.count(it);
    }
    //cnt-=subtract;
    cout << cnt/2;
}


/*
6
MIAMI MI
MICHIGAN MI
MIGOS MI
TXINT TX
TXUS TX
TXA TX
ans=0

6
MIAMI FL
DALLAS TX
FLINT MI
CLEMSON SC
BOSTON MA
ORLANDO FL
*/
