#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    // this makes cin, cout faster
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    int prefixsum[100005]={};
    int sum=0;
    for (int i=1; i<=N; i++)
    {
        int a;
        cin >> a;
        sum += a;
        prefixsum[i]=sum;
    }
    // now find sum in range
    for (int i=0; i<M; i++)
    {
        int start, end;
        cin >> start >> end;
        cout << prefixsum[end]-prefixsum[start-1] << "\n";
    }
    return 0;
}
