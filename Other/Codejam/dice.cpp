#include <iostream>
#include <algorithm>
using namespace std;

const int MAX=1e6+5;
int S[MAX]={};

int main()
{
    int T; cin >> T;
    for (int t=1; t<=T; t++) {
        int N; cin >> N;
        for (int i=0; i<N; i++) cin >> S[i];
        sort(S, S+N);

        int ans=0, need=1;
        for (int i=0; i<N; i++) {
            if (S[i]>=need) {
                ans++;
                need++;
            }
        }

        cout << "Case #" << t << ": " << ans << "\n";
    }
}
