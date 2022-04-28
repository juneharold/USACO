#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int N; cin >> N;
    for (int i=0; i<N; i++) {
        int x; cin >> x;
        string temp, s;
        getline(cin, temp);
        getline(cin, s);
        cout << s << endl;
        for (int j=0; j<s.size(); j++) {
            if (s[j]==' ') {
                cout << ' ';
                continue;
            }
            int a=s[j]-x;
            if (a<97) a+=26;
            cout << (char)a;
        }
        cout << "\n";
    }
}

/*
3
1
buubdl bu ebxo
3
ghvwurb wkh fdvwoh
6
yzkgr znk ynov
*/
