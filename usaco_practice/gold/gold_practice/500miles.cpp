#include <iostream>
#include <algorithm>
using namespace std;

int N, K;

int main()
{
    long long ans=2019201997;
    cin >> N >> K;
    for (int x=1; x<=K-1; x++) {
        for (int y=x+1; y<=N; y++) {
            long long temp=2019201997-84*x-48*y;
            if (temp<ans) ans=temp;
        }
    }
    cout << ans;
}
