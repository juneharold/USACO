#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

struct cmp {
    bool operator() (pair<int, int> a, pair<int, int> b) {
        if (a.second==b.second) return a.first<b.first;
        else return a.second<b.second;
    }
};

multiset <pair<int, int>> x_order;
multiset <pair<int, int>, cmp> y_order;

int main()
{
    freopen("reduce.in", "r", stdin);
    freopen("reduce.out", "w", stdout);
    int n; cin >> n;
    for (int i=0; i<n; i++) {
        int x, y; cin >> x >> y;
        x_order.insert({x, y});
        y_order.insert({x, y});
    }

    vector<pair<int, int>> twelve;
    // first 3
    auto start_x=x_order.begin();
    twelve.push_back(*start_x); start_x++;
    twelve.push_back(*start_x); start_x++;
    twelve.push_back(*start_x);
    // last 3
    auto end_x=x_order.end(); end_x--;
    twelve.push_back(*end_x); end_x--;
    twelve.push_back(*end_x); end_x--;
    twelve.push_back(*end_x);
    // first 3
    auto start_y=y_order.begin();
    twelve.push_back(*start_y); start_y++;
    twelve.push_back(*start_y); start_y++;
    twelve.push_back(*start_y);
    // last 3
    auto end_y=y_order.end(); end_y--;
    twelve.push_back(*end_y); end_y--;
    twelve.push_back(*end_y); end_y--;
    twelve.push_back(*end_y);

    long long ans=40005*40005;
    for (int i=0; i<12; i++) {
        for (int j=0; j<12; j++) {
            for (int k=0; k<12; k++) {
                if (i==j or j==k or k==i) continue;

                x_order.erase(twelve[i]);
                x_order.erase(twelve[j]);
                x_order.erase(twelve[k]);
                y_order.erase(twelve[i]);
                y_order.erase(twelve[j]);
                y_order.erase(twelve[k]);

                auto MINX=x_order.begin();
                auto MINY=y_order.begin();
                auto MAXX=x_order.end(); MAXX--;
                auto MAXY=y_order.end(); MAXY--;

                int min_x=MINX->first, min_y=MINY->second, max_x=MAXX->first, max_y=MAXY->second;
                long long area=(max_y-min_y)*(max_x-min_x);
                ans=min(ans, area);

                x_order.insert(twelve[i]);
                x_order.insert(twelve[j]);
                x_order.insert(twelve[k]);
                y_order.insert(twelve[i]);
                y_order.insert(twelve[j]);
                y_order.insert(twelve[k]);
            }
        }
    }
    cout << ans;
}
