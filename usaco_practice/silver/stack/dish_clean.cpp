// 스택 3개 만들기.
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n; cin >> n;
    stack <int> pile1; //not cleaned
    stack <int> pile2; // cleaned
    stack <int> pile3; // cleaned and dried
    for (int i=n; i>=1; i--) pile1.push(i);
    while (true) {
        int c, d; cin >> c >> d;
        if (c==1) {
            for (int j=0; j<d; j++) {
                pile2.push(pile1.top());
                pile1.pop();
            }
        }
        else {
            for (int j=0; j<d; j++) {
                pile3.push(pile2.top());
                pile2.pop();
            }
        }
        if (pile3.size()==n) break;
    }
    for (int i=0; i<n; i++) {
        cout << pile3.top() << "\n";
        pile3.pop();
    }
    return 0;
}
