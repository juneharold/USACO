#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T; cin >> T;
    for (int t=1; t<=T; t++)
    {
        ll R, C, K; cin >> R >> C >> K;
        ll r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;

        ll ans=0;
        ll rlen=r2-r1+1, clen=c2-c1+1;

        if (r1==1 && c1==1 && r2==R && c2==C) ans=0; // 4면 맞닿아있음
        else if (r1==1 && c1==1 && r2==R) ans=(R-1+K)/K; // 3면 맞닿아있음
        else if (r1==1 && c1==1 && c2==C) ans=(C-1+K)/K; // 3면 맞닿아있음
        else if (r2==R && c2==C && r1==1) ans=(R-1+K)/K; // 3면 맞닿아있음
        else if (r2==R && c2==C && c1==1) ans=(C-1+K)/K; // 3면 맞닿아있음
        else if (r1==1 && c1==1) ans=(rlen-1+K)/K+(clen-1+K)/K; // 인접한 2면 맞닿아있음
        else if (r1==1 && c2==C) ans=(rlen-1+K)/K+(clen-1+K)/K; // 인접한 2면 맞닿아있음
        else if (r2==R && c2==C) ans=(rlen-1+K)/K+(clen-1+K)/K; // 인접한 2면 맞닿아있음
        else if (r2==R && c1==1) ans=(rlen-1+K)/K+(clen-1+K)/K; // 인접한 2면 맞닿아있음
        else if (r1==1 && r2==R) ans=(R-1+K)/K*2; // 반대 2면 맞닿아있음
        else if (c1==1 && c2==C) ans=(C-1+K)/K*2; // 반대 2면 맞닿아있음
        else if (r1==1 || r2==R) ans=(rlen-1+K)/K*2+(clen-1+K)/K; // 1면 맞닿아있음
        else if (c1==1 || c2==C) ans=(rlen-1+K)/K+(clen-1+K)/K*2; // 1면 맞닿아있음
        else { // 0면 맞닿아있음
            ans=(r2-1+K)/K+(rlen-1+K)/K+(clen-1+K)/K*2;
            ans=min(ans, ((R-r1+1)-1+K)/K+(rlen-1+K)/K+(clen-1+K)/K*2);
            ans=min(ans, (c2-1+K)/K+(clen-1+K)/K+(rlen-1+K)/K*2);
            ans=min(ans, ((C-c1+1)-1+K)/K+(clen-1+K)/K+(rlen-1+K)/K*2);
        }

        // K*K 정사각형으로 나누기
        ll rpoint=(rlen-1+K)/K, cpoint=(clen-1+K)/K;
        ans+=rpoint*(cpoint-1)+cpoint*(rpoint-1);

        // 나머지 커트
        ans+=(rlen/K)*(clen/K)*(K*K-1);
        if (rlen%K!=0) ans+=(clen/K)*(K*(rlen%K)-1);
        if (clen%K!=0) ans+=(rlen/K)*(K*(clen%K)-1);
        if (rlen%K!=0 && clen%K!=0) ans+=(rlen%K)*(clen%K)-1;

        cout << "Case #" << t << ": " << ans << "\n";
    }
}
/*
1
10 10 3
1 1 6 6
*/
