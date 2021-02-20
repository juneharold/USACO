#include <iostream>
using namespace std;

int main()
{
    int N; cin >> N;
    int minX=100, maxX=0, minY=100, maxY=0;
    for (int i=0; i<N; i++)
    {
        int x, y; cin >> x >> y;
        if (x>maxX) maxX=x;
        if (x<minX) minX=x;
        if (y>maxY) maxY=y;
        if (y<minY) minY=y;
    }
    cout << (maxX-minX+1)*2 + (maxY-minY+1)*2;
}

