#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
using namespace std;
#define f first
#define s second
#define ll long long
#define MOD 1000000007

int color[200005]={};

bool check_beautiful(string brackets) {
    stack<int> st1;
    for (int i=0; i<brackets.size(); i++) {
        if (!st1.empty() && st1.top()=='(' && brackets[i]==')') st1.pop();
        else st1.push(brackets[i]);
    }
    if (st1.empty()) return true;
    
    stack<int> st2;
    for (int i=brackets.size()-1; i>=0; i--) {
        if (!st2.empty() && st2.top()=='(' && brackets[i]==')') st2.pop();
        else st2.push(brackets[i]);
    }
    if (st2.empty()) return true;
    return false;
}

int main()
{
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string b; cin >> b;
        if (check_beautiful(b)) {
            cout << 1 << "\n";
            for (int i=0; i<b.size(); i++) cout << 1 << ' ';
            cout << "\n";
            continue;
        }
        int cnt1=0, cnt2=0;
        for (int i=0; i<b.size(); i++) {
            if (b[i]=='(') cnt1++;
            else cnt2++;
        }
        if (cnt1==cnt2) {
            stack<char> st;
            for (int i=0; i<b.size(); i++) {
                if (st.empty()) {
                    if (b[i]=='(') {
                        st.push(b[i]);
                        color[i]=1;
                    }
                    else {
                        st.push(b[i]);
                        color[i]=2;
                    }
                }
                else if (!st.empty() && st.top()=='(' && b[i]==')') {
                    color[i]=1;
                    st.pop();
                }
                else if (!st.empty() && st.top()==')' && b[i]=='(') {
                    color[i]=2;
                    st.pop();
                }
                else if (!st.empty() && st.top()=='(' && b[i]=='(') {
                    color[i]=1;
                    st.push(b[i]);
                }
                else if (!st.empty() && st.top()==')' && b[i]==')') {
                    color[i]=2;
                    st.push(b[i]);
                }
            }
            cout << "2\n";
            for (int i=0; i<b.size(); i++) cout << color[i] << ' ';
            cout << "\n";
        }
        else cout << "-1\n";
    }
}

/*
1
14
((())))()(()()
*/
