#include <iostream>
#include <string>
using namespace std;

char word[200005]={};

int main()
{
    int T; cin >> T;
    for (int t=1; t<=T; t++) {
        int N; cin >> N;
        for (int i=1; i<=N; i++) cin >> word[i];

        cout << "Case #" << t << ": ";
        int cnt=0;
        for (int i=1; i<=N; i++) {
            if (i>1 && word[i]>word[i-1]) {
                cout << ++cnt << " ";
            }
            else {
                cnt=1;
                cout << cnt << " ";
            }
        }
        cout << "\n";
    }
}
