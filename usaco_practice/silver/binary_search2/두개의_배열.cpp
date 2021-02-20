#include <iostream>
#include <algorithm>
using namespace std;

int A[1000005]={}, B[1000005]={}, C[1000005]={};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    for (int i=0; i<T; i++)
    {
        int n, m; cin >> n >> m;
        for (int j=0; j<n; j++) cin >> A[j];
        for (int j=0; j<m; j++) cin >> B[j];
        sort(A, A+n);
        sort(B, B+m);
        // making C arr
        for (int j=0; j<n; j++)
        {
            int LB=lower_bound(&B[0], &B[m], A[j])-&B[0];
            int UB=upper_bound(&B[0], &B[m], A[j])-&B[0];
            // edge case
            if (UB==m or LB==m) 
            {
                C[j]=B[m-1];
                continue;
            }
            if (abs(A[j]-B[UB-1]) < abs(A[j]-B[LB]))
            {
                C[j]=B[UB-1];
            }
            else if (abs(A[j]-B[UB-1]) > abs(A[j]-B[LB]))
            {
                C[j]=B[LB];
            }
            else
            {
                if (B[UB-1]<B[LB]) C[j]=B[UB-1];
                else C[j]=B[LB];
            }
            if (C[j]==0) C[j]=B[0];
        }
        long long sum=0;
        for (int j=0; j<n; j++) sum+=C[j];
        cout << sum << "\n";
    }
}

/*
1
4 3
0 9 32 30
5 9 29
*/


