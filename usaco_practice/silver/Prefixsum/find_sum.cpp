#include <iostream>
#include <algorithm>
using namespace std;

int pfs[1000005]={};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    int sum=0;
    for (int i=1; i<=N; i++)
    {
        int a;
        cin >> a;
        sum += a;
        pfs[i]=sum;
    }
    int M;
    cin >> M;
    for (int i=0; i<M; i++)
    {
        int start, end;
        cin >> start >> end;
        cout << pfs[end]-pfs[start-1] << "\n";
    }
}
