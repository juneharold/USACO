#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

vector <int> want; //만들어야하는 수열
vector <int> num; //남은 숫자
stack <int> stk; // 스택
vector <int> ans; // +, - 를 1과 0으로 표시

int main()
{
    int n; cin >> n;
    for (int i=0; i<n; i++) {
        int a; cin >> a;
        want.push_back(a);
    }
    for (int i=1; i<=n; i++)  num.push_back(i);
    int ind=0;
    for (int i=0; i<n; i++) {
        int a=want[i];
        if (!stk.empty() and stk.top()==a) {
            ans.push_back(0);
            stk.pop();
        }
        else if (num[ind]>a or (ind==n and stk.top()!=a)) {
            cout << "NO";
            exit(0);
        }
        else if (num[ind]<=a) {
            for (int j=ind; j<n; j++) {
                ind++;
                if (num[j]==a) {
                    ans.push_back(1);
                    ans.push_back(0);
                    break;
                }
                else {
                    stk.push(num[j]);
                    ans.push_back(1);
                }
            }
        }
        /*
        a가 stk에 있는지, num에 있는지..
        1) num의 x번째에 있으묜, x번 만큼 +, 그리고 한번 -
        2) 만약 stk에 첫번째에 있지 않으면--> NO,
        */
    }
    for (int i=0; i<ans.size(); i++) {
        if (ans[i]==1) cout << "+" << "\n";
        else cout << "-" << "\n";
    }
}
