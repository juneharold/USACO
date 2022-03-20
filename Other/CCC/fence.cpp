#include <iostream>
using namespace std;

double h[10005]={}, w[10005]={};

int main()
{
    int N; cin >> N;
    for (int i=1; i<=N+1; i++) cin >> h[i];
    for (int i=1; i<=N; i++) cin >> w[i];

    double ans=0;
    for (int i=1; i<=N; i++) {
        ans+=w[i]*(h[i]+h[i+1])/2.0;
    }
    cout << fixed << ans;
    return 0;
}
