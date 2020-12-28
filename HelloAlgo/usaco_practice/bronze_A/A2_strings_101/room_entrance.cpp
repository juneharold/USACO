// 입실 관리 
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int N;
    cin >> N;
    for (int i=0; i<N; i++)
    {
        string a;
        cin >> a;
        for (int i=0; i<a.size(); i++)
        {
            int b=a[i];
            if(b>64 and b<=90)
            {
                printf("%c", b+32);
            }
            else
            {
                printf("%c", b);
            }
        }
        printf("\n");
    }
}
