#include <iostream>
#include <algorithm>
using namespace std;

const int MAX=1e5+5;
int N;
struct Plan{
    int t, x, y;
};
Plan plan[MAX];

bool cmp (Plan a, Plan b) { return a.t<b.t; }

int main()
{
    cin >> N;
    for (int i=1; i<=N; i++) cin >> plan[i].t >> plan[i].x >> plan[i].y;

    sort(&plan[1], &plan[N+1], cmp);

    int X=0, Y=0, T=0;
    for (int i=1; i<=N; i++) {
        int dt=plan[i].t-T, mindis=abs(plan[i].x-X)+abs(plan[i].y-Y);

        if (dt-mindis>=0 && (dt-mindis)%2==0) {
            X=plan[i].x, Y=plan[i].y, T=plan[i].t;
        }
        else {
            cout << "No";
            exit(0);
        }
    }
    cout << "Yes";
}
