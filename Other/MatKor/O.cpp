#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

int A[3][3]={}, B[3][3]={}, C[3][3]={};

void press(int a, int b, int x) {
    for (int j=1; j<=2; j++) {
        B[a][j]+=x;
        if (B[a][j]>4) B[a][j]-=4;
    }
    for (int i=1; i<=2; i++) {
        if (i==a) continue;
        B[i][b]+=x;
        if (B[i][b]>4) B[i][b]-=4;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) {
        char c; cin >> c;
        A[i][j]=c-'0';
    }
    for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) {
        char c; cin >> c;
        C[i][j]=c-'0';
    }
    int ans=1e9;
    for (int i=0; i<=3; i++) {
        for (int j=0; j<=3; j++) {
            for (int k=0; k<=3; k++) {
                for (int l=0; l<=3; l++) {
                    for (int x=1; x<=N; x++) for (int y=1; y<=N; y++) B[x][y]=A[x][y];
                    press(1, 1, i);
                    press(1, 2, j);
                    press(2, 1, k);
                    press(2, 2, l);
                    bool same=true;
                    for (int x=1; x<=N; x++) for (int y=1; y<=N; y++) if (B[x][y]!=C[x][y]) same=false;
                    if (same) ans=min(ans, i+j+k+l);
                }
            }
        }
    }
    cout << (ans==1e9 ? -1 : ans);
}
