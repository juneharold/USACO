#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

stack<char> st;
string s, bomb;

bool check() { // return n letters from the top
    vector<char> temp;
    string ret="";
    for (int i=0; i<bomb.size(); i++) {
        ret+=st.top();
        temp.push_back(st.top());
        st.pop();
    }
    reverse(ret.begin(), ret.end());
    if (ret==bomb) return true;
    else {
        for (int i=bomb.size()-1; i>=0; i--) st.push(temp[i]);
        return false;
    }
}

int main()
{
    cin >> s >> bomb;
    for (int i=0; i<s.size(); i++) {
        st.push(s[i]);
        while (st.size()>=bomb.size() && check()) {}
    }

    string ans="";
    while (!st.empty()) {
        ans+=st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    if (ans=="") cout << "FRULA";
    else cout << ans;
}
/*
abaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaa
abaaaaaa
*/