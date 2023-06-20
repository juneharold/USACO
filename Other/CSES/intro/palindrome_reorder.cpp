#include <iostream>
#include <string>
#include <map>
#include <queue>
using namespace std;

int main()
{
    string s; cin >> s;
    int n=s.size();
    map<char, int> m;
    for (int i=0; i<n; i++) {
        m[s[i]]++;
    }

    int cnt_odd=0;
    for (auto x: m) {
        if (x.second%2) cnt_odd++;
    }

    if (n%2 && cnt_odd>1) {
        cout << "NO SOLUTION";
        return 0;
    }
    if (n%2==0 && cnt_odd>0) {
        cout << "NO SOLUTION";
        return 0;
    }

    deque<char> ans;
    if (cnt_odd==1) {
        for (auto x: m) {
            if (x.second%2) {
                while(x.second) {
                    ans.push_back(x.first);
                    x.second--;
                }
                break;
            }
        }
        for (auto x: m) {
            if (x.second%2) continue;
            while(x.second) {
                ans.push_back(x.first);
                ans.push_front(x.first);
                x.second-=2;
            }
        }
    }
    else {
        for (auto x: m) {
            while(x.second) {
                ans.push_back(x.first);
                ans.push_front(x.first);
                x.second-=2;
            }
        }
    }

    for (char x: ans) cout << x;
}