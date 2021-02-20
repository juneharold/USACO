#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    set <string> unique;
    multiset <string> names1;
    int N; cin >> N;
    for (int i=0; i<N; i++)
    {
        string a; cin >> a;
        unique.insert(a);
        names1.insert(a);
    }
    for (int i=0; i<N-1; i++)
    {
        string a; cin >> a;
        names1.insert(a);
        if (names1.count(a)%2==0) 
        {
            names1.erase(a);
        }
    }
    auto iter=names1.begin();
    cout << *iter;
}

