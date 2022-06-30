#include <iostream>
using namespace std;

int main()
{
    int T; cin >> T;
    for (int t=1; t<=T; t++) {
        int N, M, sum=0; cin >> N >> M;
        for (int i=0; i<N; i++) {
            int x; cin >> x;
            sum+=x;
        }
        cout << "Case #" << t << ": " << sum%M << "\n";
    }
}
