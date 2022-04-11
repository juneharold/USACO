#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    for (int i=1; i<=N; i++) {
        int x, ans=0; cin >> x;
        for (int i=1; i<=sqrt(x); i++) {
            if (x%i==0) ans+=2;
        }
        int temp=sqrt(x);
        if (temp*temp==x) ans--;
        cout << ans << "\n";
    }
}
