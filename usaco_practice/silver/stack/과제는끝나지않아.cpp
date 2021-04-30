/*
stack < pair<int, int> >를 이용. 위에 있는 과제부터 1분씩 감소시킴
시간이 0이 되면 점수 추가.
*/
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main()
{
    int n; cin >> n;
    stack < pair <int, int> > work;
    int score=0;
    for (int i=0; i<n; i++) {
        int x; cin >> x;
        if (x==0 and work.size()>0) {
            work.top().second--;
            if (work.top().second==0) {
                score+=work.top().first;
                work.pop();
            }
        }
        else if (x==1) {
            int a, t; cin >> a >> t;
            work.push(make_pair(a, t-1));
            if (work.top().second==0) {
                score+=work.top().first;
                work.pop();
            }
        }
    }
    cout << score;
    return 0;
}
