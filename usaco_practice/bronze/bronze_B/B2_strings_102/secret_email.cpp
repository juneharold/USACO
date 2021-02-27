// 비밀 이메일 
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string encoded;
    cin >> encoded;
    int N=encoded.size();
    if (N<=3)
    {
        cout << encoded;
    }
    else
    {
        // find R and C using double nested loop
        int R=0, C=0;
        for (int r=0; r<=N; r++) 
        {
            for (int c=0; c<=N; c++) // c<=N이 중요 ㅎㄷㄷ 
            {
                if (r<=c and r*c==N and r>=R)
                {
                    R=r;
                    C=c;
                }
            }
        }
        // now we found R and C
        // we should 
        for (int i=0; i<R; i++)
        {
            for (int j=0; j<C; j++)
            {
                cout << encoded[i+j*R];;
            }
        }
    }
}

