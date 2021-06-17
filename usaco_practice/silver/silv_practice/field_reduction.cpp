/*
x좌표 기준으로 정렬했을때, 처음 3개, 마지막 3개
y좌표 기준으로 정렬했을때, 처음 3개, 마지막 3개
--> 총 12개중 최선의 3개를 고른다.
*/

#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

struct cmp {
    bool operator() (pair<int , int> a, pair<int , int> b) {
        if (a.second==b.second) return a.first<b.first;
        else return a.second<b.second;
    }
};

set <pair<int , int>> x_order;
set <pair<int , int>, cmp> y_order;

int main()
{
    freopen("reduce.in", "r", stdin);
    freopen("reduce.out", "w", stdout);
    int n; cin >> n;
    for (int i=0; i<n; i++) {
        int  x, y; cin >> x >> y;
        x_order.insert({x, y});
        y_order.insert({x, y});
    }

    vector<pair<int , int>> MAXX;
    vector<pair<int , int>> MINX;
    vector<pair<int , int>> MAXY;
    vector<pair<int , int>> MINY;
    // first 3
    auto start_x=x_order.begin();
    MINX.push_back(*start_x); start_x++;
    MINX.push_back(*start_x); start_x++;
    MINX.push_back(*start_x); start_x++;
    MINX.push_back(*start_x);
    // last 3
    auto end_x=x_order.end(); end_x--;
    MAXX.push_back(*end_x); end_x--;
    MAXX.push_back(*end_x); end_x--;
    MAXX.push_back(*end_x); end_x--;
    MAXX.push_back(*end_x);
    // first 3
    auto start_y=y_order.begin();
    MINY.push_back(*start_y); start_y++;
    MINY.push_back(*start_y); start_y++;
    MINY.push_back(*start_y); start_y++;
    MINY.push_back(*start_y);
    // last 3
    auto end_y=y_order.end(); end_y--;
    MAXY.push_back(*end_y); end_y--;
    MAXY.push_back(*end_y); end_y--;
    MAXY.push_back(*end_y); end_y--;
    MAXY.push_back(*end_y);

    long long ans=40005*40005;
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            for (int k=0; k<4; k++) {
                for (int l=0; l<4; l++) {
                    int max_x=MAXX[i].first, min_x=MINX[j].first, max_y=MAXY[k].second, min_y=MINY[l].second;

                    int cnt=0;
                    for (auto x: x_order) {
                        if (x.first>max_x or x.first<min_x) cnt++;
                        else if (x.second>max_y or x.second<min_y) cnt++;
                    }

                    if (cnt<=3) {
                        long long area=(max_x-min_x)*(max_y-min_y);
                        ans=min(area, ans);
                    }
                }
            }
        }
    }
    cout << ans;
}

/*
6
1 3
1 4
2 5
2 6
2 7
1 8
*/
