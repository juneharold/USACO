#include<iostream>
using namespace std;

int main()
{
    int T; cin >> T;
    for (int t=1; t<=T; t++) {
        int R, C; cin >> R >> C;
        cout << "Case #" << t << ":\n";
        for (int i=0; i<R; i++) {
            for (int j=0; j<=2*C; j++) {
                if ((i==0 && j==0) || (i==0 && j==1)) {
                    cout << '.';
                    continue;
                }
                if (j%2==0) cout << '+';
                else cout << '-';
            }
            cout << "\n";
            for (int j=0; j<=2*C; j++) {
                if (i==0 && j==0) {
                    cout << '.';
                    continue;
                }
                if (j%2==0) cout << '|';
                else cout << '.';
            }
            cout << "\n";
        }
        for (int j=0; j<=2*C; j++) {
            if (j%2==0) cout << '+';
            else cout << '-';
        }
        cout << "\n";
    }
}
