#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int L; cin >> L;
    string s; cin >> s;
    vector<int> fail(L, 0);
    int j=0;
    for (int i=1; i<L; i++) {
        while (j>0 && s[j]!=s[i]) j=fail[j-1];
        if (s[j]==s[i]) fail[i]=++j;
    }
    cout << L-fail[L-1];
}