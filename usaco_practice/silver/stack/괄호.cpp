#include <iostream>
#include <stack>
#include <string>
using namespace std;

/*
( 일때 스택에 더하기
) 일때 스택에 빼기
*/
int main()
{
    int t; cin >> t;
    for (int i=0; i<t; i++) {
        int cnt=0;
        int indic=1;
        string PS; cin >> PS;
        for (int j=0; j<PS.size(); j++) {
            if (PS[j]=='(') cnt++;
            else cnt--;
            if (cnt<0) {
                indic=0;
                break;
            }
        }
        if (indic==0) cout << "NO" << "\n";
        else if (cnt==0) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
    return 0;
}
