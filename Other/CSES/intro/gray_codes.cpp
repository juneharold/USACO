#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<string> a{"0", "1"};
    while (n>1) {
        vector<string> x, y;
        for (auto code: a) {
            x.push_back("0"+code);
        }
        for (auto code: a) {
            y.push_back("1"+code);
        }
        reverse(y.begin(), y.end());
        a.clear();
        for (auto code: x) a.push_back(code);
        for (auto code: y) a.push_back(code);
        n--;
    }

    for (auto code: a) cout << code << "\n";
}