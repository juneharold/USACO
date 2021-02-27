// 창영마을 
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a;
    cin >> a;
    int x=1, y=0, z=0;
    for (int i=0; i<a.size(); i++)
    {
        if (a[i]=='A')
        {
            int t;
            t=x;
            x=y;
            y=t;
        }
        else if (a[i]=='B')
        {
            int t;
            t=y;
            y=z;
            z=t;
        }
        else
        {
            int t;
            t=x;
            x=z;
            z=t;
        }
    }
    if (x==1)
    {
        printf("1");
    }
    else if (y==1)
    {
        printf("2");
    }
    else
    {
        printf("3");
    } 
}
