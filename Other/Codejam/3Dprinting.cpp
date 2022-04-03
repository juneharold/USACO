#include<iostream>
using namespace std;

const int MAX=1e9;

int main()
{
    int T; cin >> T;
    for (int t=1; t<=T; t++) {
        int have[4]={MAX, MAX, MAX, MAX};
        for (int i=0; i<3; i++) {
            int C, M, Y, K; cin >> C >> M >> Y >> K;
            have[0]=min(have[0], C);
            have[1]=min(have[1], M);
            have[2]=min(have[2], Y);
            have[3]=min(have[3], K);
        }
        cout << "Case #" << t << ": ";
        if (have[0]+have[1]+have[2]+have[3]<1e6) {
            cout << "IMPOSSIBLE\n";
            continue;
        }

        int need=1e6;
        for (int i=0; i<4; i++) {
            cout << min(need, have[i]) << " ";
            need-=min(need, have[i]);
        }
        cout << "\n";
    }
}
