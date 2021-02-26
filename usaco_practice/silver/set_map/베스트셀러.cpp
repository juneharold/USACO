#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    map <string, int> books;
    int N; cin >> N;
    int max=0;
    for (int i=0; i<N; i++)
    {
        string a; cin >> a;
        if (books.count(a)==0) books[a]=1;
        else books[a]++;
        if (books[a]>max) max=books[a];
    }
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
