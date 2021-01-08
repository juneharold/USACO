// 크로스워드 만들기
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string A, B; //A는 가로, B는 세로 
    cin >> A >> B;
    int indexA=-1, indexB=-1;
    for (int a=0; a<A.size(); a++)
    {
        for (int b=0; b<B.size(); b++)
        {
            if (A[a]==B[b])
            {
                indexA=a;
                indexB=b;
                break;
            }
        }
        if (indexA==a)
        {
            break;
        }
    }
    // we found the index of A and B...
    int N=A.size(), M=B.size();
    for (int i=0; i<M; i++)
    {
        if (i==indexB)
        {
            cout << A << endl;
            continue;
        }
        for (int j=0; j<N; j++)
        {
            if (j==indexA && j==N-1)
            {
                cout << B[i] << endl;
            }
            else if (j==indexA)
            {
                cout << B[i];
            }
            else if (j==N-1)
            {
                cout << "." << endl;
            }
            else
            {
                cout << ".";
            }
        }
    }
}
