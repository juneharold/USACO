#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
using namespace std;

#define ll long long
string s;
stack<ll> stk;
vector<string> S;

vector<string> tokenize (string s) {
    vector<string> ret;
    string temp="";
    for (char x: s) {
        if (x==32) {
            ret.push_back(temp);
            temp="";
        }
        else temp+=x;
    }
    ret.push_back(temp);
    return ret;
}

int main()
{
    getline(cin, s);
    string temp="";
    for (char x: s) {
        if (x==32) {
            S.push_back(temp);
            temp="";
        }
        else temp+=x;
    }
    S.push_back(temp);

    for (ll i=S.size()-1; i>=0; i--) {
        if (48<=S[i][S[i].size()-1] && S[i][S[i].size()-1]<=57) { //숫자
            ll num=0, power=1;
            for (ll j=S[i].size()-1; j>=0; j--) {
                if (S[i][j]=='-') {
                    num*=-1;
                    continue;
                }
                num+=(S[i][j]-48)*power;
                power*=10;
            }
            stk.push(num);
        }
        else {
            ll oper=S[i][0];
            ll a=stk.top();
            stk.pop();

            if (oper=='|') {
                stk.push(abs(a));
            }
            if (oper=='+') {
                ll b=stk.top();
                stk.pop();
                stk.push(a+b);
            }
            if (oper=='-') {
                ll b=stk.top();
                stk.pop();
                stk.push(a-b);
            }
            if (oper=='*') {
                ll b=stk.top();
                stk.pop();
                stk.push(a*b);
            }
            if (oper=='@') {
                ll b=stk.top();
                stk.pop();
                ll c=stk.top();
                stk.pop();
                if (a>0) stk.push(b);
                else stk.push(c);
            }
            if (oper=='>') {
                ll b=stk.top();
                stk.pop();
                ll c=stk.top();
                stk.pop();
                stk.push(max(a, max(b, c)));

            }
        }
    }
    cout << stk.top();
}
