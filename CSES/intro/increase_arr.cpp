#include <iostream>
#include <string>
 
using namespace std;
 
 
int main()
{
    long long N; cin >> N;
    long long SUM=0; 
    long long prev;
    cin >> prev;
    for (int i=1; i<N; i++)
    {
        int a; cin >> a;
        if (a<prev)
        {
            SUM+=prev-a;
            continue;
        }
        prev=a;
    }
    cout << SUM;
}
