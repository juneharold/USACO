#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    set <string> log;
    int N; cin >> N;
    for (int i=0; i<N; i++)
    {
        string a, b; cin >> a >> b;
        if (log.count(a)==0 and b=="enter")
        {
            log.insert(a);
        }
        else if (log.count(a)==1 and b=="leave")
        {
            log.erase(a);
        }
    }
    vector <string> ans;
    for (auto it=log.begin(); it!=log.end(); it++)
    {
        ans.push_back(*it);
    }  
    sort(&ans[0], &ans[ans.size()]);
    for (int i=ans.size()-1; i>=0; i--)
    {
        cout << ans[i] << "\n";
    }
    return 0;
}
