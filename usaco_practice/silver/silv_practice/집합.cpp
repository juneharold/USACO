#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int M; cin >> M;
    long long num=0;
    for (int i=0; i<M; i++) {
        string s;
        int x;
        cin >> s;
        if (s=="add") {
            cin >> x;
            num=(num|(1<<x));
        }
        if (s=="remove") {
            cin >> x;
            num&=(~(1<<x));
        }
        if (s=="check") {
            cin >> x;
            if (num&(1<<x)) cout << "1\n";
            else cout << "0\n";
        }
        if (s=="toggle") {
            cin >> x;
            num=(num^(1<<x));
        }
        if (s=="all") {
            num=(1<<21)-1;
        }
        if (s=="empty") {
            num=0;
        }
    }
}
