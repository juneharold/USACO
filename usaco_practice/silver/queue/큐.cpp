#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n; cin >> n;
    queue <int> q;
    for (int i=0; i<n; i++) {
        string order; cin >> order;
        if (order=="push") {
            int x; cin >> x;
            q.push(x);
        }
        if (order=="pop") {
            if (q.size()==0) cout << -1 << "\n";
            else {
                cout << q.front() << "\n";
                q.pop();
            }
        }
        if (order=="empty") {
            cout << q.empty() << "\n";
        }
        if (order=="size") {
            cout << q.size() << "\n";
        }
        if (order=="front") {
            if (q.size()==0) cout << -1 << "\n";
            else {
                cout << q.front() << "\n";
            }
        }
        if (order=="back") {
            if (q.size()==0) cout << -1 << "\n";
            else {
                cout << q.back() << "\n";
            }
        }
    }
}
