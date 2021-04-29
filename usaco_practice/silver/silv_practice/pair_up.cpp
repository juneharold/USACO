#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

pair <int, int> cows[100005]; //first is output amount, second is the number of cows

int main()
{
    //freopen("pairup.in", "r", stdin);
    //freopen("pairup.out", "w", stdout);
    int n; cin >> n;
    for (int i=0; i<n; i++) {
        cin >> cows[i].second >>  cows[i].first;
    }
    sort(cows, cows+n); //시간에 따라 오름차순 정리
    int maxnum=0, low=0, high=n-1;
    while (low <= high) {
        int x = min(cows[low].second, cows[high].second);
        if (low==high) x /= 2;
        maxnum = max(maxnum, cows[low].first + cows[high].first);
        cows[low].second -= x;
        cows[high].second -= x;
        if (cows[low].second == 0) low++;
        if (cows[high].second == 0) high--;
    }
    cout << maxnum;
}

/*
7
2 1
2 3
1 6
1 7
3 8
1 10
2 11
*/
