#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n; cin >> n;
    char prev='E';
    int counter=0;
    for (int i=0; i<n; i++)
    {
        char cur; cin >> cur;
        if (prev=='E' and cur=='W') counter++;
        prev=cur;
    }
    cout << counter;
}
