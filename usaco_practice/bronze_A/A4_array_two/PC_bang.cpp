// 피시방 알바
#include <iostream>
using namespace std;

int main()
{
    int comp[101]={};
    int N;
    cin >> N;
    int counter = 0;
    for (int i=0; i<N; i++)
    {
        int person;
        scanf("%d ", &person);
        if (comp[person]==0)
        {
            comp[person] = 1;
        }
        else
        {
            counter += 1;
        }
    }
    printf("%d", counter);
}
