#include <iostream>
#include <algorithm>
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

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    for (int i=0; i<t; i++) {
        string kiroga; cin >> kiroga;
        stack <char> stk1, stk2;
        for (int j=0; j<kiroga.size(); j++) {
            char c=kiroga[j];
            if (c=='<') {
                if (stk1.size()!=0) {
                    stk2.push(stk1.top());
                    stk1.pop();
                }
            }
            else if (c=='>') {
                if (stk2.size()!=0) {
                    stk1.push(stk2.top());
                    stk2.pop();
                }
            }
            else if (c=='-') {
                stk1.pop();
            }
            else if ((c>='a' and c<='z') or (c>='A' and c<='Z') or (c>='0' and c<='9')) {
                stk1.push(c);
            }
        }
        while (!stk1.empty()) {
            stk2.push(stk1.top());
            stk1.pop();
        }
        string answer;
        while (!stk1.empty()) {
            answer += stk1.top();
            stk1.pop();
        }
        reverse(answer.begin(), answer.end());
        cout << answer << "\n";
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
