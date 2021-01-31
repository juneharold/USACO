#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int i=0; i<T; i++)
    {
        int arr[1005]={};
        int N;
        cin >> N;
        int sum=0;
        for (int j=1; j<=N; j++)
        {
            int a;
            cin >> a;
            sum+=a;
            arr[j]=sum;
        }
        int MAX=0;
        for (int j=1; j<=N; j++)
        {
            for (int k=1; k<=j; k++)
            {
                if (j==1 and k==1)
                {
                    MAX=arr[j];
                }
                if (arr[j]-arr[k-1]>MAX)
                {
                    MAX=arr[j]-arr[k-1];
                }
            }
        }
        cout << MAX << "\n";
    }
}

/*
2
5
1 2 3 4 5
6 
-1 -1 -1 -2 0 -5
*/
