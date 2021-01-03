// 거북이
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int sides[4];
    for (int i=0; i<4; i++){
        scanf("%d ", &sides[i]);
    }
    sort(sides, sides+4);
    printf("%d", sides[0]*sides[2]);
}
