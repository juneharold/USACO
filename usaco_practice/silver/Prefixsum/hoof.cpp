#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int fj[100005]={};
int pfs[3][100005]={};

int main()
{
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    int N; cin >> N;
    for (int i=1; i<=N; i++) {
        char a; cin >> a;
        if (a=='H') fj[i]=0;
        if (a=='P') fj[i]=1;
        if (a=='S') fj[i]=2;
    }
    for (int i=1; i<=N; i++) {
        pfs[0][i]=pfs[0][i-1];
        pfs[1][i]=pfs[1][i-1];
        pfs[2][i]=pfs[2][i-1];

        if (fj[i]==0) pfs[0][i]=pfs[0][i-1]+1;
        if (fj[i]==1) pfs[1][i]=pfs[1][i-1]+1;
        if (fj[i]==2) pfs[2][i]=pfs[2][i-1]+1;
    }

    int ans=0;
    for (int i=0; i<=N; i++) {
        int temp=max(pfs[0][i]-pfs[0][0], max(pfs[1][i]-pfs[1][0], pfs[2][i]-pfs[2][0]));
        temp+=max(pfs[0][N]-pfs[0][i], max(pfs[1][N]-pfs[1][i], pfs[2][N]-pfs[2][i]));
        ans=max(ans, temp);
    }
    cout << ans;
}
