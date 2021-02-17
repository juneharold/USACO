#include <iostream>
 
using namespace std;
 
int main()
{
    long long n;
    cin >> n;
    long long sum=0, SUM=0;
    for (int i=0; i<n-1; i++)
    {
        int a; cin >> a;
        sum += a;
    }
    for (int i=0; i<n; i++) SUM+=i+1;
    cout << SUM-sum; 
}
