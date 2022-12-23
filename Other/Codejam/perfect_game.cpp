#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int P[1005], L[1005];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T; cin >> T;
    for (int t=1; t<=T; t++) {
        int N; cin >> N;
        for (int i=1; i<=N; i++) cin >> L[i];
        for (int i=1; i<=N; i++) cin >> P[i];

        cout << "Case #" << t << ": ";
    }
}

/*
1 1 1 1
50 0 20 20
0231

50*80*80*100

chance of ending at 1st level = 0.5
chance of ending at 2nd level = 0.5*0.2 = 0.1
chance of ending at 3rd level = 0.5*0.8*0.2 = 0.08
chances of ending at 4th level = 0
chance of success = 0.5*0.8*0.8*1 = 0.32


3
100 80 50
40 20 80
ans 2 0 1

2 0 1
0.2*0.6*0.8
50 100 80
chance of ending at 1st level = 0.8
2nd level = 0.2*0.4 = 0.08
3rd level = 0.2*0.6*0.2 = 0.024
clear = 0.096


1 0 2
0.8*0.6*0.2
80 100 50
chance of ending at 1st level = 0.2
2nd level = 0.8*0.4 = 0.32
3rd level = 0.8*0.6*0.8 = 0.384
clear = 0.096

*/
