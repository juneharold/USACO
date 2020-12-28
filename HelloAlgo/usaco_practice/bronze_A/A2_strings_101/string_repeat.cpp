// 문자열 반복
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int N;
    cin >> N;
    for (int i=0; i<N; i++)
    {
        int R;
        cin >> R;
        string S;
        cin >> S;
        for (int j=0; j<S.size(); j++)
        {
            for (int k=0; k<R; k++)
            {
                printf("%c", S[j]);
            }
        }
        printf("\n");
    }
}
