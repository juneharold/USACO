#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s, t;

int main()
{
    cin >> s >> t;
    string stk="";

    for (int i=0; i<s.size(); i++) {
        stk+=s[i];
        if (stk.size()>=t.size()){
            bool same=true;
            int ind=0;
            for (int j=stk.size()-t.size(); j<=stk.size()-1; j++) {
                if (stk[j]!=t[ind]) same=false;
                ind++;
            }
            if (same==true) {
                stk.erase(stk.size()-t.size());
            }
        }
    }
    cout << stk;
}
