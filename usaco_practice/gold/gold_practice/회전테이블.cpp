#include <iostream>
#include <algorithm>
using namespace std;

const int MAX=105;
int N, sz[3]={}, dp[MAX][MAX][MAX][3]={}, arr[3][MAX]={};

int cost (int a, int b) {
    int d=abs(a-b);
    d%=N;
    return min(d, N-d);
}

int solve(int i, int j, int k, int l) {
    if (dp[i][j][k][l]!=1e9) return dp[i][j][k][l];
    
}

int main()
{
    cin >> N;
    for (int i=0; i<3; i++) {
        cin >> sz[i];
        for (int j=1; j<=sz[i]; j++) {
            cin >> arr[i][j]; arr[i][j]--;

            if (i==1) arr[i][j]=(arr[i][j]+N/3*2)%N;
            if (i==2) arr[i][j]=(arr[i][j]+N/3)%N;
        }
    }
    arr[1][0]=N/3; arr[2][0]=N/3*2;

    fill(&dp[0][0][0][0], &dp[MAX-1][MAX][MAX][3], 1e9);

    /*
    for (int i=0; i<=sz[0]; i++) {
        for (int j=0; j<=sz[1]; j++) {
            for (int k=0; k<=sz[2]; k++) {
                for (int l=0; l<3; l++) {
                    cout << dp[i][j][k][l] << " ";
                }
                cout << "\n";
            }
        }
    }*/

}
