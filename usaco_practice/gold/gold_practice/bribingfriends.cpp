/*
sort cow by smallest icecream
dp[i][j]=ith cow, j mooney left, maximum pair of {popularity, icecrem left}
pick ith cow
dp[i][j]={dp[i-1][j-money_spent].f+P[i], dp[i-1][j-money_spent].s-ice_cream}
*/
#include <iostream>
#include <algorithm>
using namespace std;
#define f first
#define s second
#define ll long long

int N, A, B; 
pair<int, pair<int, int> > XCP[2005];
pair<int, int> dp[2005][2005]={};

int main()
{
    cin >> N >> A >> B;
    for (int i=1; i<=N; i++) cin >> XCP[i].s.s >> XCP[i].s.f >> XCP[i].f;
    sort(&XCP[1], &XCP[N+1]);

    fill(&dp[0][0], &dp[N+1][N+1], make_pair(-1e9, 0));
    dp[0][A]=make_pair(0, B);

    for (int i=0; i<N; i++) {
        for (int j=0; j<=A; j++) {
            if (dp[i][j].f!=-1e9) {
                dp[i+1][j]=max(dp[i+1][j], dp[i][j]);
                
                int X=XCP[i+1].f, C=XCP[i+1].s.f, P=XCP[i+1].s.s, ice_used, mooney_used;
                if (dp[i][j].s>=X*C) { //if discount greater than cost
                    ice_used=X*C;
                    mooney_used=0;
                }
                else { // use maximum ice 
                    ice_used=dp[i][j].s/X*X;
                    mooney_used=C-dp[i][j].s/X;
                }
                if (j-mooney_used<0) continue;
                dp[i+1][j-mooney_used]=max(dp[i+1][j-mooney_used], make_pair(dp[i][j].f+P, dp[i][j].s-ice_used));
            }
        }
    }

    int ans=0;
    for (int j=0; j<=A; j++) ans=max(ans, dp[N][j].f);
    cout << ans;

    cout << endl;
    for (int i=0; i<=N; i++) {
        for (int j=0; j<=A; j++) {
            cout << dp[i][j].f << " " << dp[i][j].s << "   ";
        }
        cout << endl;
    }
}

/*
5 3 50
10 1 32
15 1 33
19 1 35
29 1 43
47 1 50

*/