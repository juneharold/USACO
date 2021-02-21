#include <iostream>
#include <set>
#include <string>
#include <vector>
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
    for (auto it=log.end(); it!=log.begin(); it--)
    {
        cout << *it << "\n";
    }  
    return 0;
}
