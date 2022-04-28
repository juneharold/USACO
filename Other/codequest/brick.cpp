#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int N; cin >> N;
    for (int i=0; i<N; i++) {
        int a, b, goal; cin >> a >> b >> goal;
        int x1=min(b, goal/5)*5;
        int need=goal-x1;
        if (a>=need) cout << "true\n";
        else cout << "false\n";
    }
}
/*

3
3 1 8
3 1 9
3 2 10
*/
