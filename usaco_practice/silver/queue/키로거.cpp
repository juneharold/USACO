#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;
/*
< 는 무시 (stack 1이 0일 경우) or delete
> 는 무시 (stack 2이 0일 경우) or 저장된 값 추가
- 는 delete
세 개의 character 외에느느 stack1에 추가.
*/

int main()
{
    int t; cin >> t;
    for (int i=0; i<t; i++) {
        string kiroga; cin >> kiroga;
        stack <char> stk1, stk2;
        for (int j=0; j<kiroga.size(); j++) {
            if (kiroga[j]=='<') {
                if (stk1.size()!=0) {
                    stk2.push(stk1.top());
                    stk1.pop();
                }
            }
            else if (kiroga[j]=='>') {
                if (stk2.size()!=0) {
                    stk1.push(stk2.top());
                    stk2.pop();
                }
            }
            else if (kiroga[j]=='-') {
                stk1.pop();
            }
            else {
                stk1.push(kiroga[j]);
            }
            for (int j=0; j<stk1.size(); j++) {
                cout << stk1.top();
                stk1.pop();
            }
            cout << "\n";
        }
        cout << "\n";
    }
}

/*
1
<<BP<A>>Cd-
2
<<BP<A>>Cd-
ThIsIsS3Cr3t
*/
