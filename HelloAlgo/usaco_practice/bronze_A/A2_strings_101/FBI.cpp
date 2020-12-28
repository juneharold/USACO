// FBI
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int num = 0;
    for(int i=0; i<5; i++)
    {
        string code;
        cin >> code;
        for (int j=0; j<code.size(); j++)
        {
            if (code[j]=='F' and code[j+1]=='B' and code[j+2]=='I')
            {
                printf("%d ", i+1);
                num += 1;
                break;
            }
        }
    }
    if (num==0)
    {
        printf("HE GOT AWAY!");
    }
}
