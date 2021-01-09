// Combination Lock
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int J1, J2, J3;
    cin >> J1 >> J2 >> J3;
    int M1, M2, M3;
    cin >> M1 >> M2 >> M3;
    int counter = 0;
    for (int a=1; a<=N; a++)
    {
        for (int b=1; b<=N; b++)
        {
            for (int c=1; c<=N; c++)
            {
                if (abs(M1-a)<=2 and abs(M2-b)<=2 and abs(M3-c)<=2)
                {
                    counter += 1;
                }
                else if (abs(J1-a)<=2 and abs(J2-b)<=2 and abs(J3-c)<=2)
                {
                    counter += 1;
                }
                else if (abs(J1-a)>=N-2 and abs(J2-b)>=N-2 and abs(J3-c)>=N-2)
                {
                    counter += 1;
                }
                else if (abs(M1-a)>=N-2 and abs(M2-b)>=N-2 and abs(M3-c)>=N-2)
                {
                    counter += 1;
                }
            }
        }
    }
    cout << counter << endl;
}
