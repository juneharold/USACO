#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main()
{
    map <string, int> books;
    int N; cin >> N;
    int max=0;
    for (int i=0; i<N; i++)
    {
        string a; cin >> a;
        books[a]+=1;
        if (books.count(a)>max) max=books.count(a);
    }
    cout << max;
    vector <string> ans;
    for (auto x : books)
    {
        if (x.second==max)
        {
            ans.push_back(x.first);
        }
    }
    sort(&ans[0], &ans[ans.size()]);
    cout << ans[0];
}
