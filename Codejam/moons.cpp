#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int t; cin >> t;
    for (int c=1; c<=t; c++)
    {
        int X, Y; cin >> X >> Y;
        string mural; cin >> mural;
        long long cost=0;
        char prev=' ';
        for (int i=0; i<mural.size()-1; i++)
        {
            if (mural[i]=='C' and mural[i+1]=='J') cost+=X;
            else if (mural[i]=='J' and mural[i+1]=='C') cost+=Y;
            else if (mural[i]=='?' and mural[i+1]=='C')
            {
                if (prev=='J') cost+=Y;
            }
            else if (mural[i]=='?' and mural[i+1]=='J')
            {
                if (prev=='C') cost+=X;
            }
            if (mural[i]=='J' or mural[i]=='C') prev=mural[i];
        }
        cout << "Case #" << c << ": " << cost << "\n";
    }
}

/*
4
-2 -3 CJ?CC?
4 2 CJCJ
1 3 C?J
2 5 ??J???

1
2 5 ??J??C
*/
