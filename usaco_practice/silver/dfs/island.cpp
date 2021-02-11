#include <iostream>
using namespace std;

int visit[55][55]={};

int main()
{
    while (true)
    {
        int w, h;
        cin >> w >> h;
        if (w==0 and h==0) break;
        for (int i=1; i<=h; i++)
        {
            for (int j=1; j<=w; j++)
            {
                cin >> visit[i][j];
            }
        }

    }
}
