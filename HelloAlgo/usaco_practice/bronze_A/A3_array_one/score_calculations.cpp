// 점수 계산 
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int pattern[N];
    for (int j=0; j<N; j++)
    {
        scanf("%d ", &pattern[j]);
    }
    int results=0, point=1;
    for (int i=0; i<N; i++)
    {
        if (pattern[i]==1)
        {
            results += point;
            point += 1;
        }
        else
        {
            point = 1;
        }
    }
    cout << results << endl;
}
