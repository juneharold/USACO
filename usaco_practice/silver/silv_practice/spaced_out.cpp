#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, a[1005][1005]={}, ans1=0, ans2=0;
int main()
{
    cin >> N;
    for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) cin >> a[i][j];

    for (int i=1; i<=N; i++) {
        int temp[2]={};
        for (int j=1; j<=N; j++) {
            temp[(j%2)]+=a[i][j];
        }
        ans1+=max(temp[0], temp[1]);
    }

    for (int j=1; j<=N; j++) {
        int temp[2]={};
        for (int i=1; i<=N; i++) {
            temp[(i%2)]+=a[i][j];
        }
        ans2+=max(temp[0], temp[1]);
    }

    cout << max(ans1, ans2);
}
