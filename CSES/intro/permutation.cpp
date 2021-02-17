#include <iostream>
#include <string>
 
using namespace std;
 
int main()
{
    int N; cin >> N;
    if (N==1)
    {
        cout << 1; 
        return 0;
    }
    if (N==2 or N==3) 
    {
        cout << "NO SOLUTION"; 
        return 0;
    }
    if (N==4) 
    {
        cout << "3 1 4 2"; 
        return 0;
    }
    if (N%2==0)
    {
        for (int i=N; i>=2; i-=2) cout << i << " ";
        for (int i=N-1; i>=1; i-=2) cout << i << " ";
    }
    else
    {
        for (int i=N-1; i>=2; i-=2) cout << i << " ";
        for (int i=N; i>=1; i-=2) cout << i << " ";
    }
}
