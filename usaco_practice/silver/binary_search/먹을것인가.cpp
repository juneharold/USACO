#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int i=0; i<T; i++)
    {
        int N, M;
        cin >> N >> M;
        int A[20005]={};
        int B[20005]={};
        for (int j=0; j<N; j++) cin >> A[j];
        for (int j=0; j<M; j++) cin >> B[j];
        sort(&B[0], &B[M]);
        int sum=0;
        for (int j=0; j<N; j++)
        {
            int position=lower_bound(&B[0], &B[M], A[j]) - &B[0];
            sum+=position;
        }
        cout << sum << "\n";
    }
}
