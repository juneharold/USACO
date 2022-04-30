#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <map>
#include <set>
using namespace std;
#define f first
#define s second
#define ll long long
#define db double

string ans[10000];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    while (T--) {
        string tt; getline(cin, tt);
        string inpt[26], code[26];
        for (int i=0; i<26; i++) {
            getline(cin, inpt[i]);
            code[i]=inpt[i].substr(2, inpt[i].size()-2);
        }

        string s; getline(cin, s);
        for (int i=0; i<s.size(); i++) {
            if (s[i]==32) cout << "    ";
            else cout << code[s[i]-65] << "   ";
        }
        cout << "\n";

        string mes; getline(cin, mes);
        int idx=0, from=0, len=-1, i=0;
        while (idx<mes.size()) {
            if (mes[idx]!=32) {
                from=min(from, idx);
                len+=2;
                idx+=2;
            }
            else if (mes[idx]==32 && idx+2<mes.size() && mes[idx+2]!=32) {
                ans[i]=mes.substr(from, len);
                i++;
                from=1e9;
                len=-1;
                idx+=2;
            }
            else if (mes[idx]==32 && idx+2<mes.size() && mes[idx+2]==32) {
                ans[i]=mes.substr(from, len);
                i++;
                ans[i]="space";
                i++;
                from=1e9;
                len=-1;
                idx+=6;
            }
            else break;
        }
        ans[i]=mes.substr(from, len);
        i++;

        for (int j=0; j<i; j++) {
            if (ans[j]=="space") cout << " ";
            else {
                for (int k=0; k<26; k++) {
                    if (ans[j]==code[k]) {
                        cout << (char)(k+65);
                        break;
                    }
                }
            }
        }
        cout << "\n";
    }
}

/*
2
A . -
B - . . .
C - . - .
D - . .
E .
F . . - .
G - - .
H . . . .
I . .
J . - - -
K - . -
L . - . .
M - -
N - .
O - - -
P . - - .
Q - - . -
R . - .
S . . .
T -
U . . -
V . . . -
W . - -
X - . . -
Y - . - -
Z - - . .
HELLO WORLD
. -   - . . .       - . - .   - - . .       - . . -
1
A . -
B - . . .
C - . - .
D - . .
E .
F . . - .
G - - .
H . . . .
I . .
J . - - -
K - . -
L . - . .
M - -
N - .
O - - -
P . - - .
Q - - . -
R . - .
S . . .
T -
U . . -
V . . . -
W . - -
X - . . -
Y - . - -
Z - - . .
HELLO
- - . .   - . - -       . - -
*/
