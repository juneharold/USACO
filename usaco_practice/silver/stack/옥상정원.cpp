#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n; cin >> n;
    stack <int> s;
    long long cnt=0;
    for (int i=0; i<n; i++) {
        int num; cin >> num;
        if (s.empty()) {
            s.push(num);
        }
        else if (s.top()>num) {
            cnt+=s.size();
            s.push(num);
        }
        else {
            while (!s.empty()) {
                if (s.top()>num) {
                    cnt+=s.size();
                    s.push(num);
                    break;
                }
                else if (s.size()==1 and s.top()<=num) {
                    s.pop();
                    s.push(num);
                    break;
                }
                else {
                    s.pop();
                }
            }
        }
    }
    cout << cnt;
}
