#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

int main()
{
    string ps; cin >> ps;
    stack <char> stk;
    long long score=0;
    long long temp=1;
    /*
    (()[[]])([])
    */
    for (int i=0; i<ps.size(); i++) {
        if (ps[i]=='[') {
            temp*=3;
            stk.push(ps[i]);
        }
        else if (ps[i]=='(') {
            temp*=2;
            stk.push(ps[i]);
        }
        else if (stk.empty()) {
            cout << 0;
            exit(0);
        }
        else if (ps[i]==']' and stk.top()=='[') {
            if (ps[i-1]!=')' and ps[i-1]!=']') {
                score += temp;
                temp /=3;
                stk.pop();
            }
            else {
                temp /=3;
                stk.pop();
            }
        }
        else if (ps[i]==')' and stk.top()=='(') {
            if (ps[i-1]!=')' and ps[i-1]!=']') {
                score += temp;
                temp /=2;
                stk.pop();
            }
            else {
                temp /=2;
                stk.pop();
            }
        }
    }
    if (stk.empty()) cout << score;
    else cout << 0;
}
