#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> a(n, 0), ans(n, 0);
    for (int i=0; i<n; i++) cin >> a[i];
    stack<int> s;
    for (int i=n-1; i>=0; i--) {
        while (!s.empty() && s.top()<=a[i]) s.pop();
        if (s.empty()) ans[i]=-1;
        else ans[i]=s.top();
        s.push(a[i]);
    }
    for (int i=0; i<n; i++) cout << ans[i] << ' ';
}