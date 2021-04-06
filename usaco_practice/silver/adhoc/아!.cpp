#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    string jae; cin >> jae;
    int j=jae.size();
    string doc; cin >> doc;
    int d=doc.size();
    if (j>=d) cout << "go";
    else cout << "no";
}
