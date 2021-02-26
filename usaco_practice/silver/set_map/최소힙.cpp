#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    multiset <int> hip;
    int N; cin >> N;
    for (int i=0; i<N; i++)
    {
        int a; cin >> a;
        if (a==0)
        {
            if (hip.size()==0)
            {
                cout << 0 << "\n";
                continue;
            }
            auto it=hip.begin();
            cout << *it << "\n";
            hip.erase(hip.find(*it));
        }
        else
        {
            hip.insert(a);
        }
    }
}

