#include <iostream>
#include <cmath>
using namespace std;

int cnt[1000005]={};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    for (int i=1; i<=N; i++) {
        int x; cin >> x;
        for (int i=1; i*i<=x; i++) {
            if (x%i==0) {
                cnt[i]++;
                if (x/i!=i) cnt[x/i]++;
            }
        }
    }

    for (int i=1000000; i>=1; i--) if (cnt[i]>=2) {
        cout << i;
        exit(0);
    }
}
