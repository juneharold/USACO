// 알파벳 거리 
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int N;
    scanf("%d", &N);
    for (int i=0; i<N; i++)
    {
        string a, b;
        cin >> a;
        cin >> b;
        printf("Distances: ");
        for (int j=0; j<a.size(); j++)
        {
            int p=a[j], q=b[j];
            if (q>=p)
            {
                printf("%d ", q-p);
            }
            else
            {
                printf("%d ", 26+q-p);
            }
        }
        printf("\n");
    }
}
