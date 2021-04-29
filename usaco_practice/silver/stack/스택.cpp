#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    stack <int> s;
    int n; cin >> n;
    for (int i=0; i<n; i++) {
        string order; cin >> order;
        if (order=="push") {
            int x; cin >> x;
            s.push(x);
        }
        if (order=="pop") {
            if (s.size()==0) cout << -1 << "\n";
            else {
                cout << s.top() << "\n";
                s.pop();
            }
        }
        if (order=="empty") {
            cout << s.empty() << "\n";
        }
        if (order=="size") {
            cout << s.size() << "\n";
        }
        if (order=="top") {
            if (s.size()==0) cout << -1 << "\n";
            else cout << s.top() << "\n";
        }
    }
    return 0;
}
