#include <iostream>
#include <algorithm>
using namespace std;

char arr[1000005]={};
int N, sum[30]={}, cur[30][30]={}, bef[30][30]={}, ans=0;

int main()
{
    cin >> N;
    for (int i=1; i<=N; i++) {
        cin >> arr[i];
    }

    fill(&bef[0][0], &bef[29][29], -1e9);

    for (int i=1; i<=N; i++) {
        int x=arr[i]-'a'+1;
        sum[x]++;

        for (int j=1; j<=26; j++) {
            if (x!=j) {
                bef[x][j]=max(bef[x][j], cur[x][j]);
                cur[x][j]=sum[x]-sum[j];

                ans=max(ans, max(sum[x]-sum[j]+bef[j][x], sum[j]-sum[x]+bef[x][j]));
            }
        }
    }

    cout << ans;
}
