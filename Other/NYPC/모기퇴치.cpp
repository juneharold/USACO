#include <iostream>
using namespace std;

int a[55][55]={};

int main()
{
    int N, M; cin >> N >> M;
    for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) cin >> a[i][j];

    int ans=0;
    for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) {
        // 가로세로.
        int temp=a[i][j];
        for (int k=1; k<=M; k++) {
            if (i+k<=N) temp+=a[i+k][j];
            if (i-k>=1) temp+=a[i-k][j];
            if (j+k<=N) temp+=a[i][j+k];
            if (j-k>=1) temp+=a[i][j-k];
        }
        ans=max(ans, temp);
        //대각선
        temp=a[i][j];
        for (int k=1; k<=M; k++) {
            if (i+k<=N && j+k<=N) temp+=a[i+k][j+k];
            if (i-k>=1 && j-k>=1) temp+=a[i-k][j-k];
            if (i-k>=1 && j+k<=N) temp+=a[i-k][j+k];
            if (i+k<=N && j-k>=1) temp+=a[i+k][j-k];
        }
        ans=max(ans, temp);
    }
    cout << ans;
}
