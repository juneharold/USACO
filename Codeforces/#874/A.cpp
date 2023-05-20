#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
using namespace std;

int main()
{
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string s; cin >> s;
        set<int> st;
        for (int i=0; i<n-1; i++) {
            char c1=s[i], c2=s[i+1];
            st.insert(c1*1000+c2);
        }
        cout << st.size() << "\n";
    }
}
