#include <iostream>
#include <algorithm>
using namespace std;
#define f first
#define s second

int N, B, dp[(1<<20)]={}, s[21][21];
struct bns {
    int k, p, a;
};
bns bonus[21];

int bitcount(int A){
  if (A==0) return 0;
  return A%2 + bitcount(A / 2);
}

int main()
{
    freopen("dec.in", "r", stdin);
    freopen("dec.out", "w", stdout);
    cin >> N >> B;

    for (int i=0; i<B; i++) {
        int k, p, a;
        cin >> k >> p >> a;
        bonus[i]={k, p, a};
    }

    for (int i=0; i<N; i++) for (int j=1; j<=N; j++) cin >> s[i][j];

    for (int i=0; i<(1<<N); i++) {
        int K=bitcount(i);
        for (int c=0; c<N; c++) if (i&(1<<c)) {
            int bef=i^(1<<c);
            int res=dp[bef]+s[c][K];
            
            int add=0;
            for (int i=0; i<B; i++) {
                if (bonus[i].k==K && bonus[i].p<=res) add+=bonus[i].a;
            }
            res+=add;

            dp[i]=max(dp[i], res);
        }
    }

    cout << dp[(1<<N)-1];
}

/*
3 2
2 7 6
3 0 100
5 1 7
2 2 4
4 2 1
*/
