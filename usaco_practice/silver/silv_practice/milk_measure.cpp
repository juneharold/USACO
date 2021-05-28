#include <iostream>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

map <int, int> current;
multiset <int> values;

struct measurement {
    int day, cow_id, change;
};
measurement milk[100005]={};

bool cmp (measurement a, measurement b) {
    return a.day<b.day;
}

int main()
{
    //freopen("measurement.in", "r", stdin);
    //freopen("measurement.out", "w", stdout);
    int n, g; cin >> n >> g;
    for (int i=0; i<n; i++) cin >> milk[i].day >> milk[i].cow_id >> milk[i].change;
    sort (milk, milk+n, cmp);
    long long ans=0;
    long long M=g, cnt=1e9; //2번째 최대 변수 만들기.
    values.insert(g);
    for (int i=0; i<n; i++) {
        int id=milk[i].cow_id, dm=milk[i].change;

        bool max_alone=false;
        if (current.count(id)==1 and current[id]==M and cnt==1) max_alone=true;

        // id가 존재하면 +dm, 존재 안하면 g+dm
        if (current.count(id)==0) {
            current[id]=g+dm;
            values.insert(current[id]);
        }
        else {
            values.erase(current[id]);
            current[id]+=dm;
            values.insert(current[id]);
        }

        /*
        for (auto x: values) {
            cout << x << " ";
        }
        cout << "\n";

        for (int j=1; j<=3; j++) {
            if (current.count(j)==0) cout << 10 << " ";
            else cout << current[j] << " ";
        }*/

        //예외
        if (max_alone==true and current[id]<g) {
            M=g;
            cnt=1e9;
            ans++;
            continue;
        }

        if (max_alone==true and current[id]>=M) {
            M=max(g, current[id]);
            continue;
        }
        else if (max_alone==true and current[id]<M) {
            auto it = values.end();
            it--;
            it--;
            int second_large=*it;
            if (current[id]>second_large) {
                M=max(g, current[id]);
            }
            else if (current[id]==second_large) {
                M=max(g, second_large);
                if (M==g) cnt=1e9;
                else cnt=values.count(second_large);
                ans++;
            }
            else {
                M=max(g, second_large);
                if (M==g) cnt=1e9;
                else cnt=values.count(second_large);
                ans++;
            }
            continue;
        }

        // 바뀐 값이 큰지 작은지
        if (current[id]>M) {
            M=max(g, current[id]);
            if (M==g) cnt=1e9;
            else cnt=1;
            ans++;
        }
        else if (current[id]==M and dm!=0) {
            cnt++;
            ans++;
        }
    }
    cout << ans;
}

/*
4 10
1 1 -1
2 2 -1
3 3 -1
4 4 -1
*/

/*
최대 숫자, 그 수를 가진 소의 마릿수
최대 숫자 or 그 수를 가진 소의 마릿수 가 바꼈을 때 cnt++;
예외:
1) 혼자 최대였는데 늘어날때
2) 혼자 최대였고, 줄어들어도 최대일때
3) g보다 최대가 작아젔을 때--> 최대=g, 마릿수=1e9
4) 최대가 g였는데 g보다 커질 때?
*/
