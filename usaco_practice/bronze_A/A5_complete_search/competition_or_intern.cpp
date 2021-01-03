// 대회 or 인턴 
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int female, male, K;
    cin >> female >> male >> K;
    int remaining=female+male;
    int counter = 0;
    for (int i=0; i<300; i++)
    {
        if (remaining-3>=K and female>=2 and male>=1)
        {
            counter += 1;
            female -= 2;
            male -= 1;
            remaining=female+male;
        }
    }
    cout << counter << endl;
}
