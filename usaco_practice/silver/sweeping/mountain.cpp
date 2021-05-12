/*
1. y를 기준으로 정렬.
2. set <pair<int, int> >에 이미 가려진 범위 넣기
3. y줄을 하나 내려갈 때마다 가려진 범위 좌우로 +1.
4. 만약 새로운 산이 가려진 범위 밖이면, counter++ 하고 범위 추가.

time complexity
set의 최대 길이?

*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

pair <int, int> yx[100005];
vector <pair <int, int> > range;

int main()
{
    //freopen("mountains.in", "r", stdin);
    //freopen("mountains.out", "w", stdout);
    int n; cin >> n;
    for (int i=0; i<n; i++) {
        cin >> yx[i].second >> yx[i].first;
    }
    sort(yx, yx+n);
    reverse(yx, yx+n); //from large to small
    int cnt=1;
    int prev_y=yx[0].first;
    range.push_back(make_pair(yx[0].second, yx[0].second));
    for (int i=1; i<n; i++) {
        int dy=prev_y-yx[i].first;
        bool ind=true;
        for (int j=0; j<range.size(); j++) {
            range[j].first-=dy;
            range[j].second+=dy;
            if (range[j].first<=yx[i].second && yx[i].second<=range[j].second) ind=false;
        }
        if (ind==true) {
            cnt++;
            range.push_back(make_pair(yx[i].second, yx[i].second));
        }
        prev_y=yx[i].first;
    }
    cout << cnt;
}

/*
3
4 6
7 2
2 5

3
1 3
4 3
3 3

3
3 3
1 2
3 1


*/
