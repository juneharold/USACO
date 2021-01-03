// 슈퍼 마리오 
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int mush[10]={};
    for (int i=0; i<10; i++)
    {
        cin >> mush[i];
    }
    int sum=0;
    for (int i=0; i<10; i++)
    {
        if (abs(100-sum)>=abs(100-sum-mush[i]))
        {
            sum += mush[i];
        }
        else
        {
            break;
        }
        
    }
    cout << sum << endl;
}
