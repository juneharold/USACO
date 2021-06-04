#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

long long arr[50005]={};
multiset <int> cases;

int main()
{
    cases.insert({0, 0});
    //freopen("diamond.in", "r", stdin);
    //freopen("diamond.out", "w", stdout);
    long long n, k; cin >> n >> k;
    for (int i=0; i<n; i++) cin >> arr[i];
    sort(arr, arr+n);

    for (int i=0; i<n; i++) {
        // 현재 숫자 arr[i]에서 최대 k인 숫자 찾기
        int ub=upper_bound(&arr[0], &arr[n], arr[i]+k)-&arr[0];
        ub--;
        cases.insert(ub-i+1);
        i=ub;
    }
    long long ans=0;
    auto it=cases.end();
    it--;
    ans+=*it;
    it--;
    ans+=*it;
    cout << ans;
}

/*
7 3
10
5
1
12
9
5
14

2 2
1
1

8 2
1
3
3
3
4
4
4
6

12 2
1
3
3
3
5
5
10
12
12
12
14
14
*/
