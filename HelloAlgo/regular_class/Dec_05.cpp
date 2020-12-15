/*
# include <iostream>
# include <string>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int c = 0;
    int cc = 0;
    for (int i=0; i<str.size(); i++)
    {
        if (str[i]=='c' or str[i]=='C')
        {
            c += 1;
        }
        if ((str[i]=='c' or str[i]=='C')and (str[i+1]=='C' or str[i+1]=='c'))
        {
            cc += 1;
        }
    }
    printf("%d\n", c);
    printf("%d", cc);
}
*/

# include <iostream>
# include <string>
using namespace std;

int main()
{
    string plates;
    cin >> plates;
    int height = 0;
    for (int i=0; i<plates.size(); i++)
    {
        if (i==0)
        {
            height += 10;
        }
        else if (plates[i]!=plates[i-1])
        {
            height += 10;
        }
        else
        {
            height += 5;
        }
    }
    printf("%d", height);
}

