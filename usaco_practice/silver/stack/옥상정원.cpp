#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n; cin >> n;
    stack <int> bldg;
    long long cnt=0;
    for (int i=0; i<n; i++) {
        int num; cin >> num;
        if (bldg.empty()) {
            bldg.push(num);
        }
        else if (bldg.top()>num) {
            cnt+=bldg.size();
            bldg.push(num);
        }
        else {
            while (!bldg.empty()) {
                if (bldg.top()>num) {
                    cnt+=bldg.size();
                    bldg.push(num);
                    break;
                }
                else {
                    bldg.pop();
                    if (bldg.empty()) bldg.push(num);
                    break;
                }
            }
        }
    }
    cout << cnt;
}
