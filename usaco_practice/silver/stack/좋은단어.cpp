#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    int n; cin >> n;
    int cnt=0;
    for (int i=0; i<n; i++) {
        stack <char> stk;
        string s; cin >> s;
        for (int j=0; j<s.size(); j++) {
            if (stk.size()>=1) {
                if (stk.top()==s[j]) stk.pop();
                else if (stk.top()!=s[j]) stk.push(s[j]);
            }
            else stk.push(s[j]);
        }
        if (stk.size()==0) cnt++;
    }
    cout << cnt;
}

/*
3
ABAB
AABB
ABBA
*/
