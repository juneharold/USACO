#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

vector <string> ans;

int main()
{
    set <string> hear;
    int N, M; cin >> N >> M;
    for (int i=0; i<N; i++)
    {
        string a; cin >> a;
        hear.insert(a);
    }
    int counter=0;
    for (int i=0; i<M; i++)
    {
        string a; cin >> a;
        if (hear.count(a)==1)
        {
            counter++;
            ans.push_back(a);
        }
    }
    cout << counter << "\n";
    for (int i=0; i<ans.size(); i++) cout << ans[i] << "\n";
    return 0;
}
